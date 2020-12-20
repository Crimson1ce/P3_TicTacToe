/* 
 * File:   Historial.cpp
 * Author: Josue_Fernandez
 */

#include "AdminHistorial.h"
#include "Partida.h"

#include "Player.h"
#include "HumanPlayer.h"
#include "RandomComputerPlayer.h"
#include "DumbComputerPlayer.h"
#include "MediumComputerPlayer.h"
#include "SmartComputerPlayer.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::ios;

AdminHistorial::AdminHistorial() {
    state = '-';
}

AdminHistorial::~AdminHistorial() {
}

void AdminHistorial::guardarHistorial(Partida* partida) {
    escritura.open("Juego\\Partida_Guardada.txt", ios::out | ios::trunc);
    if (escritura.is_open()) {
        
        escritura << partida->state << '\n';
        
        if(partida->state != '-') {
            
            escritura << partida->player1->getType() << '\n';
            escritura << partida->player1->getName() << '\n';
            escritura << partida->player2->getType() << '\n';
            escritura << partida->player2->getName() << '\n';
            
            for (int i = 0; i < partida->jugadas.size(); i++) {
                escritura << partida->jugadas.at(i) << '\n';
            }
            
        }
        
        
    } else {
        cout << "\nError al guardar la partida.\n";
    }
    escritura.close();
}

bool AdminHistorial::cargarHistorial() {
    lectura.open("Juego\\Partida_Guardada.txt");
    if (lectura.is_open()) {

        lectura >> state;

        // - No hay un juego cargado
        // ? Juego en curso
        // # Empate
        // X Ganó la X
        // 0 Ganó el O
        
        if (state == '-') {
            cout << "\nNo hay una partida guardada.\n";
            return false;
        }
        
        int tipo;
        string nombre;

        lectura >> this->typePlayer1;
        lectura >> this->namePlayer1;
        
        lectura >> this->typePlayer2;
        lectura >> this->namePlayer2;
        
        this->jugadas.clear();
        
        string movimiento;
        while(lectura >> movimiento){
            this->jugadas.push_back(movimiento);
        }

        lectura.close();
        return true;

    }
    lectura.close();
    cout << "\nError al abrir el archivo.\n";
    return false;
}

vector<string> AdminHistorial::getJugadas() {
    return this->jugadas;
}

Player* AdminHistorial::getPlayer1() {
    if (state != '-') {
        
        Player* player1 = NULL;
        
        switch (this->typePlayer1) {
            case 1: { //Jugador humano
                player1 = new HumanPlayer(this->namePlayer1, 'X', '0');
                break;
            }
            case 2: { //Computadora aleatoria
                player1 = new RandomComputerPlayer('X', '0');
                player1->setName(this->namePlayer1);
                break;
            }
            case 3: { //Computadora tonta
                player1 = new DumbComputerPlayer('X', '0');
                player1->setName(this->namePlayer1);
                break;
            }
            case 4: { //Computadora media
                player1 = new MediumComputerPlayer('X', '0');
                player1->setName(this->namePlayer1);
                break;
            }
            case 5: { //Computadora inteligente
                player1 = new SmartComputerPlayer('X', '0');
                player1->setName(this->namePlayer1);
                break;
            }
        }
        return player1;
    }
    return NULL;
}

Player* AdminHistorial::getPlayer2() {
    if (state != '-') {
        
        Player* player2 = NULL;
        
        switch (this->typePlayer2) {
            case 1: { //Jugador humano
                player2 = new HumanPlayer(this->namePlayer2, 'X', '0');
                break;
            }
            case 2: { //Computadora aleatoria
                player2 = new RandomComputerPlayer('X', '0');
                player2->setName(this->namePlayer2);
                break;
            }
            case 3: { //Computadora tonta
                player2 = new DumbComputerPlayer('X', '0');
                player2->setName(this->namePlayer2);
                break;
            }
            case 4: { //Computadora media
                player2 = new MediumComputerPlayer('X', '0');
                player2->setName(this->namePlayer2);
                break;
            }
            case 5: { //Computadora inteligente
                player2 = new SmartComputerPlayer('X', '0');
                player2->setName(this->namePlayer2);
                break;
            }
        }
        return player2;
    }
    return NULL;
}

char AdminHistorial::getState() {
    return this->state;
}
