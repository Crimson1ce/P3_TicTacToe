/* 
 * File:   Historial.h
 * Author: Josue_Fernandez
 */

#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <string>
using std::string;

#include <vector>
using std::vector;

class Historial {
public:
    /* Constructor */
    Historial();
    /* Constructor de copia */
    Historial(const Historial& orig);
    /* Destructor */
    virtual ~Historial();
private:
    vector<string> jugadas;
};

#endif /* HISTORIAL_H */

