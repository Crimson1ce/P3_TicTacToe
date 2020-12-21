/* 
 * File:   Historial.h
 * Author: Josue_Fernandez
 */

#ifndef ADMINHISTORIAL_H
#define ADMINHISTORIAL_H

#include "Player.h"

class Partida;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class AdminHistorial {
public:
    /* Constructor */
    AdminHistorial();
    
    /* Destructor */
    virtual ~AdminHistorial();
    
    /* Escribe el estado actual de la partida, junto con los tipos y nombres de 
     los jugadores. */
    void guardarHistorial(Partida* partida);
    
    /* Carga la partida y todas las jugadas */
    bool cargarHistorial();
    
    /* Retorna una instancia del Player1 guardado, si la hay. */
    Player* getPlayer1();
    
    /* Retorna una instancia del Player2 guardado, si la hay. */
    Player* getPlayer2();
    
    /* Retorna el vector con las jugadas. */
    vector<string> getJugadas();
    
    /* Retorna un caracter que representa el estado de la partida. */
    char getState();
    
private:
    
    ifstream lectura;
    ofstream escritura;
    
    char state;
    string namePlayer1;
    int typePlayer1;
    string namePlayer2;
    int typePlayer2;
    vector<string> jugadas;
    
};

#endif /* HISTORIAL_H */

