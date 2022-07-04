#include <iostream>
#include <conio.h>
#include <stdlib.h>//Libreria para poder usar new y delete 
#define cls system("CLS");

FILE *doc;
int guardar();
int cargar();

using namespace std;

struct ICO{
	char clave[20];
	char nombre[30];
	int calificacion;
};

struct Nodo{
	ICO alumnos;
	Nodo *siguiente;
	int dato;
	
}   *primero, *ultimo;
//Insertar elementos a l cola 
void menu();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&,Nodo *&,ICO);
bool c_vacia(Nodo *);
void buscarNodo();
void modificarNodo();
void EliminarA(Nodo *&frente,Nodo *&fin,int &dato);


int main(){
	ICO alumnos;
	Nodo *frente=NULL;
	Nodo *fin=NULL;
	char opcion;
	  int dato;
  
	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		Nodo *aux=frente;
		switch(opcion){
			case '1':
				agregarDatos(alumnos);
				insertarDatos(frente,fin,alumnos);
				break;
			case '2':
				cout<<"CLAVE"<<"\tNOMBRE\t\t\t"<<"CALIFICACION "<<endl;
				while(aux !=NULL){
					cout<<aux->alumnos.clave<<"\t"<<aux->alumnos.nombre<<"\t\t\t"<<aux->alumnos.calificacion<<endl;
					aux=aux->siguiente;
				}
				break;
				
			case '3':
				cout << endl << endl << " BUSCAR UN ALUMNO POR CLAVE " << endl << endl;
				buscarNodo();
				break;
			
			case '4':	
				
				cout << endl << endl << " MODIFICAR LA CLAVE DE ALUMNOS " << endl << endl;
				modificarNodo();
				break;
				
			case '5':
				cout << endl << endl << " ELIMINAR ALUMNOS" << endl << endl;
				cout << endl << " Alumnos Eliminados " << endl << endl;
               delete aux;
			 while (frente!=NULL)
               {
              EliminarA(frente,fin,dato);
              cout<<"Se ha eliminado el dato: "<<dato<<"\n";
               }
				break;
				
			case '6':
				cout<<"\nCARGAR Y GUARDAR"<<endl;
				 cls
				 
                doc = fopen("ALUMNOS.txt","a+");
                 if(doc == NULL)
 				{
 				printf("\n ERROR\n ");	
  				printf("SE CERRARA EL PROGRAMA---INGRESA DATOS DE ALUMNO ");
 				} 
 				
 				fprintf(doc,"  CLAVE= ");
 				fprintf(doc,aux->alumnos.clave);
 				fprintf(doc,"  NOMBRE= ");
 				fprintf(doc,aux->alumnos.nombre);
 				fprintf(doc,"  CALIFICACION= ");
 				fprintf(doc,"   %d\n", aux->alumnos.calificacion);
 				
 				fclose(doc);
 				cls
 				cout<<"\nARCHIVO GUARDADO CON EXITO"<<endl;
				break;
			case '7':
				cout<<"\nCARGAR ARCHIVO"<<endl;
				
				doc = fopen("ALUMNOS.txt","r");
 				int c;
 
 				if(doc == NULL)
 				{
  				printf("ERROR EN EL ARCHIVO");
  				return 1;
 				}               
 
 				printf("\n\n\t--------Datos Cargados--------\n");
 			    printf("\t\n");
  				while((c = getc(doc)) != EOF)
 				{
 					
  				if(c == '\n\n')
  				{
   				printf(" ");
   				
  				}	else if(c == '='){
   				printf("=");
   				
  				}else{
   				printf("%c",c);
  				}
  
 				}
 				fclose(doc);
 				cout<<"               "<<endl;
				break;
			case '8':
				cout<<"\nSalio del programa..."<<endl;
				break;
			default:
				cout<<"\nOpcion invalida "<<endl;
				break;
		}
		cout<<"Presionar una tecla para continuar"<<endl;
		getch();
		system("cls");
	}while(opcion !='8');
	return 0;
}

void menu(){
	cout<<"MENU"<<endl
	    <<"1.Agregar datos del alumno"<<endl
	    <<"2.Mostrar datos de los alumnos"<<endl
	    <<"3.Buscar alumnos"<<endl
	    <<"4.Modificar"<<endl
	    <<"5.Eliminar"<<endl
	    <<"6.Guardar"<<endl
	    <<"7.Cargar"<<endl
	    <<"8.Salir del programa\n"<<endl
	    <<"Ingresar el numero de opcion que desea: ";
}

void agregarDatos(ICO &alumnos){
	cout<<"Ingresar clave del alumno: "; cin.getline(alumnos.clave,20,'\n');
	cout<<"Ingresar nombre del alumno: "; cin.getline(alumnos.nombre,30,'\n');
	cout<<"Ingresar calificacion: "; cin>>alumnos.calificacion;
}

//Insertando elementos a ala cola
void insertarDatos(Nodo *&frente, Nodo *&fin,ICO alumnos){
	Nodo *n_nodo=new Nodo();//declarando un nuevo nodo 
	
	n_nodo->alumnos=alumnos;//asignando al nuevo nodo el dato a insertar en la cola
	//siguiente apunta directamente hacia null
	n_nodo->siguiente=NULL;
	
	if(c_vacia(frente)){
		frente = n_nodo;//si la cola esta vacia frente = nuevo nodo
	}
	else{
		fin->siguiente=n_nodo;//si la cola no esta vacia 
	}
	
	fin=n_nodo;
}
//determina si la cola esta vacia 
bool c_vacia(Nodo *frente){
	//si frente igual a null cola vacia retornar true
	return (frente==NULL)? true : false;
}

void buscarNodo(){
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	char nodoBuscado =0 ;
	cout << " Ingrese la clave del alumno a Buscar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumnos.clave)
			{
				cout << "\n Alumno con la clave ( " << nodoBuscado << " ) Encontrado";
				encontrado = true;	
			}
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Alumno No Encontrado";
		}
	}else{
		cout << endl << " Alumno no encontrado verifica la clave " << endl << endl;
		
	}	
}


void modificarNodo(){
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	int NodoBuscado =0;
	cout << " Ingresa la clave a Buscar para Modificar: ";
	cin >> NodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumnos.clave){
				cout << "\n Alumno con la clave ( " << NodoBuscado << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Alumno: ";
				cin >> actual -> alumnos.clave;
				cout << "\n Dato Modificado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Alumno No Encontrado\n\n";
		}
	}else{
		cout << endl << " La lista se encuentra Vacia " << endl << endl;
	}		
}
  
void EliminarA(Nodo *&frente,Nodo *&fin,int &dato){
     
    Nodo *aux=frente;
    if(frente==fin){
        frente=NULL;
        fin=NULL;
    }else{
        frente=aux->siguiente;
    }
    delete aux;

}








