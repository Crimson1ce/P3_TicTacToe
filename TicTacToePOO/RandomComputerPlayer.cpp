/* 
 * File:   RandomComputerPlayer.cpp
 * Author: Josue_Fernandez
 * 
 */

#include <cstdlib>
#include <ctime>

#include "RandomComputerPlayer.h"
#include "Player.h"

#include <string>
using std::string;

/* Constructor
 */
RandomComputerPlayer::RandomComputerPlayer(char player, char opponent)
: Player("Random_Computer", player, opponent) {
    srand(time(0));
    this->typeOfPlayer = 2;
}

/* Deconstructor
 */
RandomComputerPlayer::~RandomComputerPlayer() {
}

/* Returns a random available position
 */
int RandomComputerPlayer::move(string board) {
    while (true) {
        int ret = 1 + (rand() % 9);
        if (isAvailable(board, ret)) {
            return ret;
        }
    }
}