#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "nodo.h"
#include "datafile.h"
class ArbolAVL
{
    public:
        ArbolAVL(DataFile * archivo);
        DataFile * archivo;
        Nodo * raiz;
        void add(int v,int nr);
        void agg(Nodo *n);
        Nodo * insertar(Nodo *&sraiz,Nodo * n);
        Nodo * buscarAux(int v,Nodo *&r);
        Nodo * buscar(int v);
        int obtenerFE(Nodo * n);
        Nodo * rotacionIzquierda(Nodo *r);
        Nodo * rotacionDerecha(Nodo *r);
        Nodo * rotacionDIzquierda(Nodo *r);
        Nodo * rotacionDDerecha(Nodo *r);
        char * toChar();
        char * toCharAux(Nodo *&r,int pos,char * data);
        void initFromChar(char * data);
        Nodo * initAux(char * data,int pos);
        void cargar();
        void escribir();
        int cant;
        void preOrden(Nodo *r);
        void inOrden(Nodo *r);
        void posOrden(Nodo *r);
        char* path();

};

#endif // ARBOLAVL_H
