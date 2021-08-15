#pragma once

namespace Images {

    const uint8_t PROGMEM Tile_Mask[] = {
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    };

    const uint8_t PROGMEM Tile_Zoom_Mask[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
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

    const uint8_t PROGMEM Tiles_Zoom[] = {
    11, 11,


    // Set 1

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0xff, 0xff, 0xd7, 0xeb, 0xd7, 0xeb, 0xd7, 0xeb, 0xd7, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xe3, 0xc7, 0xcf, 0xdb, 0xf3, 0xe3, 0xc7, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   

    0xff, 0xff, 0xc7, 0xe3, 0xf3, 0xdb, 0xcf, 0xc7, 0xe3, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xc3, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xc3, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 


    // Set 2

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0xff, 0xff, 0xd7, 0xeb, 0xd7, 0xeb, 0xd7, 0xeb, 0xd7, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xe7, 0xe7, 0x81, 0x81, 0x81, 0xe7, 0xe7, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    0xff, 0xff, 0xc3, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xc3, 0xff, 0xff, 
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 

    };

}
