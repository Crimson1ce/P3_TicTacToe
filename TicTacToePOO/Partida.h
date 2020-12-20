/* 
 * File:   Partida.h
 * Author: Josue_Fernandez
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include "Player.h"
#include "TicTacToeBoard.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

class Historial;

class Partida {
public:
    Partida();
    virtual ~Partida();
private:
    Player* player1;
    Player* player2;
    TicTacToeBoard board;
    vector<string> jugadas;
    
    friend class Historial;
};

#endif /* PARTIDA_H */

