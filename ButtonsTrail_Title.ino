#include <Arduboy2.h>

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void title_Init() {

    uint8_t level = eeprom_read_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level));

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

        if (gameStats.titleSel == 0) gameStats.level = 0;
        eeprom_update_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level), gameStats.level);
        gameState = GameState::Game_Init;

    }         


    // Render page ..

    Sprites::drawOverwrite(0, 0, Images::Title, 0);

    font3x5.setCursor(20, 58);
    font3x5.print("New Game");

    if (gameStats.level > 0) {
     
        font3x5.setCursor(70, 58);
        font3x5.print("Continue");

    }
    Sprites::drawSelfMasked(14 + (gameStats.titleSel * 48), 59, Images::Pointer, 0);

}
