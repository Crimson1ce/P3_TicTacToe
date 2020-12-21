/* 
 * File:   HumanPlayer.cpp
 * Author: IT
 * 
 * Created on 30 de noviembre de 2020, 08:33 PM
 */

#include "HumanPlayer.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/* Constructor
 */
HumanPlayer::HumanPlayer(string name, char player, char opponent) : Player(name, player, opponent) {
    this->type = 1;
}

/* Destructor
 */
HumanPlayer::~HumanPlayer() {
}

/* Receives from the user a position to play on the board.
 */
int HumanPlayer::move(string board) {
    int position;
    
    cin >> position;
    
    return position;
}

