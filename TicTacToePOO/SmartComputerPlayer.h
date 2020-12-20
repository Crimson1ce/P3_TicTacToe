/* 
 * File:   SmartComputerPlayer.h
 * Author: Josue_Fernandez
 */

#ifndef SMARTCOMPUTERPLAYER_H
#define SMARTCOMPUTERPLAYER_H

#include "MediumComputerPlayer.h"

#include <string>
using std::string;

class SmartComputerPlayer : public MediumComputerPlayer {
public:
    /* Constructor */
    SmartComputerPlayer(char player, char opponent);
    /* Deconstructor */
    virtual ~SmartComputerPlayer();
    
    virtual int move(string board);

private:
    bool areVerticallyAdjacent(int pos1, int pos2);
    bool areHorizontallyAdjacent(int pos1, int pos2);
    bool areOpposite(int pos1, int pos2);
    int getLastPlay(string board);
    int getRandomCorner(string board);
    int getRandomSide(string board);
    int searchThreats(string board, char good, char bad);
    
    int nextMove = 0;
    int lastMove = 0;
    string lastState = "_________";
    
};

#endif /* SMARTCOMPUTERPLAYER_H */

