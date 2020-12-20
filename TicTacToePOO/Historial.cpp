/* 
 * File:   Historial.cpp
 * Author: Josue_Fernandez
 */

#include "Historial.h"
#include "Partida.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;

Historial::Historial() {
    finished = false;
}

Historial::Historial(const Historial& orig) {
}

Historial::~Historial() {
}

void Historial::guardarHistorial() {

}

bool Historial::cargarHistorial() {
    lectura.open("Juego\\Partida_Guardada.txt");
    if (lectura.is_open()) {

        string gameEnded;
        lectura >> gameEnded;

        if (gameEnded == "false") {
            finished = false;
        } else if (gameEnded == "true") {
            finished = true;
        }
        
        int tipo;
        string nombre;

        lectura >> tipo;
        lectura >> nombre;

        switch (tipo) {
            case 1:
            {

                

                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
        }

        lectura.close();
        return true;

    }
    lectura.close();
    cout << "\nError al abrir el archivo.\n";
    return false;
}
