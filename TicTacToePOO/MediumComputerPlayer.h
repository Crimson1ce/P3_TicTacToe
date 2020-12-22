/* 
 * File:   MediumComputerPlayer.h
 * Author: Josue_Fernandez
 */

#ifndef MEDIUMCOMPUTERPLAYER_H
#define MEDIUMCOMPUTERPLAYER_H

#include "DumbComputerPlayer.h"

#include <string>
using std::string;

class MediumComputerPlayer : public DumbComputerPlayer {
public:

    MediumComputerPlayer(char player, char opponent);

    virtual ~MediumComputerPlayer();
    
    virtual int move(string board);
    
    virtual void prepareNewGame();


protected:
    /* Looks for attack or defend positions, depending on the character. */
    virtual int defend_attack(string board, char player);

};

#endif /* MEDIUMCOMPUTERPLAYER_H */

