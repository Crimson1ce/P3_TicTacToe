/* 
 * File:   Partida.cpp
 * Author: Josue_Fernandez
 */

#include "Partida.h"
#include "Player.h"
#include "TicTacToeBoard.h"
#include "AdminHistorial.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstdlib>
#include <ctime>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Partida::Partida() {
    state = '-';
    turn = 'X';
}

Partida::~Partida() {
    delete player1;
    delete player2;
    delete board;
}

void Partida::conseguirJugadores() {

    srand(time(0));
    short randomNumber = (rand() % 2);

    char CHAR_1 = 'X'; //(randomNumber == 1 ? 'X' : '0');
    char CHAR_2 = '0'; //(randomNumber == 1 ? '0' : 'X');

    string NOMBRE_1;
    string NOMBRE_2;

    string nombre;

    int option = 0;
    do {
        cout << "~~~ Tipos de jugadores ~~~\n"
                << "1. Jugador humano\n"
                << "2. Computadora aleatoria\n"
                << "3. Computadora tonta\n"
                << "4. Computadora media\n"
                << "5. Computadora inteligente\n";
        cout << "Elija el tipo de jugador para el primer jugador: ";
        cin >> option;
    } while (option < 1 || option > 5);

    if (option == 1) {
        cout << "\nIngrese el nombre del primer jugador: ";
        cin >> nombre;
        cin.ignore();
        (randomNumber == 1 ? NOMBRE_1 : NOMBRE_2) = nombre;
    }

    int option2 = 0;
    do {
        cout << "~~~ Tipos de jugadores ~~~\n"
                << "1. Jugador humano\n"
                << "2. Computadora aleatoria\n"
                << "3. Computadora tonta\n"
                << "4. Computadora media\n"
                << "5. Computadora inteligente\n";
        cout << "Elija el tipo de jugador para el segundo jugador: ";
        cin >> option2;
    } while (option2 < 1 || option2 > 5);

    if (option2 == 1) {
        cout << "\nIngrese el nombre del segundo jugador: ";
        cin >> nombre;
        cin.ignore();
        (randomNumber == 1 ? NOMBRE_2 : NOMBRE_1) = nombre;
    }


    switch (option) {
        case 1:
        {
            player1 = new HumanPlayer(NOMBRE_1, CHAR_1, CHAR_2);
            break;
        }
        case 2:
        {
            player1 = new RandomComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
        case 3:
        {
            player1 = new DumbComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
        case 4:
        {
            player1 = new MediumComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
        case 5:
        {
            player1 = new SmartComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
    }
    cout << endl << endl;



    switch (option2) {
        case 1:
        {
            player2 = new HumanPlayer(NOMBRE_2, CHAR_2, CHAR_1);
            break;
        }
        case 2:
        {
            player2 = new RandomComputerPlayer(CHAR_2, CHAR_1);
            if (player1->getName() == "Random_Computer") {
                player2->setName("Random_Computer_2");
            }
            break;
        }
        case 3:
        {
            player2 = new DumbComputerPlayer(CHAR_2, CHAR_1);
            if (player1->getName() == "Dumb_Computer") {
                player2->setName("Dumb_Computer_2");
            }
            break;
        }
        case 4:
        {
            player2 = new MediumComputerPlayer(CHAR_2, CHAR_1);
            if (player1->getName() == "Medium_Computer") {
                player2->setName("Medium_Computer_2");
            }
            break;
        }
        case 5:
        {
            player2 = new SmartComputerPlayer(CHAR_2, CHAR_1);
            if (player1->getName() == "Smart_Computer") {
                player2->setName("Smart_Computer_2");
            }
            break;
        }
    }
    cout << endl << endl;

    cout << "Las posiciones de juego son: " << endl;
    board->printPositions();
    cout << endl;

    turn = 'X';
}

void Partida::jugar() {
    int position;

    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    board->printBoard();
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    while (true) {
        //Player 1
        if (turn == 'X') {
            do {
                cout << "-> Es el turno de " << player1->getName() << ". Ingrese una posición: ";
                position = player1->move(board->toString());
                if (player1->getType() != 1) {
                    cout << position << endl;
                }
            } while (position < 1 || position > 9 || !board->setPosition(position, player1->getPlayerChar()));
            
            guardarPartida();
            
            board->printBoard();

            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            if (checkEndOfGame(board->toString(), player1)) {
                break;
            }

            turn == '0';
        }

        //Player 2
        if (turn == '0') {
            do {
                cout << "-> Es el turno de " << player2->getName() << ". Ingrese una posición: ";
                position = player2->move(board->toString());
                if (player2->getType() != 1) {
                    cout << position << endl;
                }
            } while (position < 1 || position > 9 || !board->setPosition(position, player2->getPlayerChar()));

            guardarPartida();
            
            board->printBoard();

            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            if (checkEndOfGame(board->toString(), player2)) {
                break;
            }

            turn == 'X';
        }

    }
}

bool Partida::checkEndOfGame(string board, Player* player) {
    if (checkWinner(board, player->getPlayerChar())) {
        cout << "¡Felicidades " << player->getName() << ", has ganado!";
        return true;
    }

    for (int i = 0; i < board.length(); i++) {
        if (board[i] == '_') {
            return false;
        }
    }
    cout << "Hay un empate!";
    return true;

}

bool Partida::checkWinner(string board, char letter) {
    //Check each row
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == letter
                && board[i + 1] == letter
                && board[i + 2] == letter) {
            return true;
        }
    }

    //Check each column
    for (int i = 0; i < 3; i++) {
        if (board[i] == letter
                && board[i + 3] == letter
                && board[i + 6] == letter) {
            return true;
        }
    }

    //Check diagonals
    if (board[0] == letter
            && board[4] == letter
            && board[8] == letter) {
        return true;
    }

    return board[2] == letter
            && board[4] == letter
            && board[6] == letter;
}

void Partida::recrearPartida() {
    historial.cargarHistorial();
    
    if (historial.getState() == '-') {
        cout << "\nNo hay ninguna partida guardada.\n";
        return;
    } else if ( historial.getState() == '?' ) {
        cout << "\nLa partida aun no ha terminado.\n";
        return;
    }
    
    int turno = 1;
    
    board->parse(historial.getJugadas().at(0));
    
    while ( turno < historial.getJugadas().size()) {
        
        cout << endl << "Es el turno de " << (turno % 2 == 1 ? 'X' : '0') << endl << endl;
        board->parse(historial.getJugadas().at(turno));
        
        char seguir = '?';
        do {
            cout << "Desea seguir viendo esta partida? (S/N): ";
            cin >> seguir;
        } while ( seguir != 'S' && seguir != 's' && seguir != 'N' && seguir != 'S' );
        
        if(seguir == 'N' || seguir == 'n') {
            break;
        }
        
        turno++;
    }
    
    if (historial.getState() == 'X') {
        cout << "\nX gano esta partida.\n";
    } else if (historial.getState() == '0') {
        cout << "\n0 gano esta partida.\n";
    } if (historial.getState() == '#') {
        cout << "\nEsta partida resultó en empate.\n";
    }
    
}

void Partida::cargarPartida() {
    historial.cargarHistorial();

    if (historial.getState() == '-') {
        cout << "\nNo hay ninguna partida guardada.\n";
        return;
    } else if ( historial.getState() != '?' ) {
        cout << "\nLa partida ya termino.\n";
        return;
    }
    
    delete player1;
    delete player2;

    player1 = historial.getPlayer1();
    player2 = historial.getPlayer2();

    board->parse(historial.getJugadas().at(historial.getJugadas().size()-1));

    
    int contador_X = 0, contador_0 = 0;
    for (int i = 0; i < 9; i++) {
        if((historial.getJugadas().at(historial.getJugadas().size()-1))[i] == 'X'){
            contador_X++;
        } else if ((historial.getJugadas().at(historial.getJugadas().size()-1))[i] == '0') {
            contador_0++;
        }
    }
    
    if(contador_X > contador_0) {
        turn = '0';
    } else {
        turn = 'X';
    }
    
    jugar();
    
}

void Partida::guardarPartida() {
    historial.guardarHistorial(this);
}
