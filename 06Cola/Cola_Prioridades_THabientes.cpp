
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>

using namespace std;
 
/*                Estructura de los nodos de la cola       */
struct nodo
{
	char nombre ;
    char dato;
    int priori;        // prioridad del nodo
    struct nodo *sgte;
};

/*                      Estructura de la cola      */
struct cola
{
	nodo alu;
    nodo *delante;
    nodo *atras  ;
};

/*                         Crear Nodo     */
struct nodo *crearNodo( char y, char x, int pr)
{
    struct nodo *nuevoNodo = new(struct nodo);
  	 nuevoNodo->nombre = y ;
    nuevoNodo->dato = x;
    nuevoNodo->priori = pr;
    return nuevoNodo;
};


/*                        Encolar cacarter con prioridad      */
void encolar( struct cola &q, char valor1, char valor, int priori )
{
     
     struct nodo *aux = crearNodo( valor1, valor, priori);
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;

     q.atras = aux;        // puntero que siempre apunta al ultimo elemento 
}

/*                        Mostrar Cola       */
void muestraCola( struct cola q )
{
     struct nodo *aux;
   
     aux = q.delante;
     
     cout << " Nombre     Tipo de cuenta    Turno " << endl;
     cout << " -----------------------------------" << endl;
          
     while( aux != NULL )
     {
            cout<<"    "<< aux->nombre << "      |   " << aux->dato << "            |   " << aux->priori << endl;
            aux = aux->sgte;
     }    
}

/*         Ordenar  por prioridad( criterio de O. por Burbuja)    */
void ordenarPrioridad( struct cola &q )
{
     struct nodo *aux1, *aux2;
     int p_aux;
     char c_aux;
     
     aux1 = q.delante;
     
     while( aux1->sgte != NULL)
     {
            aux2 = aux1->sgte;
            
            while( aux2 != NULL)
            {
                   if( aux1->priori > aux2->priori )
                   {
                       p_aux = aux1->priori;
                       c_aux = aux1->dato;
                       
                       aux1->priori = aux2->priori;
                       aux1->dato   = aux2->dato;
                       
                       aux2->priori = p_aux;
                       aux2->dato   = c_aux;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}
/*                Inserta cacacteres en una cola     */
void insertar( struct cola &q, char b, char c, int pr )
{
     /* Encolando caracteres */
     encolar( q, b, c, pr );
     
     /* Ordenando por prioridad */
     ordenarPrioridad( q ); 
}

/*
Supongamos que quiero 
guardar la cola en archivo
txt

void guardar(){
	//primero es crear el archivo
	FILE *archivo;
	archivo = fopen("guardar.txt", "w");//aqui va el nombre
	//se le conoce como la serializacion del archivo
	int i = 0;
	if(!i){
		cout<<"no hay nada que guaradar";
		getchar();
		return;
		
	}
	q = i;
	while(q){
	fprint(archivo, "%i\n", q->dato);  //%i enteros   %c caracter 
	q = q->siguiente;
	}
	cout<<"archivo guardado";
	//es importante cerrar el flujo del archivo
	fclose(archivo);
	getchar();
}

fscanf(archivo, "%i\n", &q)  */


// las funciones
void menuPrincipal();
void menuAsignarturno();
void menuBanco();
void menuMostrarfila();



int main()
{
		nodo alu;
    menuPrincipal();
    return 0;
}




void menuPrincipal()
{
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1. Asignar Turno" << endl;
        cout << "\t2. Realizar la operacion --- Entrar al Sistema Bancario" << endl;
        cout << "\t3. Mostrar tarjetahabientes en fila" << endl;
        cout << "\t4. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuAsignarturno();
            break;

        case 2:
            menuBanco();
            break;
            
        case 3:
            menuMostrarfila();
            break;

        case 4:
            repetir = false;
            break;
        }
    } while (repetir);
}

// Def

void menuAsignarturno()
{
  int opcion;
    bool repetir = true;
  
  struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;
    
	char b ; 
    char c ;     // caracter a encolar
    int pr;      // prioridad del caracter
    int op;      // opcion del menu
    int x ;      // numero que devuelve la funcon pop
    
     
      
    do
    {
        system("cls");

         cout<<"\n\t SISTEMA DE TURNOS \n\n";
    cout<<" 1. INGRESA UN TURNO                           "<<endl;
    cout<<" 2. IMPRIMIR TURNO                           "<<endl;
    cout<<" 3. REGRESAR                             "<<endl;

    cout<<"\n INGRESE OPCION: ";
        cin >> opcion;
          
       
        switch(opcion)
        {
            case 1:
            	 
				 cout<< "\n Ingrese el Nombre del Tarjetahabiente: ";
				 
				 cin>> b;
                 cout<< "\n Ingrese el tipo de cuenta \n N= Normal \n E= Empresarial \n V= Vip \n S= Sin cuenta: ";
                 cin>> c;
                 
                 cout<< "\n Ingrese Turno: ";   
                 cin>> pr;
                 
                 insertar( q, b, c, pr );
                 
                 cout<<"\n\n\t\tFormese e la caja '" << c << "' Y espere su turno...\n\n";
            break; 
                  
            case 2:

                 cout << "\n\n IMPRIMIENDO SU TURNO \n\n";
                
                 if(q.delante!=NULL)
                     muestraCola( q );
                 else   
                    cout<<"\n\n\tCola vacia...!"<<endl;
            break;
            
			case 3:
            repetir = false;
            break;
            
            default:
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                    system("pause");
                    exit(0);
         }

       
        system("pause"); 
		 

    }while (repetir);
    
}




void menuBanco()
{
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");

        int opcion;
    float total=1000,ingreso,egreso;
    std::cout<<"¡¡Bienvenido al sistema bancario!!\n";
    regreso:
    std::cout<<"Por favor digita una opcion:\n";
    std::cout<<"1.- Ingreso de dinero\n";
    std::cout<<"2.- Retirar dinero\n";
    std::cout<<"3.- Salir\n";
    std::cin>>opcion;
    switch (opcion)
    {
    case 1:
        std::cout<<"Cuanto dinero vas a ingresar? ";
        std::cin>>ingreso;
       
         if(ingreso>=5001){
            std::cout<<"Solo puedes depositar un maximo de 5000, tienes "<<total<<"\n";
        }else{
            total+=ingreso;
             std::cout<<"Tu saldo a favor en el bancon $"<<total<<"\n";
        }
       
        goto regreso;
    case 2:
        std::cout<<"Cuanto dinero deseas sacar: ";
        std::cin>>egreso;
        if(egreso>total){
            std::cout<<"Saldo Insuficientes, tienes "<<total<<"\n";
        }else{
            total-=egreso;
            std::cout<<"Tu saldo actual es $"<<total<<"\n";
        }
        goto regreso;

        case 3:
            repetir = false;
            break;
        }
    } while (repetir);
}


void menuMostrarfila()
{
     int opcion;
    bool repetir = true;
  
  struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;
    
	char b ; 
    char c ;     // caracter a encolar
    int pr;      // prioridad del caracter
    int op;      // opcion del menu
    int x ;      // numero que devuelve la funcon pop
    
     
      
    do
    {
        system("cls");

         cout<<"\n\t SISTEMA DE TURNOS \n\n";
    cout<<" 1. MOSTRAR FILA                           "<<endl;
    cout<<" 2. REGRESAR                          "<<endl;
    

    cout<<"\n INGRESE OPCION: ";
        cin >> opcion;
          
       
        switch(opcion)
        {
            
            case 1:

                 cout << "\n\n MOSTRANDO LA FILA \n\n";
                
                
                     muestraCola( q );
                 
            break;
            
			case 2:
            repetir = false;
            break;
            
            default:
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                    system("pause");
                    exit(0);
         }

       
        system("pause"); 
		 

    }while (repetir);
    
}


