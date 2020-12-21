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
                    partida->conseguirJugadores();
                } else {
                    if (partida->getPlayer1() == NULL || partida->getPlayer2() == NULL) {
                        cout << "No se han establecido jugadores aun.\n\n";
                        partida->conseguirJugadores();
                    } else {
                        partida->reusePlayers();
                    }
                }

                partida->cleanBoard();
                partida->jugar();

                break;
            }
            case 2:
            {
                partida->cargarPartida();
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

    cout << "\nNos vemos!\n";

    delete partida;
    return 0;
}

int menuPrincipal() {
    cout << "+-----------------------------+" << endl;
    cout << "|                             |" << endl;
    cout << "|    T I C - T A C - T O E    |" << endl;
    cout << "|     R E V O L U T I O N     |" << endl;
    cout << "|                             |" << endl;
    cout << "+----+------------------------+" << endl;
    cout << "| 1. | Nueva partida          |" << endl;
    cout << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "| 2. | Cargar partida         |" << endl;
    cout << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "| 3. | Recrear ultima partida |" << endl;
    cout << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "| 4. | Ver puntajes           |" << endl;
    cout << "+~~~~+~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "| 5. | Salir                  |" << endl;
    cout << "+----+------------------------+" << endl << endl;

    int opcion;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 5) {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }
    cout << endl << endl;

    return opcion;
}

void mostrarPuntajes(Partida* partida) {
    cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "|    TABLA DE PUNTUACION    |" << endl;
    cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "|" << endl;
    
    if (partida->getPlayer1() == NULL || partida->getPlayer2() == NULL) {
        cout << "| No hay puntajes para mostrar." << endl;
        return;
    }
    cout << "| Puntos: " << partida->getPlayer1()->getScore() << " - " << partida->getPlayer1()->getName() << endl;
    cout << "| Puntos: " << partida->getPlayer2()->getScore() << " - " << partida->getPlayer2()->getName() << endl;
}