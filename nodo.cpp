#include "nodo.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

Nodo::Nodo(int v,int nR)
{
    valor=v;
    izquierdo=0;
    derecho=0;
    alturaDer=0;
    alturaIz=0;
    nRegistro=nR;
    fe=0;
}

char * Nodo::toChar()
{
    iz=false;
    der=false;
    int pos=0;
    char * data= new char[22];
    if(this->derecho!=0)
        der=true;
    if(this->izquierdo!=0)
        iz=true;
    memcpy(&data[pos],&valor,4);
    pos+=4;
    memcpy(&data[pos],&nRegistro,4);
    pos+=4;
    memcpy(&data[pos],&alturaIz,4);
    pos+=4;
    memcpy(&data[pos],&alturaDer,4);
    pos+=4;
    memcpy(&data[pos],&iz,1);
    pos+=1;
    memcpy(&data[pos],&der,1);
    pos+=1;
    memcpy(&data[pos],&fe,4);
    pos+=4;
    return data;
}

void Nodo::initFromChar(char * data)
{
    int pos=0;
    memcpy(&valor,&data[pos],4);
    pos+=4;
    memcpy(&nRegistro,&data[pos],4);
    pos+=4;
    memcpy(&alturaIz,&data[pos],4);
    pos+=4;
    memcpy(&alturaDer,&data[pos],4);
    pos+=4;
    memcpy(&iz,&data[pos],1);
    pos+=1;
    memcpy(&der,&data[pos],1);
    pos+=1;
    memcpy(&fe,&data[pos],4);
    pos+=4;
}


