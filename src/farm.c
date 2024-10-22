#include "global.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"

void SaveFarmMap(void)
{
    u16 *farmMap;
    int width;
    int height;
    farmMap = gSaveBlock1Ptr->farmMap;
    for (y = 0; y < gBackupMapLayout.height; y++)
    {
        for (x = 0; x < gBackupMapLayout.width; x++)
            *mapView++ = sBackupMapData[width * y + x];
    }
}

static bool32 FarmMapViewIsEmpty(void)
{
    u16 i;
    u32 marker = 0;

#ifndef UBFIX
    // BUG: This loop extends past the bounds of the mapView array. Its size is only 0x100.
    for (i = 0; i < 0x200; i++)
        marker |= gSaveBlock1Ptr->farmMap[i];
#else
    // UBFIX: Only iterate over 0x100
    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->farmMap); i++)
        marker |= gSaveBlock1Ptr->farmMap[i];
#endif


    if (marker == 0)
        return TRUE;
    else
        return FALSE;
}

static bool8 SkipCopyingMetatileFromFarmMap(u16 *mapBlock, u16 mapWidth, u8 yMode)
{
    if (yMode == 0xFF)
        return FALSE;

    if (yMode == 0)
        mapBlock -= mapWidth;
    else
        mapBlock += mapWidth;

    if (IsLargeBreakableDecoration(*mapBlock & MAPGRID_METATILE_ID_MASK, yMode) == TRUE)
        return TRUE;
    return FALSE;
}

void LoadFarmMap(void)
{
    u8 yMode;
    int i, j;
    int x, y;
    u16 *farmMap;
    int width;
    farmMap = gSaveBlock1Ptr->farmMap;
    if (!FarmMapViewIsEmpty())
    {
        width = gBackupMapLayout.width;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        for (i = y; i < y + MAP_OFFSET_H; i++)
        {
            if (i == y && i != 0)
                yMode = 0;
            else if (i == y + MAP_OFFSET_H - 1 && i != gMapHeader.mapLayout->height - 1)
                yMode = 1;
            else
                yMode = 0xFF;

            for (j = x; j < x + MAP_OFFSET_W; j++)
            {
                if (!SkipCopyingMetatileFromFarmMap(&sBackupMapData[j + width * i], width, yMode))
                    sBackupMapData[j + width * i] = *farmMap;
                farmMap++;
            }
        }
        for (j = x; j < x + MAP_OFFSET_W; j++)
        {
            if (y != 0)
                FixLongGrassMetatilesWindowTop(j, y - 1);
            if (i < gMapHeader.mapLayout->height - 1)
                FixLongGrassMetatilesWindowBottom(j, y + MAP_OFFSET_H - 1);
        }
    }
}