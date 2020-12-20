/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToeBoard.h
 * Author: IT
 *
 * Created on 30 de noviembre de 2020, 06:18 PM
 */

#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include "SymmetricCharMatrix.h"

#include <string>

using std::string;

class TicTacToeBoard : public SymmetricCharMatrix {
public:
    //Constructor que crea un tablero limpio
    TicTacToeBoard(); 
    //Constructor de copia 
    TicTacToeBoard(const TicTacToeBoard& orig);
    //Destructor
    virtual ~TicTacToeBoard();
    //Imprime el tablero
    void printBoard();
    //Imprime las posiciones
    void printPositions();
    //Setter de las casillas del tablero
    bool setPosition(int casilla, char caracter);
    //Provee una interpretación del tablero en formato string
    string toString();
    //Inicializa la matriz con espacios en blanco
    virtual void initMatrix();
    //Llena las casillas del tablero d acuerdo con la cadena recibida
    void parse(string board);
private:
    
};

#endif /* TICTACTOEBOARD_H */

