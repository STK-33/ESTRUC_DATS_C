//Ejemplo de una cola
//Primeras entredas
//Primeras salidas

#include<iostream>

using namespace std;

int main(){
	
	int num;
	
	//Estructura
	struct nodo{
		int nro; struct nodo *siguiente;
	};
	
	//Estructura de la cola
	struct cola{
		nodo *delante;
		nodo *atras;
	};
	
	return num;
}

//mostrar la cola
void muestraCola(struct cola q ){
	
	//nodo auxiliar
	struct nodo *aux;
	
	//siempre el nodo hasta adelante
	aux = q.delante;
	//cola vacia?
	while(aux != NULL){
		cout<<" "<<aux->nro;
		//recorrer la cola
		aux = aux->siguiente;
	}
};

//vaciar la cola
void vaciarCola(struct cola &q){
	//auxiliar para eliminar cada elemento 
	struct nodo *aux;
	//si esta vacia
	while(q.delante!=NULL){
		aux = q.delante;
		q.delante = aux->siguiente;
		delante(aux);
	}
	q.delante = NULL
	q.atras = NULL;
}

void menu(){
	cout<<"\nEjemplo de uan cola T_T\n"
	cout<<"1.-Encolar\n";
	cout<<"2.-Desencolar\n";
	cout<<"3.-Mostrar cola\n";
	cout<<"4.-Vaciar cola\n";
	cout<<"5.-Salir\n";
}

int main(){
	//Primero declaramos la cola
	struct cola q;
	
	//defino la cola con sus apuntadores
	q.delante = NULL;
	q.atras = NULL;
	
	//datos
	int dato;
	int op;
	//Funcion de pop o la cola
	int x; 
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Numero a encolar: \n";
				cin>>dato;
				encolar(q, dato);
				cout<<"\n Numero: "<<dato<<"encolado";
				break;
			
			case 2:
				x = desencolar(q);
				cout<<"\n Numero: "<<x<<"desencolado";
				break;
			
			case 3:
				cout<<"\n Mostrar cola: \n";
				//Saber que no este NULL
				if(q.delante != NULL)muestraCola(q);
				else cout<<"\n Cola vacia...\n"
				break;
				
			case 4:
				vaciaCola(q);
				cout<<"\n Se vacio la cola...\n";
				break;
		}
	}while(op!=5);
	
	return 0;
}
