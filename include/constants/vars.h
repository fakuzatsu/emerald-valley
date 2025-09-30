#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#define VARS_START 0x4000

// temporary vars
// The first 0x10 vars are temporary--they are cleared every time a map is loaded.
#define TEMP_VARS_START             0x4000

#define VAR_TEMP_0                 (TEMP_VARS_START + 0x0)
#define VAR_TEMP_1                 (TEMP_VARS_START + 0x1)
#define VAR_TEMP_2                 (TEMP_VARS_START + 0x2)
#define VAR_TEMP_3                 (TEMP_VARS_START + 0x3) // Note: Used when the player checks a TV
#define VAR_TEMP_4                 (TEMP_VARS_START + 0x4)
#define VAR_TEMP_5                 (TEMP_VARS_START + 0x5)
#define VAR_TEMP_6                 (TEMP_VARS_START + 0x6)
#define VAR_TEMP_7                 (TEMP_VARS_START + 0x7)
#define VAR_TEMP_8                 (TEMP_VARS_START + 0x8)
#define VAR_TEMP_9                 (TEMP_VARS_START + 0x9)
#define VAR_TEMP_A                 (TEMP_VARS_START + 0xA)
#define VAR_TEMP_B                 (TEMP_VARS_START + 0xB)
#define VAR_TEMP_C                 (TEMP_VARS_START + 0xC)
#define VAR_TEMP_D                 (TEMP_VARS_START + 0xD)
#define VAR_TEMP_E                 (TEMP_VARS_START + 0xE)
#define VAR_TEMP_F                 (TEMP_VARS_START + 0xF)

#define TEMP_VARS_END              VAR_TEMP_F
#define NUM_TEMP_VARS              (TEMP_VARS_END - TEMP_VARS_START + 1)

// object gfx id vars
// These 0x10 vars are used to dynamically control a map object's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetObjectEventGraphicsId().
#define VAR_OBJ_GFX_ID_0           0x4010
#define VAR_OBJ_GFX_ID_1           0x4011
#define VAR_OBJ_GFX_ID_2           0x4012
#define VAR_OBJ_GFX_ID_3           0x4013
#define VAR_OBJ_GFX_ID_4           0x4014
#define VAR_OBJ_GFX_ID_5           0x4015
#define VAR_OBJ_GFX_ID_6           0x4016
#define VAR_OBJ_GFX_ID_7           0x4017
#define VAR_OBJ_GFX_ID_8           0x4018
#define VAR_OBJ_GFX_ID_9           0x4019
#define VAR_OBJ_GFX_ID_A           0x401A
#define VAR_OBJ_GFX_ID_B           0x401B
#define VAR_OBJ_GFX_ID_C           0x401C
#define VAR_OBJ_GFX_ID_D           0x401D
#define VAR_OBJ_GFX_ID_E           0x401E
#define VAR_OBJ_GFX_ID_F           0x401F

#define OBJ_GFX_VARS_END           VAR_OBJ_GFX_ID_F
#define NUM_OBJ_GFX_VARS           (OBJ_GFX_VARS_END - OBJ_GFX_VARS_START + 1)

// general id vars
// used for general event tracking.
#define GENERAL_VARS_START         (OBJ_GFX_VARS_END + 1)

enum GeneralVars {
    VAR_RECYCLE_GOODS = GENERAL_VARS_START,
    VAR_REPEL_STEP_COUNT,
    VAR_ICE_STEP_COUNT,
    VAR_STARTER_MON, // 0=Treecko, 1=Torchic, 2=Mudkip
    VAR_MIRAGE_RND_H,
    VAR_MIRAGE_RND_L,
    VAR_SECRET_BASE_MAP,
    VAR_CYCLING_ROAD_RECORD_COLLISIONS,
    VAR_CYCLING_ROAD_RECORD_TIME_L,
    VAR_CYCLING_ROAD_RECORD_TIME_H,
    VAR_FRIENDSHIP_STEP_COUNTER,
    VAR_POISON_STEP_COUNTER,
    VAR_RESET_RTC_ENABLE,
    VAR_ENIGMA_BERRY_AVAILABLE,
    VAR_WONDER_NEWS_STEP_COUNTER,
    VAR_FRONTIER_MANIAC_FACILITY,
    VAR_FRONTIER_GAMBLER_CHALLENGE,
    VAR_FRONTIER_GAMBLER_SET_CHALLENGE,
    VAR_FRONTIER_GAMBLER_AMOUNT_BET,
    VAR_FRONTIER_GAMBLER_STATE,
    VAR_DEOXYS_ROCK_STEP_COUNT,
    VAR_DEOXYS_ROCK_LEVEL,
    VAR_PC_BOX_TO_SEND_MON,
    VAR_ABNORMAL_WEATHER_LOCATION,
    VAR_ABNORMAL_WEATHER_STEP_COUNTER,
    VAR_SHOULD_END_ABNORMAL_WEATHER,
    VAR_FARAWAY_ISLAND_STEP_COUNTER,
    VAR_REGICE_STEPS_1,
    VAR_REGICE_STEPS_2,
    VAR_REGICE_STEPS_3,
    VAR_ALTERING_CAVE_WILD_SET,
    VAR_DISTRIBUTE_EON_TICKET, // This var is read and written, but is always zero. The only way to obtain the Eon Ticket in Emerald is via Record Mixing
    VAR_DAYS,
    VAR_FANCLUB_FAN_COUNTER,
    VAR_FANCLUB_LOSE_FAN_TIMER,
    VAR_DEPT_STORE_FLOOR,
    VAR_TRICK_HOUSE_LEVEL,
    VAR_POKELOT_PRIZE_ITEM,
    VAR_NATIONAL_DEX,
    VAR_SEEDOT_SIZE_RECORD,
    VAR_ASH_GATHER_COUNT,
    VAR_BIRCH_STATE,
    VAR_CRUISE_STEP_COUNT,
    VAR_POKELOT_RND1,
    VAR_POKELOT_RND2,
    VAR_POKELOT_PRIZE_PLACE,
    VAR_UNUSED_0x404E, // Unused Var
    VAR_LOTAD_SIZE_RECORD,
    VAR_LITTLEROOT_TOWN_STATE,
    VAR_OLDALE_TOWN_STATE,
    VAR_DEWFORD_TOWN_STATE, // Unused Var
    VAR_LAVARIDGE_TOWN_STATE,
    VAR_CURRENT_SECRET_BASE, // was probably allocated for VAR_FALLARBOR_TOWN_STATE at one point
    VAR_VERDANTURF_TOWN_STATE, // Unused Var
    VAR_PACIFIDLOG_TOWN_STATE, // Unused Var
    VAR_PETALBURG_CITY_STATE,
    VAR_SLATEPORT_CITY_STATE,
    VAR_MAUVILLE_CITY_STATE, // Unused Var
    VAR_RUSTBORO_CITY_STATE,
    VAR_FORTREE_CITY_STATE, // Unused Var
    VAR_LILYCOVE_CITY_STATE, // Unused Var
    VAR_MOSSDEEP_CITY_STATE,
    VAR_SOOTOPOLIS_CITY_STATE,
    VAR_EVER_GRANDE_CITY_STATE, // Unused Var
    VAR_ROUTE101_STATE,
    VAR_ROUTE102_STATE, // Unused Var
    VAR_ROUTE103_STATE, // Unused Var
    VAR_ROUTE104_STATE,
    VAR_ROUTE105_STATE, // Unused Var
    VAR_ROUTE106_STATE, // Unused Var
    VAR_ROUTE107_STATE, // Unused Var
    VAR_ROUTE108_STATE, // Unused Var
    VAR_ROUTE109_STATE, // Unused Var
    VAR_ROUTE110_STATE,
    VAR_ROUTE111_STATE, // Unused Var
    VAR_ROUTE112_STATE, // Unused Var
    VAR_ROUTE113_STATE, // Unused Var
    VAR_ROUTE114_STATE, // Unused Var
    VAR_ROUTE115_STATE, // Unused Var
    VAR_ROUTE116_STATE,
    VAR_ROUTE117_STATE, // Unused Var
    VAR_ROUTE118_STATE,
    VAR_ROUTE119_STATE,
    VAR_ROUTE120_STATE, // Unused Var
    VAR_ROUTE121_STATE,
    VAR_ROUTE122_STATE, // Unused Var
    VAR_ROUTE123_STATE, // Unused Var
    VAR_ROUTE124_STATE, // Unused Var
    VAR_ROUTE125_STATE, // Unused Var
    VAR_ROUTE126_STATE, // Unused Var
    VAR_ROUTE127_STATE, // Unused Var
    VAR_ROUTE128_STATE,
    VAR_ROUTE129_STATE, // Unused Var
    VAR_ROUTE130_STATE, // Unused Var
    VAR_ROUTE131_STATE, // Unused Var
    VAR_ROUTE132_STATE, // Unused Var
    VAR_ROUTE133_STATE, // Unused Var
    VAR_ROUTE134_STATE, // Unused Var
    VAR_LITTLEROOT_HOUSES_STATE_MAY,
    VAR_UNUSED_0x4083, // Unused Var
    VAR_BIRCH_LAB_STATE,
    VAR_PETALBURG_GYM_STATE, // 0-1: Wally tutorial, 2-6: 0-4 badges, 7: Defeated Norman, 8: Rematch Norman
    VAR_CONTEST_HALL_STATE,
    VAR_CABLE_CLUB_STATE,
    VAR_CONTEST_TYPE,
    VAR_SECRET_BASE_INITIALIZED,
    VAR_CONTEST_PRIZE_PICKUP,
    VAR_UNUSED_0x408B, // Unused Var
    VAR_LITTLEROOT_HOUSES_STATE_BRENDAN,
    VAR_LITTLEROOT_RIVAL_STATE,
    VAR_BOARD_BRINEY_BOAT_STATE,
    VAR_DEVON_CORP_3F_STATE,
    VAR_BRINEY_HOUSE_STATE,
    VAR_UNUSED_0x4091, // Unused Var
    VAR_LITTLEROOT_INTRO_STATE,
    VAR_MAUVILLE_GYM_STATE,
    VAR_LILYCOVE_MUSEUM_2F_STATE,
    VAR_LILYCOVE_FAN_CLUB_STATE,
    VAR_BRINEY_LOCATION,
    VAR_INIT_SECRET_BASE,
    VAR_PETALBURG_WOODS_STATE,
    VAR_LILYCOVE_CONTEST_LOBBY_STATE,
    VAR_RUSTURF_TUNNEL_STATE,
    VAR_UNUSED_0x409B, // Unused Var
    VAR_ELITE_4_STATE,
    VAR_UNUSED_0x409D, // Unused Var
    VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE,
    VAR_MOSSDEEP_SPACE_CENTER_STATE,
    VAR_SLATEPORT_HARBOR_STATE,
    VAR_UNUSED_0x40A1, // Unused var
    VAR_SEAFLOOR_CAVERN_STATE,
    VAR_CABLE_CAR_STATION_STATE,
    VAR_SAFARI_ZONE_STATE,  // 0: In or out of SZ, 1: Player exiting SZ,2: Player entering SZ
    VAR_TRICK_HOUSE_BEING_WATCHED_STATE,
    VAR_TRICK_HOUSE_FOUND_TRICK_MASTER,
    VAR_TRICK_HOUSE_ENTRANCE_STATE,
    VAR_UNUSED_0x40A8, // Unused Var
    VAR_CYCLING_CHALLENGE_STATE,
    VAR_SLATEPORT_MUSEUM_1F_STATE,
    VAR_TRICK_HOUSE_PUZZLE_1_STATE,
    VAR_TRICK_HOUSE_PUZZLE_2_STATE,
    VAR_TRICK_HOUSE_PUZZLE_3_STATE,
    VAR_TRICK_HOUSE_PUZZLE_4_STATE,
    VAR_TRICK_HOUSE_PUZZLE_5_STATE,
    VAR_TRICK_HOUSE_PUZZLE_6_STATE,
    VAR_TRICK_HOUSE_PUZZLE_7_STATE,
    VAR_TRICK_HOUSE_PUZZLE_8_STATE,
    VAR_WEATHER_INSTITUTE_STATE,
    VAR_SS_TIDAL_STATE,
    VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR,
    VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, // Leftover from RS, never set
    VAR_SLATEPORT_FAN_CLUB_STATE,
    VAR_UNUSED_0x40B8, // Unused Var
    VAR_MT_PYRE_STATE,
    VAR_NEW_MAUVILLE_STATE,
    VAR_UNUSED_0x40BB, // Unused Var
    VAR_BRAVO_TRAINER_BATTLE_TOWER_ON,
    VAR_JAGGED_PASS_ASH_WEATHER,
    VAR_GLASS_WORKSHOP_STATE,
    VAR_METEOR_FALLS_STATE,
    VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE,
    VAR_TRICK_HOUSE_PRIZE_PICKUP,
    VAR_PACIFIDLOG_TM_RECEIVED_DAY,
    VAR_VICTORY_ROAD_1F_STATE,
    VAR_FOSSIL_RESURRECTION_STATE,
    VAR_WHICH_FOSSIL_REVIVED,
    VAR_STEVENS_HOUSE_STATE,
    VAR_OLDALE_RIVAL_STATE,
    VAR_JAGGED_PASS_STATE,
    VAR_SCOTT_PETALBURG_ENCOUNTER,
    VAR_SKY_PILLAR_STATE,
    VAR_MIRAGE_TOWER_STATE,
    VAR_FOSSIL_MANIAC_STATE,
    VAR_CABLE_CLUB_TUTORIAL_STATE,
    VAR_FRONTIER_BATTLE_MODE,
    VAR_FRONTIER_FACILITY,
    VAR_HAS_ENTERED_BATTLE_FRONTIER, // Var is used like a flag.
    VAR_SCOTT_STATE,
    VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE,
    VAR_DEX_UPGRADE_JOHTO_STARTER_STATE,
    VAR_SS_TIDAL_SCOTT_STATE, // Always equal to FLAG_MET_SCOTT_ON_SS_TIDAL
    VAR_ROAMER_POKEMON, // 0 = Latias,1 = Latios
    VAR_TRAINER_HILL_IS_ACTIVE,
    VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE,
    VAR_SOOTOPOLIS_WALLACE_STATE,
    VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT,
    VAR_REGISTER_BIRCH_STATE,
    VAR_UNUSED_0x40DB, // Unused Var
    VAR_UNUSED_0x40DC, // Unused Var
    VAR_GIFT_PICHU_SLOT,
    VAR_GIFT_UNUSED_1, // Var is written to, but never read
    VAR_GIFT_UNUSED_2, // Var is written to, but never read
    VAR_GIFT_UNUSED_3, // Var is written to, but never read
    VAR_GIFT_UNUSED_4, // Var is written to, but never read
    VAR_GIFT_UNUSED_5, // Var is written to, but never read
    VAR_GIFT_UNUSED_6, // Var is written to, but never read
    VAR_GIFT_UNUSED_7, // var is written to, but never read
    VAR_UNUSED_0x40E5, // Unused Var
    VAR_DAILY_SLOTS,
    VAR_DAILY_WILDS,
    VAR_DAILY_BLENDER,
    VAR_DAILY_PLANTED_BERRIES,
    VAR_DAILY_PICKED_BERRIES,
    VAR_DAILY_ROULETTE,
    VAR_SECRET_BASE_STEP_COUNTER, // Used by Secret Base TV programs
    VAR_SECRET_BASE_LAST_ITEM_USED, // Used by Secret Base TV programs
    VAR_SECRET_BASE_LOW_TV_FLAGS, // Used by Secret Base TV programs
    VAR_SECRET_BASE_HIGH_TV_FLAGS, // Used by Secret Base TV programs
    VAR_SECRET_BASE_IS_NOT_LOCAL, // Set to TRUE while in another player's secret base.
    VAR_DAILY_BP,
    VAR_WALLY_CALL_STEP_COUNTER,
    VAR_SCOTT_FORTREE_CALL_STEP_COUNTER,
    VAR_ROXANNE_CALL_STEP_COUNTER,
    VAR_SCOTT_BF_CALL_STEP_COUNTER,
    VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER,
    VAR_UNUSED_0x40F7, // Unused Var
    VAR_UNUSED_0x40F8, // Unused Var
    VAR_UNUSED_0x40F9, // Unused Var
    VAR_UNUSED_0x40FA, // Unused Var
    VAR_UNUSED_0x40FB, // Unused Var
    VAR_UNUSED_0x40FC, // Unused Var
    VAR_UNUSED_0x40FD, // Unused Var
    VAR_UNUSED_0x40FE, // Unused Var
    VAR_UNUSED_0x40FF, // Unused Var
};

#define GENERAL_VARS_END              VAR_UNUSED_0x40FF
#define NUM_GENERAL_VARS              (GENERAL_VARS_END - GENERAL_VARS_START + 1)

// total regular vars
#define VARS_END                      GENERAL_VARS_END
#define VARS_COUNT                    (VARS_END - VARS_START + 1)

// special vars
// They are commonly used as parameters to commands, or return values from commands.
#define SPECIAL_VARS_START            0x8000

#define VAR_0x8000                    SPECIAL_VARS_START
#define VAR_0x8001                    0x8001
#define VAR_0x8002                    0x8002
#define VAR_0x8003                    0x8003
#define VAR_0x8004                    0x8004
#define VAR_0x8005                    0x8005
#define VAR_0x8006                    0x8006
#define VAR_0x8007                    0x8007
#define VAR_0x8008                    0x8008
#define VAR_0x8009                    0x8009
#define VAR_0x800A                    0x800A
#define VAR_0x800B                    0x800B
#define VAR_FACING                    0x800C
#define VAR_RESULT                    0x800D
#define VAR_ITEM_ID                   0x800E
#define VAR_LAST_TALKED               0x800F
#define VAR_CONTEST_RANK              0x8010
#define VAR_CONTEST_CATEGORY          0x8011
#define VAR_MON_BOX_ID                0x8012
#define VAR_MON_BOX_POS               0x8013
#define VAR_UNUSED_0x8014             0x8014
#define VAR_TRAINER_BATTLE_OPPONENT_A 0x8015 // Alias of TRAINER_BATTLE_PARAM.opponentA

#define SPECIAL_VARS_END              VAR_TRAINER_BATTLE_OPPONENT_A

// If an overworld trigger uses this pseudo-variable as the trigger check,
// then the script will be run using RunScriptImmediately instead of in the
// global script context. This means it will run faster, but cannot do any
// cutscenes nor call a wait command. Used for weather effects in vanilla.
#define TRIGGER_RUN_IMMEDIATELY 0

// Temp var aliases
#define VAR_TEMP_CHALLENGE_STATUS          VAR_TEMP_0
#define VAR_TEMP_MIXED_RECORDS             VAR_TEMP_0
#define VAR_TEMP_RECORD_MIX_GIFT_ITEM      VAR_TEMP_1
#define VAR_TEMP_PLAYING_PYRAMID_MUSIC     VAR_TEMP_E
#define VAR_TEMP_FRONTIER_TUTOR_SELECTION  VAR_TEMP_D
#define VAR_TEMP_FRONTIER_TUTOR_ID         VAR_TEMP_E
#define VAR_TEMP_TRANSFERRED_SPECIES       VAR_TEMP_1

#if TESTING
#define TESTING_VARS_START                  0x9000
#define TESTING_VAR_DIFFICULTY              (TESTING_VARS_START + 0x0)
#define TESTING_VAR_STARTING_STATUS         (TESTING_VARS_START + 0x1)
#define TESTING_VAR_STARTING_STATUS_TIMER   (TESTING_VARS_START + 0x2)
#define TESTING_VAR_UNUSED_3                (TESTING_VARS_START + 0x3)
#define TESTING_VAR_UNUSED_4                (TESTING_VARS_START + 0x4)
#define TESTING_VAR_UNUSED_5                (TESTING_VARS_START + 0x5)
#define TESTING_VAR_UNUSED_6                (TESTING_VARS_START + 0x6)
#define TESTING_VAR_UNUSED_7                (TESTING_VARS_START + 0x7)
#endif // TESTING

#endif // GUARD_CONSTANTS_VARS_H
