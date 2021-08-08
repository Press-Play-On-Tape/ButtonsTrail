#pragma once

namespace Images {

    const uint8_t PROGMEM Tile_Mask[] = {
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    };

    const uint8_t PROGMEM Tiles[] = { 
    7, 7,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,       // Blank
    0x7f, 0x41, 0x41, 0x41, 0x41, 0x41, 0x7f,       // Normal floor
    0x7f, 0x71, 0x79, 0x5d, 0x4f, 0x47, 0x7f,       // Solid floor #1
    0x7f, 0x47, 0x4f, 0x5d, 0x79, 0x71, 0x7f,       // Solid floor #2
    0x7f, 0x77, 0x77, 0x41, 0x77, 0x77, 0x7f,       // Double floor
    0x77, 0x6b, 0x55, 0x2a, 0x55, 0x6b, 0x77,       // Button floor #1
    0x77, 0x7f, 0x7f, 0x3e, 0x7f, 0x7f, 0x77,       // Button floor #2
    };

}