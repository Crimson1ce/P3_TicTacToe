#ifndef SYMMETRICCHARMATRIX_H
#define SYMMETRICCHARMATRIX_H

#include "CharMatrix.h" //Incluir la clase base

class SymmetricCharMatrix : public CharMatrix { //Todos los métodos públicos de la clase base son públicos también
public:
    //Constructor por defecto
    SymmetricCharMatrix();
    //Constructor de copia
    SymmetricCharMatrix(const SymmetricCharMatrix& orig);
    //Destructor
    virtual ~SymmetricCharMatrix();
    
    //Constructor sobrecargado que recibe el tamaño de la matriz
    SymmetricCharMatrix(int);
    
    
    
private:

};

#endif /* SYMMETRICCHARMATRIX_H */

