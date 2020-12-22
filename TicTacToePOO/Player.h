/* 
 * File:   Player.h
 * Author: Josue_Fernandez
 *
 */

#include <string>

using std::string;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    /* COnstructor
     */
    Player(string name, char player, char opponent);
    
    /* Deconstructor
     */
    virtual ~Player();
    
    /* Returns the character the player is playing with
     */
    char getPlayerChar();
    
    /* Returns the character the opponent is playing with
     */
    char getOpponentChar();
    
    /* Sets the character the player is playing with
     */
    void setPlayerChar(char player);
    
    /* Sets the character the opponent is playing with
     */
    void setOpponentChar(char opponent);
    
    /* Returns the player name
     */
    string getName();
    
    /* Sets the player name
     */
    void setName(string name);
    
    /* Returns the player score
     */
    int getScore();
    
    /* Sets the player score
     */
    void setScore(int score);
    
    /* Pure virtual function move that all players have
     */
    virtual int move(string board)=0;
    
    /* Returns the number of available spaces on the board
     */
    int numAvailablePositions(string board);
    
    /* Checks if the specified position is available.
     */
    bool isAvailable(string board, int position);
    
    /* Getter of the player type */
    int getType();
    
    /* Prepares the attributes of the player for a new game */
    virtual void prepareNewGame();
    
protected:
    //Name of the player
    string name;
    //Score of the player
    int score;
    //Character the player is playing with
    char playerChar;
    //Character the opponent is playing with
    char opponentChar;
    //Type of player
    int type;

};

#endif /* PLAYER_H */

