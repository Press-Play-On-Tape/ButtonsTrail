#pragma once

namespace Constants {

    constexpr uint8_t FallingTilesCount = 5;
    constexpr uint8_t BoardWidth = 13;
    constexpr uint8_t BoardHeight = 6;
    constexpr uint8_t CellWidth = 7;
    constexpr uint8_t CellWidth_PlusBorder = 9;

    constexpr uint8_t Board_XOffset = 6;
    constexpr uint8_t Board_YOffset = 9;

    constexpr uint16_t EEPROM_Char1 = 28;
    constexpr uint16_t EEPROM_Char2 = 29;
    constexpr uint16_t EEPROM_Level = 30;

}

enum class GameState : uint8_t {
    Splash_Init,
    Splash,
    Title_Init,
    Title,
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
