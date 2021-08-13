#pragma once

#include "../utils/Utils.h"

struct GameStats {

    public: 

        GameStats() { };

        uint8_t level = 0;
        uint8_t maxLevel = 0;
        
        uint8_t titleSel = 0;
        int16_t xOffset = 0;
        uint8_t yOffset = 0;
        uint16_t moves = 0;
        uint8_t minimumMoves = 0;
        uint8_t instruction = 0;
        uint8_t start = 0;
        uint8_t exit = 0;
        bool endOfGame = false;

        void reset() {

            uint8_t level = eeprom_read_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level_Current));

            this->titleSel = level > 0 ? 1 : 0;

        }

};


struct LevelSelectVars {

    public: 

        LevelSelectVars() { };

        uint8_t cursor = 0;
        uint8_t cursorFlashTop = 0;
        uint8_t cursorFlashBottom = 0;
        uint8_t topRow = 0;

};