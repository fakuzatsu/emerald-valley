#ifndef GUARD_RTC_UTIL_H
#define GUARD_RTC_UTIL_H

#include "global.h"
#include "siirtc.h"
#include "config/overworld.h"
#include "constants/rtc.h"

#define TIME_MIDNIGHT_FLAG      (1 << 0)
#define TIME_EARLY_MORNING_FLAG (1 << 1)
#define TIME_MORNING_FLAG       (1 << 2)
#define TIME_LATE_MORNING_FLAG  (1 << 3)
#define TIME_MIDDAY_FLAG        (1 << 4)
#define TIME_AFTERNOON_FLAG     (1 << 5)
#define TIME_EVENING_FLAG       (1 << 6)
#define TIME_NIGHT_FLAG         (1 << 7)

extern const u8 gSeasonalTimeOfDay[SEASONS_COUNT][TIMES_OF_DAY_COUNT];

extern struct Time gLocalTime;
extern const s32 sNumDaysInMonths[MONTH_COUNT];

void RtcDisableInterrupts(void);
void RtcRestoreInterrupts(void);
u32 ConvertBcdToBinary(u8 bcd);
bool8 IsLeapYear(u32 year);
u16 ConvertDateToDayCount(u8 year, u8 month, u8 day);
u16 RtcGetDayCount(struct SiiRtcInfo *rtc);
void RtcInit(void);
u16 RtcGetErrorStatus(void);
void RtcGetInfo(struct SiiRtcInfo *rtc);
void RtcGetDateTime(struct SiiRtcInfo *rtc);
void RtcGetStatus(struct SiiRtcInfo *rtc);
void RtcGetRawInfo(struct SiiRtcInfo *rtc);
u16 RtcCheckInfo(struct SiiRtcInfo *rtc);
void RtcReset(void);
void FormatDecimalTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexRtcTime(u8 *dest);
void FormatDecimalDate(u8 *dest, s32 year, s32 month, s32 day);
void FormatHexDate(u8 *dest, s32 year, s32 month, s32 day);
void RtcCalcTimeDifference(struct SiiRtcInfo *rtc, struct Time *result, struct Time *t);
void RtcCalcLocalTime(void);
bool8 IsBetweenHours(s32 hours, s32 begin, s32 end);
enum TimeOfDay GetTimeBracketBySeason(enum Seasons season, s32 hours);
enum TimeOfDay GetTimeOfDay(enum TimeOfDayMode mode);
enum TimeOfDay GetTimeOfDayForDex(void);
void RtcInitLocalTimeOffset(s32 hour, s32 minute);
void RtcCalcLocalTimeOffset(s32 days, s32 hours, s32 minutes, s32 seconds);
void CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2);
u32 RtcGetMinuteCount(void);
u32 RtcGetLocalDayCount(void);
void FormatDecimalTimeWithoutSeconds(u8 *dest, s8 hour, s8 minute, bool32 is24Hour);
u16 GetFullYear(void);
enum Month GetMonth(void);
u8 GetDay(void);
enum Weekday GetDayOfWeek(void);
enum TimeOfDay GenConfigTimeOfDay(enum TimeOfDay timeOfDay);
enum TimeOfDay TryIncrementTimeOfDay(enum TimeOfDay timeOfDay);
enum TimeOfDay TryDecrementTimeOfDay(enum TimeOfDay timeOfDay);

#endif // GUARD_RTC_UTIL_H
