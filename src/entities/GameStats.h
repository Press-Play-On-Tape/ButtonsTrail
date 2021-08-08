#pragma once

#include "../utils/Utils.h"

struct GameStats {

    public: 

        GameStats() { };

        uint8_t level = 0;
        uint8_t titleSel = 0;
        int16_t xOffset = 0;
        uint8_t yOffset = 0;

        void reset() {

            uint8_t level = eeprom_read_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level));

            this->titleSel = level > 0 ? 1 : 0;

        }

};