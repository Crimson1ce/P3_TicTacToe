//Clases del proyecto
#include "TicTacToeBoard.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomComputerPlayer.h"
#include "DumbComputerPlayer.h"
#include "MediumComputerPlayer.h"
#include "SmartComputerPlayer.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

bool checkEndOfGame(string board, Player* player);

/*
 * Proyecto de Programación 3: TicTacToe con POO
 */
int main(int argc, char** argv) {

    Player* player1;
    Player* player2;

    srand(time(0));
    short randomNumber = (rand() % 2);

    char CHAR_1 = (randomNumber == 1 ? 'X' : '0');
    char CHAR_2 = (randomNumber == 1 ? '0' : 'X');

    int option = 0;
    do {
        cout << "~~~ Tipos de jugadores ~~~\n"
                << "1. Jugador humano\n"
                << "2. Computadora aleatoria\n"
                << "3. Computadora tonta\n"
                << "4. Computadora media\n"
                << "5. Computadora inteligente\n";
        cout << "Elija el tipo de jugador para Player 1: ";
        cin >> option;
    } while (option < 1 || option > 5);

    switch (option) {
        case 1:
        {
            cout << "\nIngrese el nombre de Player 1: ";
            string nombre;
            cin >> nombre;
            cin.ignore();
            player1 = new HumanPlayer(nombre, CHAR_1, CHAR_2);
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

    int option2 = 0;
    do {
        cout << "~~~ Tipos de jugadores ~~~\n"
                << "1. Jugador humano\n"
                << "2. Computadora aleatoria\n"
                << "3. Computadora tonta\n"
                << "4. Computadora media\n"
                << "5. Computadora inteligente\n";
        cout << "Elija el tipo de jugador para Player 2: ";
        cin >> option2;
    } while (option2 < 1 || option2 > 5);
    
    switch (option2) {
        case 1:
        {
            cout << "\nIngrese el nombre de Player 2: ";
            string nombre;
            cin >> nombre;
            cin.ignore();
            player2 = new HumanPlayer(nombre, CHAR_2, CHAR_1);
            break;
        }
        case 2:
        {
            player2 = new RandomComputerPlayer(CHAR_2, CHAR_1);
            player2->setName("Random_Computer_2");
            break;
        }
        case 3:
        {
            player2 = new DumbComputerPlayer(CHAR_2, CHAR_1);
            player2->setName("Dumb_Computer_2");
            break;
        }
        case 4:
        {
            player2 = new MediumComputerPlayer(CHAR_2, CHAR_1);
            player2->setName("Medium_Computer_2");
            break;
        }
        case 5:
        {
            player2 = new SmartComputerPlayer(CHAR_2, CHAR_1);
            player2->setName("Smart_Computer_2");
            break;
        }
    }
    cout << endl << endl;

    TicTacToeBoard* board = new TicTacToeBoard();

    cout << "Las posiciones de juego son: " << endl;
    board->printPositions();
    cout << endl;

    bool first = (randomNumber == 1);
    int position = -1;

    while (true) {
        //Player 1
        if (first) {
            do {
                cout << "-> Es el turno de " << player1->getName() << ". Ingrese una posición: ";
                position = player1->move(board->toString());
                if (option != 1) {
                    cout << position << endl;
                }
            } while (position < 1 || position > 9 || !board->setPosition(position, player1->getPlayerChar()));

            board->printBoard();

            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            if (checkEndOfGame(board->toString(), player1)) {
                break;
            }
        }

        first = true;

        //Player 2
        do {
            cout << "-> Es el turno de " << player2->getName() << ". Ingrese una posición: ";
            position = player2->move(board->toString());
            if (option2 != 1) {
                cout << position << endl;
            }
        } while (position < 1 || position > 9 || !board->setPosition(position, player2->getPlayerChar()));

        board->printBoard();

        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        if (checkEndOfGame(board->toString(), player2)) {
            break;
        }

    }

    delete player1;
    delete player2;
    delete board;

    return 0;
}

bool checkWinner(string board, char letter) {

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

bool checkEndOfGame(string board, Player* player) {
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