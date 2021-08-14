#pragma once

namespace Constants {

    constexpr uint8_t FallingTilesCount = 5;
    constexpr uint8_t BoardWidth = 15;
    constexpr uint8_t BoardHeight = 6;
    constexpr uint8_t CellWidth = 7;
    constexpr uint8_t CellWidth_PlusBorder = 8;
    constexpr uint8_t CellHeight_PlusBorder = 6;

    constexpr uint8_t Board_XOffset = 4;
    constexpr uint8_t Board_YOffset = 15;

    constexpr uint16_t EEPROM_Char1 = 27;
    constexpr uint16_t EEPROM_Char2 = EEPROM_Char1 + 1;
    constexpr uint16_t EEPROM_Level_Current = EEPROM_Char1 + 2;
    constexpr uint16_t EEPROM_Level_Max = EEPROM_Char1 + 3;
    constexpr uint16_t EEPROM_Level_Rating = EEPROM_Char1 + 4;
    constexpr uint16_t EEPROM_Tile_Set = EEPROM_Char1 + 54;

    constexpr uint8_t ParticlesMax = 30;

}

enum class GameState : uint8_t {
    Splash_Init,
    Splash,
    Title_Init,
    Title,
    LevelSelect_Init,
    LevelSelect,
    Instructions_Init,
    Instructions,
    Game_Init,
    Game,
};

enum class Tiles : uint8_t {
    None,           // 0
    NormalFloor,    // 1
    SolidFloor1,    // 2
    SolidFloor2,    // 3
    DoubleFloor,    // 4
    Button1,        // 5
    Button2,        // 6
};

enum class Direction : uint8_t {
    Up,
    Down,
};

