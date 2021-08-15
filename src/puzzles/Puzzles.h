#pragma once

namespace Puzzles {

    // 0 Blank
    // 1 Normal floor
    // 2 Solid floor #1
    // 3 Solid floor #2
    // 4 Double floor
    // 5 Button floor #1
    // 6 Button floor #2

    constexpr uint8_t Count = 26;

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_00[] = {
        3, 5, // Starting Pos
        11, 2, 0, 0, // Arrows
        20, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 2, 3, 2, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 5, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_01[] = {
        2, 3, // Starting Pos
        7, 0, 12, 0, // Arrows
        10, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 5, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_02[] = {
        7, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        14, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 2, 6, 3, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_03[] = {
        4, 3, // Starting Pos
        0, 0, 0, 0, // Arrows
        15, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 5, 1, 6, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 0, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_04[] = {
        5, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        18, // Minimum moves
        0, 0, 0, 0, 0, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 3, 5, 2, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_05[] = {
        6, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        22, // Minimum moves
        0, 0, 0, 0, 0, 0, 5, 1, 1, 0, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 2, 0, 5, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_06[] = {
        3, 3, // Starting Pos
        0, 0, 0, 0, // Arrows
        16, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 4, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 1, 0, 5, 1, 4, 6, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_07[] = {
        3, 3, // Starting Pos
        0, 0, 0, 0, // Arrows
        27, // Minimum moves
        0, 0, 0, 0, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 6, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 1, 5, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 1, 6, 1, 1, 5, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_08[] = {
        3, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        29, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 1, 1, 6, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 0, 5, 0, 5, 0, 5, 1, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 
        0, 0, 0, 5, 1, 5, 1, 5, 1, 0, 1, 6, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_09[] = {
        7, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        35, // Minimum moves
        0, 0, 0, 5, 1, 1, 1, 0, 0, 1, 6, 5, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 4, 6, 1, 4, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 5, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 5, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_10[] = {
        5, 3, // Starting Pos
        0, 0, 0, 0, // Arrows
        33, // Minimum moves
        0, 0, 0, 1, 1, 3, 4, 6, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 0, 1, 0, 5, 0, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 5, 1, 1, 1, 0, 5, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 0, 5, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 4, 1, 1, 1, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_11[] = {
        3, 1, // Starting Pos
        0, 0, 0, 0, // Arrows
        33, // Minimum moves
        0, 0, 0, 0, 0, 6, 4, 4, 1, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 1, 1, 4, 0, 5, 0, 1, 0, 4, 0, 0, 0, 
        0, 0, 0, 0, 0, 6, 1, 1, 1, 5, 1, 6, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 0, 0, 5, 1, 1, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_12[] = {
        3, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        37, // Minimum moves
        0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 6, 4, 5, 1, 1, 1, 1, 1, 5, 1, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 1, 1, 5, 4, 1, 5, 0, 0, 
        0, 0, 0, 1, 1, 2, 1, 1, 5, 0, 4, 0, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 6, 1, 5, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_13[] = {
        7, 3, // Starting Pos
        0, 0, 0, 0, // Arrows
        48, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 5, 0, 
        0, 5, 1, 4, 6, 0, 0, 0, 0, 1, 1, 4, 0, 5, 0, 
        0, 4, 5, 0, 5, 0, 0, 0, 1, 5, 0, 1, 0, 0, 0, 
        0, 5, 0, 0, 1, 0, 0, 1, 4, 1, 1, 5, 0, 0, 0, 
        0, 0, 0, 1, 5, 4, 1, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_14[] = {
        4, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        35, // Minimum moves
        0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 4, 1, 5, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 1, 0, 1, 0, 1, 0, 0, 
        0, 0, 0, 1, 1, 5, 1, 0, 1, 1, 6, 1, 1, 0, 0, 
        0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 
        0, 0, 0, 5, 1, 1, 5, 0, 0, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 1, 1, 5, 1, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_15[] = {
        3, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        32, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 1, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 4, 5, 0, 0, 0, 
        0, 0, 0, 0, 5, 0, 1, 0, 5, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 1, 1, 6, 5, 1, 1, 1, 4, 0, 0, 0, 0, 
        0, 0, 0, 1, 0, 1, 0, 0, 6, 0, 6, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 1, 4, 1, 5, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_16[] = {
        3, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        41, // Minimum moves
        0, 0, 5, 6, 4, 1, 1, 6, 1, 6, 1, 1, 0, 0, 0, 
        0, 0, 0, 1, 5, 6, 0, 1, 5, 1, 0, 1, 1, 0, 0, 
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0, 0, 
        0, 0, 0, 5, 0, 0, 0, 0, 6, 4, 5, 0, 1, 0, 0, 
        0, 0, 0, 1, 5, 4, 4, 5, 4, 0, 1, 1, 6, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 1, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_17[] = {
        4, 4, // Starting Pos
        0, 0, 0, 0, // Arrows
        39, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 5, 0, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 4, 5, 4, 4, 1, 5, 0, 0, 
        0, 0, 0, 5, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 
        0, 0, 0, 1, 0, 4, 1, 1, 0, 0, 1, 1, 6, 0, 0, 
        0, 0, 0, 1, 1, 5, 0, 5, 0, 5, 1, 0, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 5, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_18[] = {
        3, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        29, // Minimum moves
        0, 0, 0, 0, 0, 5, 1, 0, 1, 1, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 2, 4, 5, 1, 6, 4, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 5, 1, 0, 0, 5, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_19[] = {
        10, 0, // Starting Pos
        0, 0, 0, 0, // Arrows
        30, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 4, 6, 1, 4, 0, 0, 5, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 4, 5, 1, 4, 5, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 1, 6, 0, 0, 1, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 5, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_20[] = {
        8, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        52, // Minimum moves
        0, 0, 6, 1, 1, 4, 6, 1, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 4, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 0, 0, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 5, 0, 1, 0, 0, 0, 0, 5, 4, 5, 0, 0, 
        0, 0, 5, 4, 1, 4, 1, 1, 5, 1, 4, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 5, 1, 5, 6, 5, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_21[] = {
        2, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        27, // Minimum moves
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 5, 6, 5, 1, 2, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 4, 5, 1, 1, 1, 1, 5, 6, 0, 0, 0, 
        0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 6, 1, 5, 0, 0, 
        0, 0, 0, 0, 5, 6, 6, 5, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    };


    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_22[] = {
        2, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        37, // Minimum moves
        0, 0, 0, 5, 6, 5, 0, 0, 0, 5, 6, 5, 0, 0, 0, 
        0, 0, 0, 2, 1, 1, 1, 0, 1, 3, 1, 1, 0, 0, 0, 
        0, 0, 1, 4, 0, 0, 1, 0, 1, 0, 0, 4, 1, 0, 0, 
        0, 0, 0, 1, 0, 0, 4, 1, 4, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 6, 5, 6, 1, 0, 1, 6, 5, 5, 0, 0, 0, 
        0, 0, 0, 0, 5, 1, 0, 0, 0, 1, 5, 0, 0, 0, 0, 
    };


    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_23[] = {
        6, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        41, // Minimum moves
        0, 0, 0, 5, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 5, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 5, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 5, 1, 5, 1, 5, 1, 5, 0, 0, 0, 0, 0, 
        0, 0, 0, 1, 5, 1, 5, 1, 5, 1, 0, 0, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_24[] = {
        0, 5, // Starting Pos
        0, 0, 0, 0, // Arrows
        55, // Minimum moves
        0, 0, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 1, 0, 0, 0, 6, 5, 6, 0, 5, 6, 0, 
        0, 0, 1, 0, 1, 0, 0, 0, 5, 4, 5, 0, 1, 5, 0, 
        0, 0, 1, 0, 1, 0, 0, 0, 0, 4, 0, 0, 5, 0, 0, 
        0, 5, 1, 4, 4, 0, 1, 5, 1, 4, 6, 1, 1, 0, 0, 
        1, 4, 5, 6, 1, 1, 4, 1, 5, 6, 6, 4, 0, 0, 0, 
    };

    //  0  1  2  3  4  5  6  7  8  9  0  1  2
    const byte PROGMEM Puzzle_25[] = {
        2, 2, // Starting Pos
        0, 0, 0, 0, // Arrows
        39, // Minimum moves
        0, 0, 0, 0, 5, 1, 5, 6, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 
        0, 0, 1, 1, 4, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 
        0, 0, 0, 0, 1, 0, 0, 2, 4, 4, 6, 6, 5, 0, 0, 
        0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 5, 0, 0, 0, 
        0, 0, 5, 1, 6, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 
    };

    const uint8_t* const puzzles[] PROGMEM = { 
        Puzzle_00, Puzzle_01, Puzzle_02, Puzzle_03, 
        Puzzle_04, Puzzle_05, Puzzle_06, Puzzle_07,
        Puzzle_08, Puzzle_09, Puzzle_10, Puzzle_11,
        Puzzle_12, Puzzle_13, Puzzle_14, Puzzle_15,
        Puzzle_16, Puzzle_17, Puzzle_18, Puzzle_19,
        Puzzle_20, Puzzle_21, Puzzle_22, Puzzle_23,
        Puzzle_24, Puzzle_25,
        };

}