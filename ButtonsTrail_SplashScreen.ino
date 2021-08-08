#include "src/utils/Arduboy2Ext.h"

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void splashScreen_Init() {

    gameState = GameState::Splash;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void splashScreen() { 

    auto justPressed = arduboy.justPressedButtons();

    if (justPressed > 0) {
        
        gameState = GameState::Title_Init; 

    }


    Sprites::drawOverwrite(32, 17, Images::PPOT, 0);

    uint8_t y = 17; 
    
    switch (arduboy.getFrameCount(48)) {

        case 12 ... 23:
            y = 30; 
            /*-fallthrough*/
        case 0 ... 11:
            Sprites::drawOverwrite(91, 25, Images::PPOT_Arrow, 0); 
            break;

        case 24 ... 35:
            y = 31; 
            break;

        default: 
            y = 32; 
            break;

    }

    arduboy.drawPixel(52, y, WHITE); 

    if (y % 2 == 0) { 
        Sprites::drawOverwrite(45, 28, Images::PPOT_Spindle, 0);
    }

}
