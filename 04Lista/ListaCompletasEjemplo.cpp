/*
Es una estructura de datos que deriva de una secuencia 
conectada de nodos, y cada uno de los cuales
contiene un dato
Hay un nodo al comienzo llamado la cabeza o frente
Hay un nodo de termino llamada la cola o atras
La lista solo puede ser recorrida en secuencia atras 
o hacia adelante
Operaciones de la estructura
Añadir o insertar elemento
eliminar o Borrar elemento
moverme eatraves de la lista desde el primero al ultimo
Buscar elementos
&
**
*elemento   apuntador memoria(direccion de memoria / el peso)
.elemento 
list    es una clase templete que nos permite
crear listas que contengan cualquier tipo de objeto
incluye las operaciones
push  meter
pop   sacar
begin()
end()
size()   tamaño
empty()  vacio
*/

 
#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;

 
void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}
 

 
int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
void insertarElemento(Tlista &lista, int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;
 
    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;
 
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}
 
 
void mostrarLista(Tlista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
}
 
 
void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 

 
    // fin del while
   
    cout<<"\n\n Valores eliminados..!"<<endl;
}
 
void menu1()
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. Insertar nuevo valor en la lista              "<<endl;
    cout<<" 2. Ver la lista                "<<endl;
    cout<<" 3. Borrar un Elemento            "<<endl;
    cout<<" 4. Salir                            "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
 
int main()
{
    Tlista lista = NULL;
    int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar
 
 
    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarInicio(lista, _dato);
            break;

            case 2:
 
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 mostrarLista(lista);
            break;
 
            case 3:
 
                cout<<"\n Valor a eliminar: "; cin>> _dato;
 
                eliminarElemento(lista, _dato);
            break;
 
                    }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=4);
 
 
   system("pause");
   return 0;
}
