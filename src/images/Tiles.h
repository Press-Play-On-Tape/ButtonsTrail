#pragma once

namespace Images {

    const uint8_t PROGMEM Tile_Mask[] = {
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    };

    const uint8_t PROGMEM Tiles[] = { 
    7, 7,

    // Set 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,       // Blank
    0x5f, 0x5b, 0x55, 0x5b, 0x55, 0x5b, 0x5f,       // Normal floor
    0x5f, 0x59, 0x53, 0x55, 0x59, 0x53, 0x5f,       // Solid floor #1
    0x5f, 0x53, 0x59, 0x55, 0x53, 0x59, 0x5f,       // Solid floor #2
    0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,       // Double floor
    0x5f, 0x51, 0x51, 0x51, 0x51, 0x51, 0x5f,       // Button floor #1
    0x5f, 0x51, 0x55, 0x55, 0x55, 0x51, 0x5f,       // Button floor #2

    // Set 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,       // Blank
    0x5f, 0x5b, 0x55, 0x5b, 0x55, 0x5b, 0x5f,       // Normal floor
    0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,       // Solid floor #1
    0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f,       // Solid floor #2
    0x5f, 0x5f, 0x5b, 0x51, 0x5b, 0x5f, 0x5f,       // Double floor
    0x5f, 0x51, 0x51, 0x51, 0x51, 0x51, 0x5f,       // Button floor #1
    0x5f, 0x51, 0x55, 0x55, 0x55, 0x51, 0x5f,       // Button floor #2

    };

    const uint8_t PROGMEM Tile_Large[] = {
    14, 14,


    // Set 1

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0xff, 0xff, 0xcf, 0xcf, 0x33, 0x33, 0xcf, 0xcf, 0x33, 0x33, 0xcf, 0xcf, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0xc3, 0xc3, 0x0f, 0x0f, 0x33, 0x33, 0xc3, 0xc3, 0x0f, 0x0f, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0x0f, 0x0f, 0xc3, 0xc3, 0x33, 0x33, 0x0f, 0x0f, 0xc3, 0xc3, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,

    0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0x03, 0x03, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x03, 0x03, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 


    // Set 2

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0xff, 0xff, 0xcf, 0xcf, 0x33, 0x33, 0xcf, 0xcf, 0x33, 0x33, 0xcf, 0xcf, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0xff, 0xff, 0xcf, 0xcf, 0x03, 0x03, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    0xff, 0xff, 0x03, 0x03, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x03, 0x03, 0xff, 0xff, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 

    };

}
