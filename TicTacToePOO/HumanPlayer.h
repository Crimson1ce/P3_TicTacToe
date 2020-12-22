/* 
 * File:   HumanPlayer.h
 * Author: Josue_Fernandez
 *
 * Created on 30 de noviembre de 2020, 08:33 PM
 */

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

#include <string>
using std::string;

class HumanPlayer : public Player {
public:
    /* Constructor
     */
    HumanPlayer(string name, char player, char opponent);
    
    /* Destructor
     */
    virtual ~HumanPlayer();
    
    /* Returns input received from the user: a position to play on the board.
     */
    int move(string board);
    
    void prepareNewGame();

    
private:

};

#endif /* HUMANPLAYER_H */

