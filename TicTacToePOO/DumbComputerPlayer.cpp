/* 
 * File:   DumbComputerPlayer.cpp
 * Author: Josue_Fernandez
 */

#include "DumbComputerPlayer.h"
#include "RandomComputerPlayer.h"

#include <string>
using std::string;

DumbComputerPlayer::DumbComputerPlayer(char player, char opponent)
: RandomComputerPlayer(player, opponent) {
    name = "Dumb_Computer";
    this->type = 3;
}

DumbComputerPlayer::~DumbComputerPlayer() {
}

int DumbComputerPlayer::move(string board) {
    int position = defend_attack(board, playerChar);
    if (position != 0) {
        return position;
    }

    position = defend_attack(board, opponentChar);
    if (position != 0) {
        return position;
    }

    return RandomComputerPlayer::move(board);

}

int DumbComputerPlayer::defend_attack(string board, char player) {
    //Validated winning positions
    int winning[6][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    for (int i = 0; i < 6; i++) {
        int posX = winning[i][0];
        int posY = winning[i][1];
        int posZ = winning[i][2];
        char x = board[ posX - 1 ];
        char y = board[ posY - 1 ];
        char z = board[ posZ - 1 ];

        if (x == y && x == player && z == '_') {
            return posZ;
        } else if (y == z && y == player && x == '_') {
            return posX;
        } else if (x == z && x == player && y == '_') {
            return posY;
        }
    }
    return 0;
}

void DumbComputerPlayer::prepareNewGame() {

}
