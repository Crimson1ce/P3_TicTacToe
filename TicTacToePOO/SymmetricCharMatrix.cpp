#include "SymmetricCharMatrix.h"

#include <iostream>

using std::cout;
using std::endl;

SymmetricCharMatrix::SymmetricCharMatrix():CharMatrix() { //En la clase padre se inicializa con 0
}

SymmetricCharMatrix::SymmetricCharMatrix(const SymmetricCharMatrix& orig) {
}

SymmetricCharMatrix::~SymmetricCharMatrix() {
    freeMatrix();
}

SymmetricCharMatrix::SymmetricCharMatrix(int size) : CharMatrix(size, size) { // El código de la clase padre se ejecuta
}

