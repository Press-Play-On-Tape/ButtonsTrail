#include <Arduboy2.h>

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void game_Init() {

    gameStats.reset();
    gameState = GameState::Game;

    gameStats.xOffset = -132;
    gameStats.exit = 0;
    gameStats.endOfGame = false;
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void game() {

    if (endOfGame() && !gameStats.endOfGame) {
        gameStats.endOfGame = true;

        #ifdef SOUNDS
        sound.tones(Sounds::Positive);
        #endif

    }


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

    // if (arduboy.justPressed(B_BUTTON)) gameStats.moves = 0;// SJH remove
    // if (arduboy.pressed(B_BUTTON) && arduboy.justPressed(UP_BUTTON)) { gameStats.level--; initGame(gameStats.level); }// SJH remove
    // if (arduboy.pressed(B_BUTTON) && arduboy.justPressed(DOWN_BUTTON)) { gameStats.level++; initGame(gameStats.level); }// SJH remove
    
    if (arduboy.pressed(B_BUTTON)) { // Exit

        gameStats.exit++;

        if (gameStats.exit > 32) {

            gameState = GameState::Title_Init;

        }
    }
    else {

        gameStats.exit = 0;

    }

    if (gameStats.xOffset == 0 && !player.isMoving() && !gameStats.endOfGame) {

        if (arduboy.justPressed(LEFT_BUTTON) && player.getX() > -1)                             { player.moveLeft();   gameStats.moves++;   removeTile(); } 
        else if (arduboy.justPressed(RIGHT_BUTTON) && player.getX() < Constants::BoardWidth)    { player.moveRight();  gameStats.moves++;   removeTile(); } 
        else if (arduboy.justPressed(UP_BUTTON) && player.getY() > -1)                          { player.moveUp();     gameStats.moves++;   removeTile(); } 
        else if (arduboy.justPressed(DOWN_BUTTON) && player.getY() < Constants::BoardHeight)    { player.moveDown();   gameStats.moves++;   removeTile(); } 

    }


    // Is the player on a 'blank' tile?

    if (!player.isDying() && (player.getXNew() < 0 || player.getXNew() == Constants::BoardWidth || player.getYNew() < 0 || player.getYNew() == Constants::BoardHeight || board[player.getYNew()][player.getXNew()] == static_cast<uint8_t>(Tiles::None))) {

        player.kill();
        
        if (gameStats.xOffset == 0) {

            #ifdef SOUNDS
            sound.tones(Sounds::Death);
            #endif

        }

    }
    
            
    // Render board ..

    if (!gameStats.endOfGame) renderBoard();
    renderHUD();


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

    if (gameStats.endOfGame) {

        uint8_t stars = 0;

        if (gameStats.moves < gameStats.minimumMoves + 2)           { stars = 3; }
        else if (gameStats.moves < gameStats.minimumMoves * 1.5)    { stars = 2; }
        else if (gameStats.moves < gameStats.minimumMoves * 3)      { stars = 1; }
        else                                                        { stars = 0; }

        Sprites::drawExternalMask(45, 20, (stars > 0 ? Images::Star_Filled : Images::Star_Hollow), Images::Star_Mask, 0, 0);
        Sprites::drawExternalMask(59, 20, (stars > 1 ? Images::Star_Filled : Images::Star_Hollow), Images::Star_Mask, 0, 0);
        Sprites::drawExternalMask(73, 20, (stars > 2 ? Images::Star_Filled : Images::Star_Hollow), Images::Star_Mask, 0, 0);

        if (gameStats.level + 1 == Puzzles::Count) {

            Sprites::drawOverwrite(37, 32, Images::EndOfGame, 0);
            updateAndRenderParticles();

            if (arduboy.isFrameCount(32)) launchParticles(random(32, 97), random(16, 48));

        }
        else {

            Sprites::drawOverwrite(22, 32, Images::Congratulations, 0);
            eeprom_update_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level_Current), gameStats.level + 1);
            if (gameStats.maxLevel < gameStats.level + 1) {
                eeprom_update_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level_Max), gameStats.level + 1);
            }

        }

        eeprom_update_byte(reinterpret_cast<uint8_t *>(Constants::EEPROM_Level_Rating + gameStats.level), stars);

        if (arduboy.justPressed(A_BUTTON)) {

            if (gameStats.level + 1 == Puzzles::Count) {

                gameState = GameState::Title_Init;

            }
            else {

                gameStats.xOffset = 4;
                gameStats.level++;
                gameStats.moves = 0;
                gameStats.endOfGame = false;

            }

        }

    }

}

void removeTile() {

    switch (static_cast<Tiles>(board[player.getY()][player.getX()])) {

        case Tiles::NormalFloor:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_01);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::None);
           
            for (FallingTile &fallingTile : fallingTiles) {

                if (!fallingTile.isActive()) {

                    fallingTile.init(player.getX(), player.getY());
                    break;

                }

            }

            break;

        case Tiles::DoubleFloor:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_02);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::NormalFloor);
            break;

        case Tiles::Button1:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_03);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button2);
            break;

        case Tiles::Button2:

            #ifdef SOUNDS
            sound.tones(Sounds::Tone_03);
            #endif

            board[player.getY()][player.getX()] = static_cast<uint8_t>(Tiles::Button1);
            break;

        default: 
            #ifdef SOUNDS
            sound.tones(Sounds::Tone_01);
            #endif
            break;

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


    // Minimium number of moves

    gameStats.minimumMoves = pgm_read_byte(&puzzle[idx++]);

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
    gameStats.endOfGame = false;


    // If last row is all zeroes we can render the board down 6px ..

    uint8_t count = 0;

    for (uint16_t x = 0; x < Constants::BoardWidth; x++){

        count = count + (board[Constants::BoardHeight - 1][x] == 0 ? 1 : 0);

    }

    gameStats.yOffset = count == Constants::BoardWidth ? 6 : 0;

}

void renderBoard() {

    for (uint16_t y = 0; y < Constants::BoardHeight; y++){

        for (uint16_t x = 0; x < Constants::BoardWidth; x++){

            if (board[y][x] > static_cast<uint8_t>(Tiles::None)) {
                Sprites::drawExternalMask(Constants::Board_XOffset + gameStats.xOffset + (x * Constants::CellWidth_PlusBorder), 
                                        Constants::Board_YOffset + (y * Constants::CellHeight_PlusBorder) + gameStats.yOffset, 
                                        Images::Tiles, Images::Tile_Mask, board[y][x] + (gameStats.tileSet * 7), 0);
            }

        }

    }


    // Render falling tiles ..
                
    for (FallingTile &fallingTile : fallingTiles) {

        if (fallingTile.isActive()) {

            Sprites::drawExternalMask(Constants::Board_XOffset + (fallingTile.getX() * Constants::CellWidth_PlusBorder), 
                                      Constants::Board_YOffset + (fallingTile.getY() * Constants::CellHeight_PlusBorder) + fallingTile.getYOffset() + gameStats.yOffset, 
                                      Images::Player_Dying, Images::Player_Mask, 0, 0);
            
        }

    }


    // Render arrows .. (if defined)

    for (Arrow &arrow : arrows) {

        if (arrow.getX() > 0 || arrow.getY() > 0) {
    
            Sprites::drawExternalMask(Constants::Board_XOffset + gameStats.xOffset + (arrow.getX() * Constants::CellWidth_PlusBorder) - 1, 
                                    Constants::Board_YOffset + (arrow.getY() * Constants::CellHeight_PlusBorder) + arrow.getYOffset() + gameStats.yOffset - 1, 
                                    Images::Arrow, Images::Arrow_Mask, 0, 0);


        }

    }


    // Render player ..

    if (gameStats.xOffset == 0) {

        uint8_t frame = arduboy.getFrameCount(32) / 8;

        if (player.isDying()) {

            if (player.isMoving()) {

                Sprites::drawExternalMask(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder) + player.getXOffset(), 
                                          Constants::Board_YOffset + (player.getY() * Constants::CellHeight_PlusBorder) + player.getYOffset() + gameStats.yOffset - 1, 
                                          Images::Player, Images::Player_Mask, frame, frame);

            }
            else {

                Sprites::drawExternalMask(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder), 
                                          Constants::Board_YOffset + (player.getY() * Constants::CellHeight_PlusBorder) + player.getYDyingOffset_1() + gameStats.yOffset - 1, 
                                          Images::Player_Dying, Images::Player_Mask, frame, frame);

            }
    
            Sprites::drawExternalMask(Constants::Board_XOffset + (player.getXOld() * Constants::CellWidth_PlusBorder), 
                                      Constants::Board_YOffset + (player.getYOld() * Constants::CellHeight_PlusBorder) + player.getYDyingOffset_2() + gameStats.yOffset - 1, 
                                      Images::Player_Dying, Images::Player_Mask, frame, frame);

        }
        else {

            Sprites::drawExternalMask(Constants::Board_XOffset + (player.getX() * Constants::CellWidth_PlusBorder) + player.getXOffset(), 
                                      Constants::Board_YOffset + (player.getY() * Constants::CellHeight_PlusBorder) + player.getYOffset() + gameStats.yOffset - 1, 
                                      Images::Player, Images::Player_Mask, frame, frame);

        }
        
    }

}


void renderHUD() {

    Sprites::drawOverwrite(0, 0, Images::Level, 0);

    {
        uint8_t digits[3] = {};
        uint8_t x = 45;

        extractDigits(digits, gameStats.level);

        for (uint8_t i = 0; i < 3; ++i) {

            if (digits[i] == 1) x = x - 3;

        }

        for (uint8_t i = 0; i < 3; ++i) {
            Sprites::drawOverwrite(x, 0, Images::Numbers, digits[i]);
            x = x - (digits[i] == 1 ? 5 : 8);
        }

    }


    Sprites::drawOverwrite(71, 0, Images::Moves, 0);

    {
        uint8_t digits[3] = {};
        uint8_t x = 121;

        extractDigits(digits, gameStats.moves < 999 ? gameStats.moves : 999);

        for (uint8_t i = 0; i < 3; ++i) {

            if (digits[i] == 1) x = x - 3;

        }
        
        for (uint8_t i = 0; i < 3; ++i) {
            Sprites::drawOverwrite(x, 0, Images::Numbers, digits[i]);
            x = x - (digits[i] == 1 ? 5 : 8);
        }

    }

    arduboy.drawFastHLine(0, 8, 128, WHITE);


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