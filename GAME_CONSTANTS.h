#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include <string>

using std::string;


// number of games playable
constexpr int ROUND_LIMIT = 40;


// input file
//const string USER_INPUT_FILE = "test_input.txt";
const string USER_INPUT_FILE = "user_input.txt";
//const string USER_INPUT_FILE = "small_test_input.txt";

// output files
const string ROUND_OUTPUT_FILE = "round_output.txt";
const string STAT_OUTPUT_FILE = "stat_output.txt";


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


// casino
const int MAX_ROUNDS = 500;
const long int CASINO_CASH = 10'000'000;

const int MIN_PLAYERS = 2;
const long int CASINO_BROKE_CASH = MIN_PLAYERS * (RED_MAX_BET + GREEN_MAX_BET + BLACK_MAX_BET + BLUE_MAX_BET);


#endif