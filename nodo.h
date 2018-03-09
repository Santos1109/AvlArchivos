#ifndef NODO_H
#define NODO_H


class Nodo
{
    public:
        Nodo(int v,int nR);
        bool borrado;
        Nodo * izquierdo;
        Nodo * derecho;
        bool iz;
        bool der;
        int valor;
        int alturaIz;
        int alturaDer;
        int fe;
        int nRegistro;
        char * toChar();
        void initFromChar(char * data);

};

#endif // NODO_H
