/*
* EJERCICIO-----5
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/*--Estruc arbol ----*/
typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*ABB;

int numNodos = 0; // nummero de nodos del arbol 



/* ---------- Estructura de la cola ---------*/
struct nodoCola{
    ABB ptr;
    struct nodoCola *sgte;
};
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

void inicializaCola(struct cola &q)
{
    q.delante = NULL;
    q.atras = NULL;
}

void encola(struct cola &q, ABB n)
{
     struct nodoCola *p;
     p = new(struct nodoCola);
     p->ptr = n;
     p->sgte = NULL;
     if(q.delante==NULL)
         q.delante = p;
     else
         (q.atras)->sgte = p;
     q.atras = p;
}

ABB desencola(struct cola &q)
{
    struct nodoCola *p;
    p = q.delante;
    ABB n = p->ptr;
    q.delante = (q.delante)->sgte;
    delete(p);
    return n;
}

ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Insertado con exito..!"<<endl<<endl;
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          enOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     numNodos++;
     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}



ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}



void recorrerxNivel(ABB arbol)
{
     struct cola q;
     inicializaCola(q);
     cout << "\t";

     if(arbol!=NULL)
     {
         encola(q, arbol);

         while(q.delante!=NULL)
         {
             arbol = desencola(q);
             cout << arbol->nro << ' ';

             if(arbol->izq!=NULL)
                 encola(q, arbol->izq);
             if(arbol->der!=NULL)
                 encola(q, arbol->der);
         }
     }
}






void menu()
{
     //system("cls");
     cout << "\n\t\t  .. ARBOL BINARIO EJERCICIO 5 ..  \n\n";
     cout << "\t [1]  Insertar elemento                  \n";
     cout << "\t [2]  Mostrar arbol                      \n";
     cout << "\t [3]  Recorridos de profundiad           \n";
     cout << "\t [4]  Recorrido por nieveles (Lucecitas prendias)  \n";
     cout << "\t [5]  SALIR                              \n";

     cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
     //system("cls");   // para limpiar pantalla
     cout << endl;
     cout << "\t [1] En Orden     \n";
     cout << "\t [2] Pre Orden    \n";
     cout << "\t [3] Post Orden   \n";
     cout << "\n\t     Opcion :  ";
}

int main()
{
    ABB arbol = NULL;
    int x;
    int op, op2;


   
    do
    {
          menu();  cin>> op;
          cout << endl;

          switch(op)
          {
               case 1:
                    cout << " Ingrese valor : ";  cin>> x;
                    insertar( arbol, x);
                    break;

               case 2:
                    verArbol(arbol, 0);
                    break;

               case 3:
                    menu2();  cin>> op2;

                    if(arbol!=NULL)
                    {
                         switch(op2)
                         {
                             case 1:
                                 enOrden(arbol); break;
                             case 2:
                                 preOrden(arbol); break;
                             case 3:
                                 postOrden(arbol); break;
                         }
                    }
                    else
                        cout << "\n\t Arbol vacio..!";
                    break;

               

               case 4:
                    cout<<"\n\n Mostrando las lucecitas de navidad encendidas\n\n";
                    recorrerxNivel(arbol);
                    break;

            
               case 5:
                    exit(0);
          }

          cout<<"\n\n\n";
          // hacer pausa y presionar una tecla para continuar
    }while(op!=11);

}
