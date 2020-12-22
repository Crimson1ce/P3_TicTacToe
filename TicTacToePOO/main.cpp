//Clases del proyecto
#include "Partida.h"
#include "Player.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

//Muestra el menu de opciones del juego
int menuPrincipal();
//Muestra el puntaje de los jugadores actuales
void mostrarPuntajes(Partida* partida);

//Contador de empates de los jugadores actuales
int empates = 0;

/*
 * Proyecto de Programación 3: TicTacToe con POO
 */
int main(int argc, char** argv) {

    Partida* partida = new Partida;

    int option = 0;
    do {

        switch (option = menuPrincipal()) {
            case 1:
            {
                int decision;
                cout << "1 -> Determinar nuevos jugadores " << endl;
                cout << "2 -> Continuar con los jugadores actuales " << endl << endl;
                cout << "Ingrese la opcion que desee: ";
                cin >> decision;

                while (decision != 1 && decision != 2) {
                    cout << "Ingrese una opcion valida: ";
                    cin >> decision;
                }
                cout << endl;

                if (decision == 1) {
                    empates = 0;
                    partida->conseguirJugadores();
                } else {
                    if (partida->getPlayer1() == NULL || partida->getPlayer2() == NULL) {
                        cout << "No se han establecido jugadores aun.\n\n";
                        empates = 0;
                        partida->conseguirJugadores();
                    } else {
                        partida->reusePlayers();
                    }
                }

                partida->cleanBoard();
                partida->jugar();
                
                if (partida->getState() == '#') {
                    empates++;
                }
                
                break;
            }
            case 2:
            {
                partida->cargarPartida();
                
                if (partida->getState() == '#') {
                    empates++;
                }
                
                break;
            }
            case 3:
            {
                partida->recrearPartida();
                break;
            }
            case 4:
            {
                mostrarPuntajes(partida);
                break;
            }
            case 5:
            {
                char seguir = 'n';

                do {
                    cout << "Estás seguro de que deseas salir? (S/N): ";
                    cin >> seguir;
                } while (seguir != 'S' && seguir != 's' && seguir != 'N' && seguir != 'n');

                if (seguir == 'N' || seguir == 'n') {
                    option = 0;
                }

                break;
            }
        }
        cout << endl << endl;

    } while (option != 5);

    cout << "Nos vemos!\n";

    delete partida;
    return 0;
}

int menuPrincipal() {
    cout << "\u001B[31m\u001B[47m" << "+-----------------------------+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "|                             |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "|    T I C - T A C - T O E    |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "|     R E V O L U T I O N     |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "|                             |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+----+------------------------+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| 1. | Nueva partida          |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| 2. | Cargar partida         |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| 3. | Recrear ultima partida |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| 4. | Ver puntajes           |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| 5. | Salir                  |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+----+------------------------+" << "\u001B[0m" << endl << endl;

    int opcion;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 5) {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }
    cout << endl << endl;
    cin.ignore();

    return opcion;
}

void mostrarPuntajes(Partida* partida) {
    cout << "\u001B[31m\u001B[47m" << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "|    TABLA DE PUNTUACION    |" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << "\u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "|" << "\u001B[0m" << endl;
    
    if (partida->getPlayer1() == NULL || partida->getPlayer2() == NULL) {
        cout << "\u001B[31m\u001B[47m" << "| No hay puntajes para mostrar." << "\u001B[0m" << endl;
        return;
    }
    cout << "\u001B[31m\u001B[47m" << "| Puntos:  " << partida->getPlayer1()->getScore() << " - " << partida->getPlayer1()->getName() << " \u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| Puntos:  " << partida->getPlayer2()->getScore() << " - " << partida->getPlayer2()->getName() << " \u001B[0m" << endl;
    cout << "\u001B[31m\u001B[47m" << "| Empates: " << empates << " \u001B[0m" << endl;
    
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cout << '\n';
}