/* 
 * File:   DumbComputerPlayer.h
 * Author: Josue_Fernandez
 */

#ifndef DUMBCOMPUTERPLAYER_H
#define DUMBCOMPUTERPLAYER_H

#include "RandomComputerPlayer.h"

#include <string>
using std::string;

class DumbComputerPlayer : public RandomComputerPlayer {
public:
    
    DumbComputerPlayer(char player, char opponent);
    
    virtual ~DumbComputerPlayer();
    
    /* Returns a random position, unless it is attacked horizontally or 
     * vertically, in which case it defends itself. */
    virtual int move(string board);
    
    virtual void prepareNewGame();

protected:
    /* Looks to defend against vertical and horizontal wins, or attack,
     * given the chance. */
    virtual int defend_attack(string board,char player);
    
};

#endif /* DUMBCOMPUTERPLAYER_H */

