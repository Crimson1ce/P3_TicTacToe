#ifndef CHARMATRIX_H
#define CHARMATRIX_H

class CharMatrix {
public:
    //Constructor por defecto
    CharMatrix();
    //Constructor sobrecargado que recibe filas y columnas
    CharMatrix(int, int);
    //Constructor para copias
    CharMatrix(const CharMatrix& orig);
    //Crea una matris de tamaño filas * columnas
    void createMatrix(int, int);
    //Libera la matriz
    void freeMatrix();
    //Inicializa la matriz con valores
    virtual void initMatrix();
    //Retorna el valor en una casilla x,y 
    char getPosValueMatrix(int, int);
    //Establece el valor en una casilla x,y
    void setPosValueMatrix(int, int, char);
    //Imprime la matriz
    void printMatrix();
    //Retorna las filas
    int getFilas();
    //Retorna las columnas
    int getColumnas();
    //Destructor
    virtual ~CharMatrix();
    
    //Sobrecarga de operador =
    void operator=(const CharMatrix& orig);
    
protected:
    char** matrix;
    int filas;
    int columnas;

};

#endif /* CHARMATRIX_H */
