#include "global.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"

void SaveFarmMap(void)
{
    int i, j;
    int width = gBackupMapLayout.width - (2 * MAP_OFFSET);
    int height = gBackupMapLayout.height - (2 * MAP_OFFSET);
    u16 *farmMap = gSaveBlock1Ptr->farmMap;

    // Iterate through the inner area of the map (ignoring the borders)
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // Save only the inner tiles, applying the offset
            farmMap[i * width + j] = sBackupMapData[(i + MAP_OFFSET) * gBackupMapLayout.width + (j + MAP_OFFSET)];
        }
    }
}

bool32 FarmMapViewIsEmpty(void)
{
    u16 i;
    u32 marker = 0;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->farmMap); i++)
        marker |= gSaveBlock1Ptr->farmMap[i];

    if (marker == 0)
        return TRUE;
    else
        return FALSE;
}

void LoadFarmMap(void)
{
    int i, j;
    int width = gBackupMapLayout.width - (2 * MAP_OFFSET);
    int height = gBackupMapLayout.height - (2 * MAP_OFFSET);
    u16 *farmMap = gSaveBlock1Ptr->farmMap;

    if (!FarmMapViewIsEmpty())
    {
        // Iterate through the inner area of the map
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                // Load only the inner tiles, applying the offset
                sBackupMapData[(i + MAP_OFFSET) * gBackupMapLayout.width + (j + MAP_OFFSET)] = farmMap[i * width + j];
            }
        }
    }
}