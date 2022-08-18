#include <iostream>//input--- out put
#include <cstdlib>  // para las  funcines gestión de memoria dinámica, control de procesos 
#include <stdlib.h>  // tiene dos funciones útiles para hacer búsqueda y ordenamiento de datos de cualquier tipo.
#include <string.h> // funciones cadenas unir comparar
#include <conio.h> // getch util
#include<fstream>  // para entrada y salida de ficheros 
#include <cstdio>  // funciones de manipulacion de entrada, salida en ficheros (abrir, cerrar, etc. )
#include <ctime>// libreria para obtener fecha y hora local
FILE *doc;  // para el archivo  txt

char pass[10];
int correct;
int intento; //contador
char contrasena[]="abc123"; //contraseña abc123

int horas, minutos, segundos, dia, mes, ano;   //variables para la fecha

int saldo = 6000; // saldo 
int ingreso; //ingresos
int retiro;  // retiros

<<<<<<< HEAD
=======
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <conio.h> // getch util

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
>>>>>>> 40b20911eb84668d04abee7974556c32b5cd8636
using namespace std;

//funciones 
void menuPrincipal();
void menuContrasena();
void menuBanco();
void UltMov();
void impconsola();




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
    cout << "                    Bienvenido***UTC BANK   \n";
    cout << "\t--------------------------------------------  \n";
        cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1. Inserta tu NIP" << endl;
        cout << "\t2. SALIR" << endl;
        
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuContrasena();
            break;

        case 2:
        	 cout << "\n\tGRACIAS POR VISITARNOS VUELVE PRONTO ......  ";
            repetir = false;
            break;
        }
    } while (repetir);
}

  
void menuContrasena()
{
<<<<<<< HEAD
 
    system("cls"); //limpiamos la consola
    
    intento=0;
   
    cout << endl;
    
	gets(pass); printf("\n");
    if (strcmp(pass,contrasena)==0) correct=1;
    while ((correct==0)&&(intento<3))
    {
        intento++;
        printf("Introduce la Contrasena. %i intento: ", intento); gets(pass); printf("\n");
        if (strcmp(pass,contrasena)==0) correct=1;
    }
    if (correct==0){
    	
    	cout << endl;
    	cout<<"Se han excedido el numero de intentos. Busca a un Asesor"<<endl;
    	cout << endl;
    	cout<<"CAJERO BLOQUEADO"<<endl;
    	cout << endl;
    	 exit(1);
	} 
    else
        {
            
            menuBanco();
      }
   }
   
void menuBanco()
{
		
  int opcion;
    bool repetir = true;

   do
=======
	
  int opcion;
    bool repetir = true;
    
    system("cls"); //limpiamos la consola
    
   vector<string> clientes;
    vector<string> contrasenas;

    // para añadir clientes
    clientes.push_back("admin");
    // para añadir contraseña alfanumerica
    contrasenas.push_back("Abc123");
    
    string cliente, nip;

    int contador = 0;
    bool ingresar = false;

    do
    {
        system("cls");
        cout << endl;
        cout << "\t\t\tLOGIN DE CLIENTES" << endl;
        cout << "\t\t\t------------------" << endl;
        cout << endl;
        cout << "\nNombre del Cliente: ";
        cout << endl;
    
        cin >> cliente;

        char caracter;

        cout << "\nNIP : ";
        
        caracter = getch();  //para tapar la contraseña con ****** 

        nip = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                nip.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (nip.length() > 0)
                {
                    cout << "\b \b";
                    nip = nip.substr(0, nip.length() - 1);
                }
            }

        caracter = getch();
        }

        for (int i = 0; i < clientes.size(); i++)
        {
            if (clientes[i] == cliente && contrasenas[i] == nip)
            {
                ingresar = true;
                break;
            }
        }

        if (!ingresar)
        {
        	system("cls");
            cout << "\n\n\tEl Nombre de clinete y/o NIP son incorrectos----(Solo cuentas con 3 intentos)" << endl;
            cout << endl;
            cin.get();
            contador++;
            system("pause"); 
        }

    } while (ingresar == false && contador < INTENTOS);

    if (ingresar == false)
    {
    	system("cls");
        cout << "\n\tNumero maximo de intentos. " << endl;
         cout << "\n\tCAJERO BLOQUEADO --- BUSCA A UN ASESOR . " << endl;
          cout << "\n\t------------------  -  ------------------" << endl;
          cout << "\n\t----------------  -----  ----------------" << endl;
          cout << "\n\t--------------  ---   ---  --------------" << endl;
          cout << "\n\t------------  -------------  ------------" << endl;
          cout << "\n\t---------  --------   -------  ----------" << endl;
          cout << "\n\t-------  ----------   ---------  --------" << endl;
          cout << "\n\t-----  ------------   -----------  ------" << endl;
          cout << "\n\t-----------------------------------------" << endl;
    }
    else
    {
        cout << "\n\n\tAcceso Correcto" << endl;
          system("pause"); 
         
        //Aquí empieza el menu del sistema bancario ..................................................................
        
         do
>>>>>>> 40b20911eb84668d04abee7974556c32b5cd8636
    {
        system("cls");

	cout<<"\n\t SISTEMA BANCARIO \n\n";
	cout << endl;
    cout<<" 1. Consultar Saldo Disponible  "<<endl;
    cout<<" 2. Retirar Efectivo            "<<endl;
    cout<<" 3. Depositar                   "<<endl;
    cout<<" 4. Ultimos Movimientos de la Cuenta  "<<endl;
    cout<<" 5. Regresar a menu principal                   "<<endl;
	cout << endl;	
    cout<<"\n Ingrese Opcion: ";
        cin >> opcion;   
        switch(opcion)
        {
            case 1:
             // Mostrar saldo
             cout << endl;
       		 cout << "Saldo Disponible $" << saldo << endl;	 
			 cout << endl;
			  UltMov();
            break; 
                  
            case 2:
        	// retirar
            
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
                // Restamos a el saldo  existente
                saldo = saldo - retiro;
                cout<<"Saldo Disponible $"<<saldo<<"\n";
                 UltMov();
            }
        
            break;
            
            case 3:
    		
			cout<<"¿Cuanto dinero deseas ingresar? ";
        	cin>>ingreso;
       
         	if(ingreso>=10001){
            cout<<"Solo puedes depositar un maximo de $10,0000 , tienes "<<saldo<<"\n";
        	}else{
            saldo+=ingreso;
            cout<<"Saldo a favor $"<<saldo<<"\n";
             UltMov();
        	}
         
            break;
            
            case 4:
			// mando a llamar void de consulta del txt
                 impconsola();
               
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
<<<<<<< HEAD

=======
 
        
    }

    cin.get();

      
>>>>>>> 40b20911eb84668d04abee7974556c32b5cd8636
      
}

void UltMov()
{
	ofstream Guardar; // clase que para crear la instancia fich para escribir en el fichero txt
	ifstream Leer;        //clase que para crear la instancia fich  leer el fichero. 
	
	Guardar.open ("Historial de Movimientos.txt",ios::app);
   
    Leer.open("Historial de Movimientos.txt");
	
	if(Leer.is_open()){
		
	//para la fecha --------------------------------------------------------------------
     
    time_t now;  // time_t  tipo de tiempo aritmético
 
    // para la hora al momento de consultar--- la hora actual
   
    time(&now); // time() para devolver la hora actual del sistema como un valor time_t
 
    // localtime convierte el valor de time_t a la hora del calendario y  devuelve un puntero a una estructura tm con sus miembros
    
    struct tm *local = localtime(&now);// rellenado con los valores correspondientes
 
    horas = local->tm_hour;         // para obtener horas a partir de la medianoche (0-23)
    minutos = local->tm_min;        // para obtener minutos pasados después de la hora, para tener 59 minutos nadamas(0-59)
    segundos = local->tm_sec;        // para obtener segundos pasados después de un minuto (0-59)
 
    dia = local->tm_mday;            // para obtener el día del mes del(1 a 31)
    mes = local->tm_mon + 1;      // para obtener el mes del año (0 a 11)
    ano = local->tm_year + 1900;   // para obtener el año desde 1900 
    //mprimimos
 	Guardar<<"\t--------UTC BANK--------\n";
    // imprime la hora local
    if (horas < 12) {    // si es antes del mediodia es am
        Guardar<<"Hora: "<< horas<< minutos<< segundos<<"am          ";
    }
    else {    // si es Después de medio dia es pm
        Guardar<<"Hora: "<<horas - 12<<":"<< minutos<<":"<< segundos<<"pm   ";
    }
 
    // imprime la fecha local y el cajero 
    Guardar<<"Fecha: "<< dia <<"/"<< mes<<"/"<< ano<<"   ";
    Guardar<<"Cajero: "<<"STK-33\n";
	//  se imprime en el txt las variables correspondientes a saldo................................................
	Guardar<<"\nUTC NIZA";
	Guardar<<"\nCDMX***************33";
	Guardar<<"\n"<<"Deposito :"<<ingreso<<"\n";
	Guardar<<"Saldo Actual :"<< saldo<<"\n";
	Guardar<<"Retiro :"<<retiro<<"\n";
		cout<<"\n\t\n\t Cargando .............";
		cout<<endl;
    	Guardar.close();
    	Leer.close();
    	system("pause");
    	system("cls");
		fflush(stdin);//limpieza de buffer (Saltos de linea y espacios)
    	
	}else{
		cout<<"\n\t   Error de Sistema busca Ayuda   ";
	}
}

<<<<<<< HEAD
void impconsola(){
	system("cls");
 cout<<"\n\t---------------------------------"<<endl;
 cout<<"\n\t   HISTORIAL DE MOVIMIENTOS     "<<endl;
 cout<<"\n\t---------------------------------"<<endl;
 
 doc = fopen("Historial de Movimientos.txt","r"); //r --leyendoo y escribiendo
 int c;
 
 if(doc == NULL)
 {
  printf("Cuenta sin Movimientos");
  
 }               
 
 printf("\n\t--------Ultimos Movimientos--------\n");
 printf("\n");
 while((c = getc(doc)) != EOF)
 {
  if(c == '\n')
  {
   printf("\n");
  }else if(c == '='){
   printf("\n");
  }else{
   printf("%c",c);
  }
  
 }
 fclose(doc);
 
=======
 cout<<"\n\tEn proceso ya csi se acaba !"<<endl;
    

>>>>>>> 40b20911eb84668d04abee7974556c32b5cd8636
}
   
