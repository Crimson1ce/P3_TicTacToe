/* 
 * File:   MediumComputerPlayer.cpp
 * Author: Josue_Fernandez
 */

#include "MediumComputerPlayer.h"
#include "DumbComputerPlayer.h"

#include <string>
using std::string;

MediumComputerPlayer::MediumComputerPlayer(char player, char opponent)
: DumbComputerPlayer(player, opponent) {
    name = "Medium_Computer";
    this->typeOfPlayer = 1;
}

MediumComputerPlayer::~MediumComputerPlayer() {
}

int MediumComputerPlayer::move(string board) {
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

int MediumComputerPlayer::defend_attack(string board, char player) {
    int ret = DumbComputerPlayer::defend_attack(board, player);

    if(ret != 0){
        return ret;
    }
    
    //Validated winning positions
    int winning[2][3] = {
        {1, 5, 9},
        {3, 5, 7}
    };
    for (int i = 0; i < 2; i++) {
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
