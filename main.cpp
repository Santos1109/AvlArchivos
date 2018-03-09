#include <iostream>
#include "arbolavl.h"
using namespace std;

int op=0, num;

int main()
{

    DataFile * archivo;
    archivo->abrir();
    ArbolAVL * arbol = new ArbolAVL(archivo);
    archivo=new DataFile(arbol->path());

    do{
        cout<<"1. Add valor"<<endl;
        cout<<"2. Print PreOrden"<<endl;
        cout<<"3. Print InOrden"<<endl;
        cout<<"4. Print PosOrden"<<endl;
        cout<<"5. Cargar arbol"<<endl;
        cout<<"Ingrese 0 si desea salir"<<endl;
        cout<<"Opcion: ";
        cin>>op;

        while(op<0 || op>5){
            cout<<"La opcion ingresada no es valida, por favor ingrese otra opcion!!"<<endl;
            cout<<"Ingrese opcion valida: ";
            cin>>op;
        }

        switch (op){
            case 1:
                op=1;

                while(op==1){
                    cout<<"Ingrese el valor que desea ingresar: ";
                    cin>>num;
                    arbol->add(num,0);
                    cout<<"Desea ingresar un nuevo valor, Si(1) o No(0)"<<endl;
                    cout<<"Ingrese su opcion: ";
                    cin>>op;
                }
                break;

            case 2:
                cout<<"########PreOrder#########"<<endl;
                arbol->preOrden(arbol->raiz);
                break;

            case 3:
                cout<<"########InOrder#########"<<endl;
                arbol->inOrden(arbol->raiz);
                break;

            case 4:
                cout<<"########PosOrder#########"<<endl;
                arbol->posOrden(arbol->raiz);
                break;

            case 5:
                arbol->cargar();
                cout<<"El arbol fue cargado con exito!"<<endl;
                break;
        }

    }while(op!=0);

    archivo->cerrar();

    return 0;
}
