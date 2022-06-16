#include <iostream>
using namespace std;
int main()
{
  int numero;
  cout << "Indique un Numero: ";
  cin >> numero;
  if ( numero % 2 == 0)
      cout << numero << " es par.";
  else
      cout << numero << " es impar.";
  return 0;
}

