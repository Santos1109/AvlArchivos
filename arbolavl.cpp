#include "arbolavl.h"
#include <string.h>
#include <iostream>
#include "nodo.h"
#include "datafile.h"
#include <stdio.h>

using namespace std;

ArbolAVL::ArbolAVL(DataFile * a)
{
    raiz=0;
    cant=0;
    archivo=a;
}


void ArbolAVL::add(int v,int nr)
{
    Nodo * n=new Nodo(v,nr);
    agg(n);
    cant++;
}

void ArbolAVL::agg(Nodo * n)
{
    if(raiz==0)
        raiz=n;
    else
        raiz=insertar(raiz,n);
}


Nodo * ArbolAVL::insertar(Nodo *&sraiz,Nodo * n)
{
    Nodo * nuevoPadre=sraiz;
    if(n->valor < sraiz->valor)
    {
       if(sraiz->izquierdo==0)
            sraiz->izquierdo=n;
       else
       {
            sraiz->izquierdo=insertar(sraiz->izquierdo,n);
            if((obtenerFE(sraiz->izquierdo))-obtenerFE(sraiz->derecho) ==2)
            {
                if(n->valor<sraiz->izquierdo->valor)
                    nuevoPadre=rotacionDerecha(sraiz);
                else
                    nuevoPadre=rotacionDDerecha(sraiz);
            }
       }

    }
    else if(n->valor>sraiz->valor)
    {
        if(sraiz->derecho==0)
            sraiz->derecho=n;
        else
        {
             sraiz->derecho=insertar(sraiz->derecho,n);
             if((obtenerFE(sraiz->derecho))-obtenerFE(sraiz->izquierdo) ==2)
             {
                 if(n->valor>sraiz->derecho->valor)
                     nuevoPadre=rotacionIzquierda(sraiz);
                 else
                     nuevoPadre=rotacionDIzquierda(sraiz);
             }
        }
    }
    else
        cout<<"Nodo Duplicado"<<endl;

    if(sraiz->izquierdo==0 && sraiz->derecho!=0)
    {
        sraiz->fe=sraiz->derecho->fe+1;
    }
    else if( sraiz->derecho==0 &&sraiz->izquierdo!=0 )
    {
        sraiz->fe=sraiz->izquierdo->fe+1;
    }
    else
    {
        int a=obtenerFE(sraiz->izquierdo);
        int b=obtenerFE(sraiz->derecho);
        sraiz->fe= a >b ? a+1:b+1;
    }
    return nuevoPadre;
}


Nodo * ArbolAVL::buscar(int v)
{
    return buscarAux(v,raiz);
}


Nodo * ArbolAVL::buscarAux(int v,Nodo *&r)
{
    if(r==0)
        return 0;
    else if(r->valor==v)
    {
        return r;
    }
    else if(r->valor>v)
        return buscarAux(v,r->izquierdo);
    return buscarAux(v,r->derecho);
}


int ArbolAVL::obtenerFE(Nodo * n)
{
    if(n==0)
    {
        return -1;
    }
    else
    {
        return n->fe;
    }
}

Nodo * ArbolAVL::rotacionIzquierda(Nodo *r)
{
    Nodo * hijoDer=r->derecho;
    r->derecho=hijoDer->izquierdo;
    hijoDer->izquierdo=r;
    int c=obtenerFE(r->izquierdo);
    int d=obtenerFE(r->derecho);
    r->fe=(c>d ? c:d)+1;
    int a=obtenerFE(hijoDer->izquierdo);
    int b=obtenerFE(hijoDer->derecho);
    hijoDer->fe= (a>b ? a:b)+1;
    return hijoDer;

}

Nodo* ArbolAVL::rotacionDerecha(Nodo *r)
{
    Nodo * hijoIz=r->izquierdo;
    r->izquierdo=hijoIz->derecho;
    hijoIz->derecho=r;
    int c=obtenerFE(r->izquierdo);
    int d=obtenerFE(r->derecho);
    r->fe=(c>d ? c:d)+1;
    int a=obtenerFE(hijoIz->izquierdo);
    int b=obtenerFE(hijoIz->derecho);
    hijoIz->fe= (a>b ? a:b)+1;
    return hijoIz;
}

Nodo * ArbolAVL::rotacionDIzquierda(Nodo *r)
{
    Nodo * tmp;
    r->izquierdo=rotacionDerecha(r->derecho);
    tmp=rotacionIzquierda(r);
    return tmp;
}

Nodo * ArbolAVL::rotacionDDerecha(Nodo *r)
{
    Nodo * tmp;
    r->izquierdo=rotacionIzquierda(r->izquierdo);
    tmp=rotacionDerecha(r);
    return tmp;
}

char * ArbolAVL::toChar()
{
    int pos=0;
    char * entry_data= new char[22*cant];
    return toCharAux(raiz,pos,entry_data);
}

char * ArbolAVL::toCharAux(Nodo *&r,int pos,char * data)
{
    if(r==0)
        return data;
    char * data_entry= r->toChar();
    memcpy(&data[pos],data_entry,22);
    pos+=22;
    toCharAux(r->izquierdo,pos,data);
    toCharAux(r->derecho,pos,data);
}

void ArbolAVL::initFromChar(char * data)
{
    int pos=0;
    Nodo * r=initAux(data,pos);
    agg(r);
}

Nodo * ArbolAVL::initAux(char * data,int pos)
{
    char * data_entry= new char[22];
    memcpy(data_entry,&data[pos],22);
    Nodo * r=new Nodo(0,0);
    r->initFromChar(data_entry);
    pos+=22;
    if(r->iz)
        r->izquierdo=initAux(data,pos);
    else
        r->izquierdo=0;
    if(r->der)
        r->derecho=initAux(data,pos);
    else
        r->derecho=0;
    return r;
}

void ArbolAVL::escribir()
{
    char * data= this->toChar();
    int tam= cant*22;
    archivo->escribir(data,0,tam);
}

void ArbolAVL::cargar()
{
    int tam=archivo->getTam();
    char * data=archivo->leer(0,tam);
    initFromChar(data);
    cant=tam/22;
}

void ArbolAVL::preOrden(Nodo *r)
{
    if(r==0)
        return;
    cout << r->valor<<endl;
    preOrden(r->izquierdo);
    preOrden(r->derecho);
}

void inOrden(Nodo* r){
    if(r==NULL)
        return;

    inOrden(r->izquierdo);
    cout<<r->valor<<endl;
    inOrden(r->derecho);
}

void posOrden(Nodo *r){
    if(r==NULL)
        return;
    posOrden(r->izquierdo);
    posOrden(r->derecho);
    cout << r->valor<<endl;
}

const char *path(){
    return "C:\\Users\\saint\\CLionProjects\\ArbolAVLArchivos\\Indices.data";
}





