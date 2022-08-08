
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
using namespace std;

//funciones 
void menuPrincipal();
void menuContrasena();
void menuUltMov();

 double saldo = 5000; // saldo 

int main()
{
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
		 cout << endl;
    cout << "\t--------------------------------------------  \n";
    cout << "               Bienvenido al Cajero Automatico  \n";
    cout << "\t--------------------------------------------  \n";
        cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1. Inserta NIP de seguridad" << endl;
        cout << "\t2. SALIR" << endl;
        
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuContrasena();
            break;

        case 2:
        	 cout << "\n\tGRACIAS POR VITARNOS VUELVE PRONTO ......  ";
            repetir = false;
            break;
        }
    } while (repetir);
}
  
void menuContrasena()
{
	
  int opcion;
    bool repetir = true;
    system("cls");
    // nip correcto
    const string nip = "abc123";
    cout << endl;
    cout << "------------------------  \n";
    cout << "  INGRESA TU NIP \n";
    cout << "------------------------  \n";
    cout << endl;
    
    string contra = "";
    cin >> contra;
    if (contra == nip)
    {
         // Si llegamos hasta aquí, todo bien por el momento
    	cout << "\nBienvenido al $$$$$$\n";
    	 cout << endl;
    	system("pause");
    }else
            {
            	cout << endl;
		cout << "NIP incorrecto vuelve a intentar";
		 cout << endl;
        // pausamos un momento 
         system("pause");
         menuContrasena();
            }
   
      
    do
    {
        system("cls");

	cout<<"\n\t SISTEMA BANCARIO \n\n";
	cout << endl;
    cout<<" 1. Consultar Saldo Disponible  "<<endl;
    cout<<" 2. Retirar Efectivo            "<<endl;
    cout<<" 3. Depositar                   "<<endl;
    cout<<" 4. Mostrar Ultimos Movimientos "<<endl;
    cout<<" 5. Regresar a menu principal                   "<<endl;
	cout << endl;	
    cout<<"\n Ingrese Opcion: ";
        cin >> opcion;   
        switch(opcion)
        {
            case 1:
             // Mostrar fondos
             cout << endl;
       		 cout << "Saldo Disponible $" << saldo << endl;	 
			 cout << endl;
            break; 
                  
            case 2:
        	// retirar
            double retiro;
            cout << endl;
            cout << "Ingrese la cantidad a retirar: " << endl;
            cin >> retiro;
            // Comprobar si puede retirar
            if (retiro > saldo || retiro >= 9001 || retiro <= 0 )
            {
            	 cout << endl;
               cout<<"Solo puedes retirar un maximo de $9000, tienes $"<<saldo<<"\n";
            }
            else
            {
                // En caso de que sí pueda retirar
                cout << "Ha retirado $" << retiro << endl;
                 cout << endl;
                // Restamos los fondos existentes
                saldo = saldo - retiro;
                cout<<"Saldo Disponible $"<<saldo<<"\n";
            }
        
            break;
            
            case 3:
    		double ingreso;
			cout<<"Cuanto dinero vas a ingresar? ";
        	cin>>ingreso;
       
         	if(ingreso>=10001){
            cout<<"Solo puedes depositar un maximo de $10,0000 , tienes "<<saldo<<"\n";
        	}else{
            saldo+=ingreso;
            cout<<"Saldo a favor $"<<saldo<<"\n";
        	}
         
            break;
            
            case 4:
			// falta hacer los ultimos 30 movimientos imprimendolos en una lista  
                 menuUltMov();
            break;
            
            
			case 5:
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

void menuUltMov()
{

cout<<"\n\tEn proceso y mantenimiento ..!"<<endl;

}
   
