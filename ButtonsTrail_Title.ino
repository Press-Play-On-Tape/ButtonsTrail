#include <Arduboy2.h>

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void title_Init() {

    uint8_t level = eeprom_read_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level_Current));

    gameStats.titleSel = level > 0 ? 1 : 0;
    gameStats.level = level;
    
    gameState = GameState::Title;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void title() {


    // Handle player actions ..

    if (arduboy.justPressed(LEFT_BUTTON)) { 

        gameStats.titleSel = 0;

    }         

    if (arduboy.justPressed(RIGHT_BUTTON) && gameStats.level > 0) { 

        gameStats.titleSel = 1;

    }         

    if (arduboy.justPressed(A_BUTTON)) { 

        if (gameStats.titleSel == 0) { 
            gameStats.level = 0;
            gameStats.instruction = 0;
            gameState = GameState::Instructions_Init;
        }
        else {
            gameState = GameState::Game_Init;
        }

        eeprom_update_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level_Current), gameStats.level);

    }         


    // Render page ..

    Sprites::drawOverwrite(9, 9, Images::Title, 0);
    Sprites::drawOverwrite(25, 49, Images::Title_New, 0);

    if (gameStats.level > 0) {
     
        Sprites::drawOverwrite(68, 49, Images::Title_Continue, 0);

    }

    uint8_t frame = arduboy.getFrameCount(32) / 8;
    Sprites::drawSelfMasked(14 + (gameStats.titleSel * 44), 50, Images::Player, frame);

}
