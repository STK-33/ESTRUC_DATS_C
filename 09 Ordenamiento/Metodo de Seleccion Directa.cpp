#include <iostream>
#include <conio.h>
#define MAX 50

using namespace std;

struct ordenamiento{
	int elem;
};
//metodos

void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrar(int, struct ordenamiento[]);
void selec(int, struct ordenamiento[]);
void incer();

void leerarray(int n, struct ordenamiento a[]){
	//ingresar los valores del arreglo
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el elemento:\n";
		cin>>a[i].elem;
	}
}

void burbuja(int n, struct ordenamiento a[]){
	int i, j;
	//aqui guardo los datos ordenados
	struct ordenamiento temp;
	
	//aplico burbuja
	for(i = 1; i < n; i++){
		for(j = n-1; j>=i; j--){
			//realizo la comparacion
			if(a[j-1].elem > a[j].elem){
				//aqui hacemos el intercambio de posiciones
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
	
}

void selec(int n, struct ordenamiento a[]){
	
	int i, j, k, aux ;
int vector[50] = {a[i].elem};
	//necesitamos recorrer el vector
	for(k = 0; k <=2; k++){
		i = k;
		aux = vector[k];
		for(j = k+1; j<=3; j++){
			if(vector[j] < aux){
				i = j;
				aux = vector[i];
			}
		}
		//intercambio
		vector[i] = vector[k];
		vector[k] = aux;
	}
	
	//imprimir
	for(i =0; i<=3; i++){
		cout<<" "<<a[i].elem<<"\n";
	}
	

	
}


void mostrar(int n, struct ordenamiento a[]){
	//imprimir elemento por elemento
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i].elem;
	}
}

void incer(){
    int numeros[5],aux,pos=0;
    std::cout<<"ingresa los datos a ordenar:\n";
    for (int i = 0; i < 5; i++)
    {
        std::cin>>numeros[i];
    }
    for (int i = 0; i < 5; i++)
    {
        pos=i;
        aux=numeros[i];
        while ( (pos>0) && (numeros[pos-1]>aux) )
        {
            numeros[pos]=numeros[pos-1];
            pos--;
        }
        numeros[pos]=aux;
    }
    std::cout<<"Ordenados por Incersion:\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout<<numeros[i]<<"\n";
    }
    system("pause");
    
} 


int main(){
	//menu
	int seleccion, l;
	
	do{
		system("cls");
		cout<<"\n Menu Ordenamiento \n";
		cout<<"\n1: Metodo Burbuja\n";
		cout<<"\n2: Metodo Seleccion Directa\n";
		cout<<"\n3: Metodo Insercion\n";
		cout<<"\n4: Salir\n";
		cout<<"\nIngrese la seleccion\n";
		
		cin>>seleccion;
		
		switch(seleccion){
			case 1:
				cout<<"\nOrdenando por Metodo Burbuja\n";
				int n;
			struct ordenamiento orden[MAX];
	
			cout<<"\nIngresa el limite del arreglo: \n";
			cin>>n;
			leerarray(n, orden);
			burbuja(n, orden);
			cout<<"\n El arreglo ordenado es: \n";
			mostrar(n, orden);
			cout<< endl;
		    getch();
				system("pause");				
				break;
			case 2:
				cout<<"\nOrdenando por Seleccion Directa\n";
				leerarray(n, orden);
				cout<<"\n El arreglo ordenado es: \n";
				selec(n, orden);
				system("pause");
				break;
			case 3:
				cout<<"\nOrdenando por Incersion\n";
				
				incer();
				
				system("pause");
				break;
			default:	
				cout<<"\nAdios Vuelve Pronto";
				break;
		}
	}while((seleccion > 0)&&(seleccion < 4));
}
