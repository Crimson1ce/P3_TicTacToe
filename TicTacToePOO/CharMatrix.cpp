#include "CharMatrix.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

//Constructor por defecto

CharMatrix::CharMatrix() {
    this->filas = this->columnas = 0;
    this->matrix = NULL;
}

//Constructor sobrecargado que recibe filas y columnas

CharMatrix::CharMatrix(int pFilas, int pColumnas) {
    this->matrix = NULL;
    createMatrix(pFilas, pColumnas);
}

//Constructor para copias

CharMatrix::CharMatrix(const CharMatrix& orig) {
    this->filas = orig.filas;
    this->columnas = orig.columnas;
    
    //Instanciar la matriz
    createMatrix(filas,columnas);
    
    //Incicializar
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            this->matrix[i][j] = orig.matrix[i][j];
        }
    }
}

//Destructor

CharMatrix::~CharMatrix() {
    freeMatrix();
}

/* Crea una nueva matriz con pFilas filas y pColumnas columnas.
 */
void CharMatrix::createMatrix(int pFilas, int pColumnas) {
    if (pFilas > 0 && pColumnas > 0) {
        if (matrix != NULL) {
            freeMatrix();
        }
        //instanciar la matriz
        matrix = new char*[pFilas];

        for (int i = 0; i < pFilas; i++) {
            matrix[i] = new char[pColumnas];
        }

        this->filas = pFilas;
        this->columnas = pColumnas;

    }
}

/* Libera la memoria de la matriz de este objeto
 */
void CharMatrix::freeMatrix() {
    if (matrix != NULL) {
        for (int i = 0; i < filas; i++) {
            if (matrix[i] != NULL) {
                delete [] matrix[i];
                matrix[i] = NULL;
            }
        }
        delete [] matrix;
        matrix = NULL;
        this->columnas = this->filas = 0;
    }
}

/* Inicializa la matriz con puntos ('.')
 */
void CharMatrix::initMatrix() {
    if (matrix != NULL) {
        for (int i = 0; i < filas; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < columnas; j++) {
                    //file >> matrix[i][j];
                    matrix[i][j] = '.';
                }
            }
        }


        //Cerrar el archivo
        //            file.close();
    }

}

/* Retorna el valor de la casilla especificada
 */
char CharMatrix::getPosValueMatrix(int x, int y) {
    if (matrix != NULL && x >= 0 && x < filas && y >= 0 && y < columnas)
        return matrix[x][y];
    return '?';
}

/* Establece el valor de la casilla especificada
 */
void CharMatrix::setPosValueMatrix(int x, int y, char val) {
    if (matrix != NULL && x >= 0 && x < filas && y >= 0 && y < columnas)
        matrix[x][y] = val;
}

/* Imprime la matriz de caracteres
 */
void CharMatrix::printMatrix() {
    if (matrix != NULL) {
        for (int i = 0; i < filas; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < columnas; j++)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
        }
    }
}

/* Retorna el número de filas de la matriz
 */
int CharMatrix::getFilas() {
    return filas;
}

/* Retorna el número de columnas de la matriz
 */
int CharMatrix::getColumnas() {
    return columnas;
}

/*Sobrecarga de operador =
 */
void CharMatrix::operator=(const CharMatrix& orig){
    this->filas = orig.filas;
    this->columnas = orig.columnas;
    
    //Instanciar la matriz
    createMatrix(filas,columnas);
    
    //Incicializar
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            this->matrix[i][j] = orig.matrix[i][j];
        }
    }
}