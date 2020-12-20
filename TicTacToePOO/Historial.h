/* 
 * File:   Historial.h
 * Author: Josue_Fernandez
 */

#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <fstream>
using std::ifstream;
using std::ofstream;

class Partida;

class Historial {
public:
    /* Constructor */
    Historial();
    
    /* Constructor de copia */
    Historial(const Historial& orig);
    
    /* Destructor */
    virtual ~Historial();
    
    /* Escribe el estado actual de la partida, junto con los tipos y nombres de 
     los jugadores. */
    void guardarHistorial();
    
    /* Carga la partida y todas las jugadas */
    void cargarHistorial();
    
private:
    
    ifstream lectura;
    ofstream escritura;
    bool finished;
    
    friend class Partida;
    
};

#endif /* HISTORIAL_H */

