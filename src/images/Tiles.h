#pragma once

namespace Images {

    const uint8_t PROGMEM Tile_Mask[] = {
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    };

    const uint8_t PROGMEM Tiles[] = { 
    7, 7,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,       // Blank
    0x5f, 0x5b, 0x55, 0x5b, 0x55, 0x5b, 0x5f,       // Normal floor
    0x5f, 0x59, 0x53, 0x55, 0x59, 0x53, 0x5f,       // Solid floor #1
    0x5f, 0x53, 0x59, 0x55, 0x53, 0x59, 0x5f,       // Solid floor #2
    0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,       // Double floor
    0x5f, 0x51, 0x51, 0x51, 0x51, 0x51, 0x5f,       // Button floor #1
    0x5f, 0x51, 0x55, 0x55, 0x55, 0x51, 0x5f,      // Button floor #2
    };

}
