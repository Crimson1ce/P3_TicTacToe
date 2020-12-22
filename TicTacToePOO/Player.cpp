/* 
 * File:   Player.cpp
 * Author: Josue_Fernandez
 * 
 */

#include "Player.h"

#include <string>
using std::string;

Player::Player(string name, char player, char opponent) : name(name), playerChar(player), opponentChar(opponent), score(0) {
}

Player::~Player() {
}

/* Returns the character the player is playing with
 */
char Player::getPlayerChar() {
    return playerChar;
}

/* Returns the character the opponent is playing with
 */
char Player::getOpponentChar() {
    return opponentChar;
}
/* Returns the player name
 */
string Player::getName() {
    return name;
}

void Player::setName(string name) {
    this->name = name;
}

/* Returns the number of available spaces on the board
 */
int Player::numAvailablePositions(string board) {
    int c = 0;
    for (int i = 0; i < board.length(); i++) {
        if (board[i] == '_') c++;
    }
    return c;
}

/* Checks if the specified position is available.
 */
bool Player::isAvailable(string board, int position) {
    if (position >= 1 && position <= 9) {
        return board[position - 1] == '_';
    }
    return false;
}

int Player::getScore() {
    return this->score;
}

void Player::setScore(int score) {
    if(score > 0) {
        this->score = score;
    }
}

int Player::getType() {
    return this->type;
}

void Player::setOpponentChar(char opponent) {
    if (opponent == '0' || opponent == 'X') {
        this->opponentChar = opponent;
    }
}

void Player::setPlayerChar(char player) {
    if (player == '0' || player == 'X') {
        this->playerChar = player;
    }
}

void Player::prepareNewGame() {

}
