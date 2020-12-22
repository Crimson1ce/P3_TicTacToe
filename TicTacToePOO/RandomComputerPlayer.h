/* 
 * File:   RandomComputerPlayer.h
 * Author: Josue_Fernandez
 */

#include "Player.h"

#ifndef RANDOMCOMPUTERPLAYER_H
#define RANDOMCOMPUTERPLAYER_H

#include <string>
using std::string;

class RandomComputerPlayer : public Player {
public:
    /* Constructor
     */
    RandomComputerPlayer(char player, char opponent);
    
    /* Deconstructor
     */
    virtual ~RandomComputerPlayer();
    
    /* Returns a random available position
     */
    int move(string board);
    
    virtual void prepareNewGame();


};

#endif /* RANDOMCOMPUTERPLAYER_H */

