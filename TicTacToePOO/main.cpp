//Clases del proyecto
#include "TicTacToeBoard.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomComputerPlayer.h"
#include "DumbComputerPlayer.h"
#include "MediumComputerPlayer.h"
#include "SmartComputerPlayer.h"
#include "Partida.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

/*
 * Proyecto de Programación 3: TicTacToe con POO
 */
int main(int argc, char** argv) {

    Partida* partida = new Partida;
    
    partida->conseguirJugadores();
    partida->jugar();
    
    delete partida;
    
    return 0;
}
