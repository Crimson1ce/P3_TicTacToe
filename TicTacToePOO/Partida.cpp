/* 
 * File:   Partida.cpp
 * Author: Josue_Fernandez
 */

#include "Partida.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomComputerPlayer.h"
#include "DumbComputerPlayer.h"
#include "MediumComputerPlayer.h"
#include "SmartComputerPlayer.h"
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
    board = new TicTacToeBoard();

    srand(time(0));
}

Partida::~Partida() {
    freePlayersMemory();
    delete board;
}

void Partida::conseguirJugadores() {

    short randomNumber = (rand() % 2);

    char CHAR_1 = 'X';
    char CHAR_2 = '0';

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
                << "5. Computadora inteligente\n\n";
        cout << "Elija el tipo de jugador para el primer jugador: ";
        cin >> option;
    } while (option < 1 || option > 5);

    if (option == 1) {
        cout << "\nIngrese el nombre del primer jugador: ";
        cin >> nombre;
        cin.ignore();
        if (randomNumber == 1) {
            NOMBRE_1 = nombre;
        } else {
            NOMBRE_2 = nombre;
        }
        cout << endl << endl;
    }

    int option2 = 0;
    do {
        cout << "\n~~~ Tipos de jugadores ~~~\n"
                << "1. Jugador humano\n"
                << "2. Computadora aleatoria\n"
                << "3. Computadora tonta\n"
                << "4. Computadora media\n"
                << "5. Computadora inteligente\n\n";
        cout << "Elija el tipo de jugador para el segundo jugador: ";
        cin >> option2;
    } while (option2 < 1 || option2 > 5);

    if (option2 == 1) {
        cout << "\nIngrese el nombre del segundo jugador: ";
        cin >> nombre;
        cin.ignore();
        if (randomNumber == 1) {
            NOMBRE_2 = nombre;
        } else {
            NOMBRE_1 = nombre;
        }
        cout << endl << endl;
    }

    if (randomNumber != 1) {
        int aux = option;
        option = option2;
        option2 = aux;
    }

    switch (option) {
        case 1:
        {
            this->player1 = new HumanPlayer(NOMBRE_1, CHAR_1, CHAR_2);
            break;
        }
        case 2:
        {
            this->player1 = new RandomComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
        case 3:
        {
            this->player1 = new DumbComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
        case 4:
        {
            this->player1 = new MediumComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
        case 5:
        {
            this->player1 = new SmartComputerPlayer(CHAR_1, CHAR_2);
            break;
        }
    }

    switch (option2) {
        case 1:
        {
            this->player2 = new HumanPlayer(NOMBRE_2, CHAR_2, CHAR_1);
            break;
        }
        case 2:
        {
            this->player2 = new RandomComputerPlayer(CHAR_2, CHAR_1);
            if (this->player1->getName() == "Random_Computer") {
                this->player2->setName("Random_Computer_2");
            }
            break;
        }
        case 3:
        {
            this->player2 = new DumbComputerPlayer(CHAR_2, CHAR_1);
            if (this->player1->getName() == "Dumb_Computer") {
                this->player2->setName("Dumb_Computer_2");
            }
            break;
        }
        case 4:
        {
            this->player2 = new MediumComputerPlayer(CHAR_2, CHAR_1);
            if (this->player1->getName() == "Medium_Computer") {
                this->player2->setName("Medium_Computer_2");
            }
            break;
        }
        case 5:
        {
            this->player2 = new SmartComputerPlayer(CHAR_2, CHAR_1);
            if (this->player1->getName() == "Smart_Computer") {
                this->player2->setName("Smart_Computer_2");
            }
            break;
        }
    }
    cout << endl << endl;

    cout << "Las posiciones de juego son: " << endl;
    board->printPositions();
    cout << endl;

    turn = 'X';
    jugadas.clear();
}

void Partida::jugar() {
    int position;


    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    board->printBoard();

    this->state = '?';

    this->jugadas.push_back(board->toString());

    while (true) {
        //Player 1
        if (turn == 'X') {
            do {
                cout << "-> Es el turno de " << player1->getName() << ". Ingrese una posición (-1 para salir): ";
                position = player1->move(board->toString());
                if (player1->getType() != 1) {
                    cout << position << endl;
                }
            } while (position != -1 && (position < 1 || position > 9 || !board->setPosition(position, player1->getPlayerChar())));

            guardarPartida();
            if (position == -1) {
                cout << "\nLa partida se ha guardado.\n";
                break;
            }

            this->jugadas.push_back(board->toString());
            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            board->printBoard();

            if (checkEndOfGame(board->toString(), player1)) {
                guardarPartida();
                break;
            }

            turn = '0';
        }

        //Player 2
        if (turn == '0') {
            do {
                cout << "-> Es el turno de " << player2->getName() << ". Ingrese una posición (-1 para salir): ";
                position = player2->move(board->toString());
                if (player2->getType() != 1) {
                    cout << position << endl;
                }
            } while (position != -1 && (position < 1 || position > 9 || !board->setPosition(position, player2->getPlayerChar())));

            guardarPartida();
            if (position == -1) {
                cout << "\nLa partida se ha guardado.\n";
                break;
            }

            this->jugadas.push_back(board->toString());
            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            board->printBoard();

            if (checkEndOfGame(board->toString(), player2)) {
                guardarPartida();
                break;
            }

            turn = 'X';
        }

    }
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.ignore();
    cout << endl;
}

bool Partida::checkEndOfGame(string board, Player* player) {
    if (checkWinner(board, player->getPlayerChar())) {
        cout << "¡Felicidades " << player->getName() << ", has ganado!";
        player->setScore(player->getScore() + 1);
        this->state = player->getPlayerChar();
        return true;
    }

    for (int i = 0; i < board.length(); i++) {
        if (board[i] == '_') {
            return false;
        }
    }

    cout << "Hay un empate!";
    this->state = '#';
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
    } else if (historial.getState() == '?') {
        cout << "\nLa partida aun no ha terminado.\n";
        return;
    }

    int turno = 1;

    board->initMatrix();
    board->parse(historial.getJugadas().at(0));
    board->printBoard();

    Player* jugador1 = historial.getPlayer1();
    Player* jugador2 = historial.getPlayer2();

    while (turno < historial.getJugadas().size()) {

        cout << endl << "Es el turno de " << (turno % 2 == 1 ? jugador1->getName() : jugador2->getName()) << " con " << (turno % 2 == 1 ? 'X' : '0') << endl << endl;
        historial.getJugadas().at(turno);
        board->parse(historial.getJugadas().at(turno));
        board->printBoard();

        if (turno + 1 != historial.getJugadas().size()) {
            char seguir = '?';
            do {
                cout << "Desea seguir viendo esta partida? (S/N): ";
                cin >> seguir;
            } while (seguir != 'S' && seguir != 's' && seguir != 'N' && seguir != 'n');

            if (seguir == 'N' || seguir == 'n') {
                break;
            }
        }
        turno++;
    }

    if (historial.getState() == 'X') {
        cout << "\nX gano esta partida.\n";
    } else if (historial.getState() == '0') {
        cout << "\n0 gano esta partida.\n";
    }
    if (historial.getState() == '#') {
        cout << "\nEsta partida resultó en empate.\n";
    }
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.ignore();
    cout << endl;
    delete jugador1;
    delete jugador2;
}

void Partida::cargarPartida() {
    historial.cargarHistorial();

    if (historial.getState() == '-') {
        cout << "\nNo hay ninguna partida guardada.\n";
        return;
    } else if (historial.getState() != '?') {
        cout << "\nLa partida ya termino.\n";
        return;
    } else if (historial.getJugadas().size() < 1) {
        cout << "\nNo hay movimientos registrados.\n";
        return;
    }

    freePlayersMemory();

    player1 = historial.getPlayer1();
    player2 = historial.getPlayer2();

    board->parse(historial.getJugadas().at(historial.getJugadas().size() - 1));

    this->jugadas.clear();
    this->jugadas = historial.getJugadas();

    int contador_X = 0, contador_0 = 0;
    for (int i = 0; i < 9; i++) {
        if ((historial.getJugadas().at(historial.getJugadas().size() - 1))[i] == 'X') {
            contador_X++;
        } else if ((historial.getJugadas().at(historial.getJugadas().size() - 1))[i] == '0') {
            contador_0++;
        }
    }

    if (contador_X > contador_0) {
        turn = '0';
    } else {
        turn = 'X';
    }

    jugar();

}

void Partida::guardarPartida() {
    historial.guardarHistorial(this);
}

Player* Partida::getPlayer1() {
    return this->player1;
}

Player* Partida::getPlayer2() {
    return this->player2;
}

void Partida::freePlayersMemory() {
    delete player1;
    delete player2;
}

void Partida::reusePlayers() {
    int random = rand();

    if (random % 2 == 1) {
        Player* aux = player1;
        player1 = NULL;
        player1 = player2;
        player2 = NULL;
        player2 = aux;

        player1->setPlayerChar('X');
        player1->setOpponentChar('0');
        player2->setPlayerChar('0');
        player2->setOpponentChar('X');
    }
    jugadas.clear();
}

void Partida::cleanBoard() {
    if (board != NULL) {
        board->initMatrix();
    }
}
