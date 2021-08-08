#include <Arduboy2.h>

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void game_Init() {

    gameStats.reset();
    gameState = GameState::Game;
    gameStats.xOffset = 132;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void game() {


    // Update scrolling motion ..

    switch (gameStats.xOffset) {

        case -132:
            initGame(gameStats.level);
            gameStats.xOffset = gameStats.xOffset + 4;
            break;

        case -131 ... -1:
            gameStats.xOffset = gameStats.xOffset + 4;
            break;

        case 1 ... 127:
            gameStats.xOffset = gameStats.xOffset + 4;
            break;

        case 128 ... 256:
            gameStats.xOffset = -132;
            break;

        default: 
            break;

    }


    // Handle player movements ..

    if (gameStats.xOffset == 0 && !player.isMoving()) {

        if (arduboy.justPressed(LEFT_BUTTON) && player.getX() > -1)                  { player.moveLeft();   removeTile(); } 
        else if (arduboy.justPressed(RIGHT_BUTTON) && player.getX() < Constants::BoardWidth)   { player.moveRight();  removeTile(); } 
        else if (arduboy.justPressed(UP_BUTTON) && player.getY() > -1)               { player.moveUp();     removeTile(); } 
        else if (arduboy.justPressed(DOWN_BUTTON) && player.getY() < Constants::BoardHeight)   { player.moveDown();   removeTile(); } 

    }


    // Is the player on a 'blank' tile?

    if (!player.isDying() && (player.getXNew() < 0 || player.getXNew() == Constants::BoardWidth || player.getYNew() < 0 || player.getYNew() == Constants::BoardHeight || board[player.getYNew()][player.getXNew()] == 0)) {

        player.kill();

    }
    
            
    // Render board ..

    renderBoard();


    // Update the game state ..

    if (player.update() && gameStats.xOffset == 0) {
    
        gameStats.xOffset = 4;

    }

               
    for (FallingTile &fallingTile : fallingTiles) {

        if (fallingTile.isActive()) {

            fallingTile.update();
            
        }

    }

    if (arduboy.isFrameCount(6)) {
                
        for (Arrow &arrow : arrows) {

            arrow.update();

        }
        
    }

    if (endOfGame()) {

        gameStats.xOffset = 4;
        gameStats.level++;
        eeprom_update_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level), gameStats.level);

    }

}

void removeTile() {

    switch (static_cast<Tiles>(board[player.getY()][player.getX()])) {

        case Tiles::NormalFloor:

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::None);
           
            for (FallingTile &fallingTile : fallingTiles) {

                if (!fallingTile.isActive()) {

                    fallingTile.init(player.getX(), player.getY());
                    break;

                }

            }

            break;

        case Tiles::DoubleFloor:

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::NormalFloor);
            break;

        case Tiles::Button1:

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button2);
            break;

        case Tiles::Button2:

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button1);
            break;

        default: break;

    }
    
}

void initGame(uint8_t level) {

    const uint8_t *puzzle = pgm_read_ptr(&Puzzles::puzzles[level]);

    uint16_t idx = 0;


    // Retrieve player starting position ..

    uint8_t startX = pgm_read_byte(&puzzle[idx++]);
    uint8_t startY = pgm_read_byte(&puzzle[idx++]);

    player.init(startX, startY);


    // Retrieve arrows (if defined) ..

    startX = pgm_read_byte(&puzzle[idx++]);
    startY = pgm_read_byte(&puzzle[idx++]);

    arrows[0].init(startX, startY);

    startX = pgm_read_byte(&puzzle[idx++]);
    startY = pgm_read_byte(&puzzle[idx++]);

    arrows[1].init(startX, startY);

    for (uint16_t y = 0; y < Constants::BoardHeight; y++){

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            uint8_t data = pgm_read_byte(&puzzle[idx++]);

            board[y][x] = data;

        }

    }


    // Clear falling tiles ..

    for (FallingTile &fallingTile : fallingTiles) {

        fallingTile.setActive(false);

    }


    // Scroll in ..

    gameStats.xOffset = -132;


    // If last row is all zeroes we can render the board down 6px ..

    uint8_t count = 0;

    for (uint16_t x = 0; x < Constants::BoardWidth; x++){

        count = count + (board[Constants::BoardHeight - 1][x] == 0 ? 1 : 0);

    }

    gameStats.yOffset = count == Constants::BoardWidth ? 6 : 0;

}

void renderBoard() {

    // Sprites::drawOverwrite(gameStats.xOffset, 0, Images::Border_LH, 0);
    // Sprites::drawOverwrite(124 + gameStats.xOffset, 0, Images::Border_RH, 0); 

    for (uint16_t y = 0; y < Constants::BoardHeight; y++){

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            Sprites::drawExternalMask(Constants::Board_XOffset + gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                      Constants::Board_YOffset + (y * Constants::CellWidth_PlusBorder) + gameStats.yOffset, 
                                      Images::Tiles, Images::Tile_Mask, board[y][x], 0);

        }

    }


    // Render falling tiles ..
                
    for (FallingTile &fallingTile : fallingTiles) {

        if (fallingTile.isActive()) {

            Sprites::drawExternalMask(Constants::Board_XOffset + (fallingTile.getX() * Constants::CellWidth_PlusBorder), 
                                      Constants::Board_YOffset + (fallingTile.getY() * Constants::CellWidth_PlusBorder) + fallingTile.getYOffset() + gameStats.yOffset, 
                                      Images::Player_Dying, Images::Player_Mask, 0, 0);
            
        }

    }


    // Render arrows .. (if defined)

    for (Arrow &arrow : arrows) {

        if (arrow.getX() > 0 || arrow.getY() > 0) {
     
            Sprites::drawExternalMask(Constants::Board_XOffset + gameStats.xOffset + (arrow.getX() * Constants::CellWidth_PlusBorder) - 1, 
                                      Constants::Board_YOffset + (arrow.getY() * Constants::CellWidth_PlusBorder) + arrow.getYOffset() + gameStats.yOffset - 1, 
                                      Images::Arrow, Images::Arrow_Mask, 0, 0);


        }

    }


    // Render player ..

    if (gameStats.xOffset == 0) {

        if (player.isDying()) {

            if (player.isMoving()) {

                Sprites::drawExternalMask(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder) + player.getXOffset(), 
                                          Constants::Board_YOffset + (player.getY() * Constants::CellWidth_PlusBorder) + player.getYOffset() + gameStats.yOffset, 
                                          Images::Player, Images::Player_Mask, 0, 0);

            }
            else {

                Sprites::drawExternalMask(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder), 
                                          Constants::Board_YOffset + (player.getY() * Constants::CellWidth_PlusBorder) + player.getYDyingOffset_1() + gameStats.yOffset, 
                                          Images::Player_Dying, Images::Player_Mask, 0, 0);

            }
    
            Sprites::drawExternalMask(Constants::Board_XOffset + (player.getXOld() * Constants::CellWidth_PlusBorder), 
                                      Constants::Board_YOffset + (player.getYOld() * Constants::CellWidth_PlusBorder) + player.getYDyingOffset_2() + gameStats.yOffset, 
                                      Images::Player_Dying, Images::Player_Mask, 0, 0);

        }
        else {

            Sprites::drawExternalMask(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder) + player.getXOffset(), 
                                      Constants::Board_YOffset + (player.getY() * Constants::CellWidth_PlusBorder) + player.getYOffset() + gameStats.yOffset, 
                                      Images::Player, Images::Player_Mask, 0, 0);

        }
        
    }

    font3x5.setCursor(7 /* + gameStats.xOffset */, 0);
    font3x5.print("Level~:~");
    font3x5.print(gameStats.level);

}

bool endOfGame() {

    if (gameStats.xOffset == 0 && !player.isMoving()) {

        for (int16_t y = 0; y < Constants::BoardHeight; y++) {

            for (int16_t x = 0; x < Constants::BoardWidth; x++) {

                if (x == player.getX() && y == player.getY()) {

                    if (board[y][x] == static_cast<uint8_t>(Tiles::Button2)) {

                        return false;

                    }

                }
                else {

                    if (board[y][x] == static_cast<uint8_t>(Tiles::Button1)) {

                        return false;

                    }

                }

            }

        }

        return true;

    }
    else {

        return false;
    }

}