#ifndef GUARD_FISHING_H
#define GUARD_FISHING_H

void StartFishing(u8 rod);
void Task_Fishing(u8);
void UpdateChainFishingStreak();
u32 CalculateChainFishingShinyRolls(void);
bool32 ShouldUseFishingEnvironmentInBattle();
void AlignFishingAnimationFrames(void);

#endif // GUARD_FISHING_H