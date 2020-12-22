/* 
 * File:   TicTacToeBoard.cpp
 * Author: Josue_Fernandez
 * 
 */

#include "TicTacToeBoard.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*Constructor que crea un tablero limpio
 */
TicTacToeBoard::TicTacToeBoard() : SymmetricCharMatrix(3) {
    initMatrix();
}

/*Constructor de copia
 */
TicTacToeBoard::TicTacToeBoard(const TicTacToeBoard& orig) {
}

/*Destructor
 */
TicTacToeBoard::~TicTacToeBoard() {
    freeMatrix();
}

/*Imprime el tablero
 */
void TicTacToeBoard::printBoard() {
    cout << "\u001B[37m\u001B[41m" << "+---+---+---+" << "\u001B[0m" << endl;
    cout << "\u001B[37m\u001B[41m" << "| " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << " |" << "\u001B[0m" << endl;
    cout << "\u001B[37m\u001B[41m" << "+---+---+---+" << "\u001B[0m" << endl;
    cout << "\u001B[37m\u001B[41m" << "| " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << " |" << "\u001B[0m" << endl;
    cout << "\u001B[37m\u001B[41m" << "+---+---+---+" << "\u001B[0m" << endl;
    cout << "\u001B[37m\u001B[41m" << "| " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << " |" << "\u001B[0m" << endl;
    cout << "\u001B[37m\u001B[41m" << "+---+---+---+" << "\u001B[0m" << endl;
}

/*Imprime las posiciones
 */
void TicTacToeBoard::printPositions() {
    cout << "\u001B[44m\u001B[37m" << "+---+---+---+" << "\u001B[0m" << endl;
    cout << "\u001B[44m\u001B[37m" << "| 1 | 2 | 3 |" << "\u001B[0m" << endl;
    cout << "\u001B[44m\u001B[37m" << "+---+---+---+" << "\u001B[0m" << endl;
    cout << "\u001B[44m\u001B[37m" << "| 4 | 5 | 6 |" << "\u001B[0m" << endl;
    cout << "\u001B[44m\u001B[37m" << "+---+---+---+" << "\u001B[0m" << endl;
    cout << "\u001B[44m\u001B[37m" << "| 7 | 8 | 9 |" << "\u001B[0m" << endl;
    cout << "\u001B[44m\u001B[37m" << "+---+---+---+" << "\u001B[0m" << endl;
    
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.ignore();
    cout << endl;
}

/*Setter de las casillas del tablero
 */
bool TicTacToeBoard::setPosition(int casilla, char caracter) {
    int x = (casilla-1)/3;
    int y = (casilla-1)%3;
    if(casilla>=1 && casilla<=9 && matrix[x][y] == ' ') {
        matrix[x][y] = caracter;
        return true;
    }
    return false;
}

/*Provee una interpretación del tablero en formato string
 */
string TicTacToeBoard::toString() {
    string retValue = "";
    for (int i = 1; i <= 9; i++) {
        char casilla = matrix[(i-1)/3][(i-1)%3];
        retValue += ( casilla == ' ' ? '_' : casilla );
    }
    return retValue;
}

/*Inicializa la matriz con espacios en blanco
 */
void TicTacToeBoard::initMatrix(){
    if(matrix == NULL) return;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrix[i][j] = ' ';
        }
    }
}

/*Llena las casillas del tablero d acuerdo con la cadena recibida
 */
void TicTacToeBoard::parse(string board){
    if(matrix == NULL) return;
    if(board.length() == 9)
    for (int i = 0; i < board.length(); i++) {
        char caracter = board[i] == '_' ? ' ' : board[i] ;
        setPosition(i+1, caracter);
    }
}