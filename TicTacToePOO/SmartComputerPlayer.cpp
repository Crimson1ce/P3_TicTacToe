/* 
 * File:   SmartComputerPlayer.cpp
 * Author: Josue_Fernandez
 */

#include "SmartComputerPlayer.h"
#include "MediumComputerPlayer.h"
#include "RandomComputerPlayer.h"

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

#include <iostream>
using std::cout;

SmartComputerPlayer::SmartComputerPlayer(char player, char opponent)
: MediumComputerPlayer(player, opponent) {
    name = "Smart_Computer";
    this->type = 5;
}

SmartComputerPlayer::~SmartComputerPlayer() {
}

int SmartComputerPlayer::move(string board) {
    int position = defend_attack(board, playerChar);
    if (position != 0) {
        lastMove = position;

        //Actualizamos nuestro string del último estado
        lastState = board;
        lastState[lastMove - 1] = playerChar;
        return position;
    }

    position = defend_attack(board, opponentChar);
    if (position != 0) {
        lastMove = position;

        //Actualizamos nuestro string del último estado
        lastState = board;
        lastState[lastMove - 1] = playerChar;
        return position;
    }

    if (nextMove) {

        int aux = nextMove;
        nextMove = 0;
        lastState = board;
        lastState[aux - 1] = playerChar;
        return aux;
    }

    int corners[] = {1, 3, 7, 9};
    int sides[] = {2, 4, 6, 8};

    //Calculamos el turno en que estamos
    int turn = 10 - numAvailablePositions(board);

    if (turn == 1) { //Tenemos el primer turno
        nextMove = 0;

        //Elegiremos una de las 4 esquinas
        lastMove = getRandomCorner(board);

        //Actualizamos nuestro string del último estado
        lastState = board;
        lastState[lastMove - 1] = playerChar;

        return lastMove;
    } else if (turn == 2) {

        int played = getLastPlay(board);

        if (played == 5) { //En este caso, se forzará un empate (el peor caso)
            //cout << "\n\nJugo el centro\n\n";
            //Jugamos una esquina
            lastMove = getRandomCorner(board);

            //Nos aseguramos de que nuestro siguiente movimiento sea esquina
            //Esto empatará en juego en caso de no haber ataque directo
            nextMove = getRandomCorner(board);


            //Actualizamos nuestro string del último estado
            lastState = board;
            lastState[lastMove - 1] = playerChar;

            return lastMove;
        } else if (played % 2 == 1) { //Si el oponente jugó una esquina
            //cout << "\n\nJugo una esquina\n\n";
            lastMove = 5;

            //Actualizamos nuestro string del último estado
            lastState = board;
            lastState[lastMove - 1] = playerChar;

            return 5;
        } else { //Si el oponente jugó un lado
            //cout << "\n\nJugo un lado\n\n";
            do {
                lastMove = getRandomCorner(board); //Jugamos una esquina
            } while (!areHorizontallyAdjacent(lastMove, played) && !areVerticallyAdjacent(lastMove, played));

            //Actualizamos nuestro string del último estado
            lastState = board;
            lastState[lastMove - 1] = playerChar;

            return lastMove;
        }
    } else if (turn == 3) {

        int played = getLastPlay(board);

        //Si el oponente jugó en el centro
        if (played == 5) {

            //Jugamos en la esquina opuesta a la primera
            lastMove = 10 - lastMove;

            //Actualizamos nuestro string del último estado
            lastState = board;
            lastState[lastMove - 1] = playerChar;

            return lastMove;

        }//Si el oponente jugó un lado
        else if (played % 2 == 0) {

            //Si fue un lado adyacente
            if (areHorizontallyAdjacent(played, lastMove) || areVerticallyAdjacent(played, lastMove)) {
                for (int i = 0; i < 4; i++) {
                    //Elegimos una casilla que no sea adyacente a la recién jugada 
                    //por el oponente ni opuesta a nuestra primera jugada.
                    // (Una esquina adyacente.)
                    //cout << "\nJugo un lado adyacente, ultimo movimiento es " << lastMove << "\n";
                    if (!areHorizontallyAdjacent(played, corners[i])
                            && !areVerticallyAdjacent(played, corners[i])
                            && !areOpposite(lastMove, corners[i])) {
                        //cout << "\nEureka\n";
                        //Nuestra siguiente jugada será la esquina opuesta a la primera
                        nextMove = 10 - lastMove;
                        lastMove = corners[i];

                        //Actualizamos nuestro string del último estado
                        lastState = board;
                        lastState[lastMove - 1] = playerChar;

                        return lastMove;
                    }
                }
            }//Si fue un lado no adyacente
            else {


                //Jugamos el centro
                lastMove = 5;

                //Actualizamos nuestro string del último estado
                lastState = board;
                lastState[lastMove - 1] = playerChar;

                return lastMove;

            }

        }//Si jugó una esquina
        else {

            //Si el oponente jugó la esquina opuesta
            if (areOpposite(lastMove, played)) {
                for (int i = 0; i < 4; i++) {
                    if (corners[i] != played && lastMove != corners[i]) {

                        //Jugamos una esquina adyacente
                        lastMove = corners[i];

                        //Nuestro siguiente movimiento será el opuesto de esa esquina
                        nextMove = 10 - lastMove;

                        //Actualizamos nuestro string del último estado
                        lastState = board;
                        lastState[lastMove - 1] = playerChar;

                        return lastMove;
                    }
                }
            }// Si no jugó la esquina opuesta
            else {
                //Esto funcionaría de ambas maneras, de esta o si intercambiamos
                //nextMove y lastMove
                nextMove = 10 - lastMove;
                lastMove = 10 - played;

                //Actualizamos nuestro string del último estado
                lastState = board;
                lastState[lastMove - 1] = playerChar;

                return lastMove;
            }
        }
    } else if (turn == 4) {

        int played = getLastPlay(board);

        //Si hemos jugado en el centro porque el oponente jugó esquina
        if (board[4] == playerChar) {
            for (int i = 0; i < 4; i++) {
                //Y si el oponente luego jugó la esquina opuesta
                if (played % 2 == 1 && board[10 - played - 1] == opponentChar) {
                    //Jugamos uno de los lados para evitar perder
                    lastMove = getRandomSide(board);

                    //Actualizamos nuestro string del último estado
                    lastState = board;
                    lastState[lastMove - 1] = playerChar;

                    return lastMove;
                }
            }
            // Si el oponente jugó el centro (lo que signofica que nosotros 
            // jugamos esquina)
        } else if (board[4] == opponentChar) {
            //Si él jugó una esquina y yo había jugado la opuesta
            if (played % 2 == 1 && areOpposite(lastMove, played)) {
                //Jugamos una esquina para empatar
                lastMove = getRandomCorner(board);

                //Actualizamos nuestro string del último estado
                lastState = board;
                lastState[lastMove - 1] = playerChar;

                return lastMove;
            } else {
                do {
                //Jugamos una esquina para empatar
                lastMove = getRandomCorner(board);
                } while (!isAvailable(board,lastMove));

                //Actualizamos nuestro string del último estado
                lastState = board;
                lastState[lastMove - 1] = playerChar;
            }
        } else if (board[4] == '_') { //Si aún no se ha jugado el centro
            //Jugamos centro
            lastMove = 5;

            //Actualizamos nuestro string del último estado
            lastState = board;
            lastState[lastMove - 1] = playerChar;

            return lastMove;
        }
    }

    position = searchThreats(board, playerChar, opponentChar);
    if (position != 0) {
        lastMove = position;

        //Actualizamos nuestro string del último estado
        lastState = board;
        lastState[lastMove - 1] = playerChar;
        return position;
    }

    position = searchThreats(board, opponentChar, playerChar);
    if (position != 0) {
        lastMove = position;

        //Actualizamos nuestro string del último estado
        lastState = board;
        lastState[lastMove - 1] = playerChar;
        return position;
    }


    cout << "\nRandom\n";
    lastMove = RandomComputerPlayer::move(board);

    //Actualizamos nuestro string del último estado
    lastState = board;
    lastState[lastMove - 1] = playerChar;

    return lastMove;
}

bool SmartComputerPlayer::areVerticallyAdjacent(int pos1, int pos2) {
    if (pos1 > 0 && pos1 < 10 && pos2 > 0 && pos2 < 10) {
        int difference = pos1 - pos2;

        if (difference == 3 || difference == -3) {
            return true;
        }
    }
    return false;
}

bool SmartComputerPlayer::areHorizontallyAdjacent(int pos1, int pos2) {
    if (pos1 > 0 && pos1 < 10 && pos2 > 0 && pos2 < 10) {
        int difference = pos1 - pos2;
        difference = difference < 0 ? -difference : difference;

        int modifference = (pos1 % 3) - (pos2 % 3);
        modifference = modifference < 0 ? -modifference : modifference;

        if (difference == 1 && modifference > 1) {
            return true;
        }
    }
    return false;
}

bool SmartComputerPlayer::areOpposite(int pos1, int pos2) {
    if (pos1 > 0 && pos1 < 10 && pos2 > 0 && pos2 < 10 && pos1 != pos2) {
        if (pos1 + pos2 == 10) {
            return true;
        }
    }
    return false;
}

int SmartComputerPlayer::getLastPlay(string board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == opponentChar && lastState[i] == '_') {
            return i + 1;
        }
    }
    return 0;
}

int SmartComputerPlayer::getRandomCorner(string board) {
    int corners[] = {1, 3, 7, 9};
    int ret;
    do {
        ret = corners[ rand() % 4 ];
    } while (board[ret - 1] != '_');
    return ret;
}

int SmartComputerPlayer::getRandomSide(string board) {
    int sides[] = {2, 4, 6, 8};
    int ret;
    do {
        ret = sides[ rand() % 4 ];
    } while (board[ret - 1] != '_');
    return ret;
}

int SmartComputerPlayer::searchThreats(string board, char good, char bad) {
    int winning[8][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
        {1, 5, 9},
        {3, 5, 7}
    };

    int positions[9] = {};

    for (int i = 0; i < 8; i++) {

        if ((board[winning[i][0] - 1] == good || board[winning[i][0] - 1] == '_'
                || board[winning[i][1] - 1] == good || board[winning[i][1] - 1] == '_'
                || board[winning[i][2] - 1] == good || board[winning[i][2] - 1] == '_')
                &&
                (board[winning[i][0] - 1] != bad
                && board[winning[i][1] - 1] != bad
                && board[winning[i][2] - 1] != bad)
                ) {

            //if (board[winning[i][0] - 1] == ' ') {
            positions[ winning[i][0] - 1 ]++;
            //}

            //if (board[winning[i][1] - 1] == ' ') {
            positions[ winning[i][1] - 1 ]++;
            //}

            //if (board[winning[i][2] - 1] == ' ') {
            positions[ winning[i][2] - 1 ]++;
            //}
        }

    }
    int max = 0, pos = 0;
    for (int i = 0; i < 9; i++) {

        if (positions[i] > max && board[i] == '_') {
            max = positions[i];
            pos = i + 1;
        }
    }
    return pos;
}

void SmartComputerPlayer::prepareNewGame() {
    nextMove = 0;
    lastMove = 0;
    lastState = "_________";
}
