#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

// number of games playable
constexpr int ROUND_LIMIT = 40;


// input file
const std::string USER_INPUT_FILE = "test_input.txt";


// Table bet amounts
constexpr int RED_MIN_BET = 5;
constexpr int RED_MAX_BET = 45;
constexpr int RED_BET_MULTIPLE = 5;

constexpr int GREEN_MIN_BET = 50;
constexpr int GREEN_MAX_BET = 95;
constexpr int GREEN_BET_MULTIPLE = 5;

constexpr int BLACK_MIN_BET = 100;
constexpr int BLACK_MAX_BET = 490;
constexpr int BLACK_BET_MULTIPLE = 10;

constexpr int BLUE_MIN_BET = 500;
constexpr int BLUE_MAX_BET = 1000;
constexpr int BLUE_BET_MULTIPLE = 10;

#endif