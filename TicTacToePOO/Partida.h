/* 
 * File:   Partida.h
 * Author: Josue_Fernandez
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include "Player.h"
#include "TicTacToeBoard.h"
#include "AdminHistorial.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

class Partida {
public:
    Partida();
    virtual ~Partida();
    
    /* Recrea una partida ya terminada. */
    void recrearPartida();
    
    /* Carga una partida en curso para reanudarla. */
    void cargarPartida();
    
    /* Guarda la partida actual. */
    void guardarPartida();
    
    /* Empieza o reanuda una partida de TicTacToe. */
    void jugar();
    
    /* Pide los tipos de jugadores al usuario. */
    void conseguirJugadores();
    
    /* Checks if the game has ended. */
    bool checkEndOfGame(string board, Player* player);
    
    /* Checks if someone has won. */
    bool checkWinner(string board, char letter);
    
    /* Returns a pointer to Player1 */
    Player* getPlayer1();
    
    /* Returns a pointer to Player2 */
    Player* getPlayer2();
    
    /* Returns a char representing the state of the game */
    char getState();
    
    /* Frees the memory of the player pointers */
    void freePlayersMemory();
    
    /* Reuses the current player instances. */
    void reusePlayers();
    
    /* Prepares the TicTacToe Board for a new game */
    void cleanBoard();
    
private:
    Player* player1;
    Player* player2;
    TicTacToeBoard* board;
    vector<string> jugadas;
    AdminHistorial historial;
    char state;
    char turn;
    
    friend class AdminHistorial;
};

#endif /* PARTIDA_H */

