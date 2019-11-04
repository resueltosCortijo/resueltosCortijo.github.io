//¿?
//1º Ingeniería Informática C 
//5 de noviembre de 2019 

#include <iostream> 
#include <cmath>
using namespace std; 


//Esta función devuelve el numero n si es divisor de m y 0 si no. 
int EsDivisor (int n, int m) {
   if ( m % n != 0 ) n = 0;
 return n;   
}

int SumaDivisores ( int m ) {
   int suma = 0; 
   for ( int n = 1; n <= m/2 ; n++ ) {
    suma = suma + EsDivisor (n, m);   
   }
 return suma;  
}

bool EsPerfecto ( int m ) {
 bool esPerfecto = SumaDivisores(m) == m; 
 return esPerfecto;   
}

int main () {
   
   //ENTRADA DE DATOS 
   
   
   int numero, perfecto, distancia; 
   
   cout << "Introduzca un número positivo: "; 
   cin >> numero; 
   
   perfecto = numero; 
   distancia = 0; 
   bool esPerfecto = false; 
   
   do {
      //Si no encuentra uno mayor, busca uno menor con esa distancia. 
      esPerfecto = EsPerfecto(perfecto + distancia); 
      if (esPerfecto) perfecto = perfecto + distancia; 
      if (!esPerfecto) {
      esPerfecto = EsPerfecto(perfecto - distancia); 
      if (esPerfecto) perfecto = perfecto - distancia;
      }
      distancia++; 
   } while (!esPerfecto); 
   
   
   
   cout << "El número perfecto más cercano a " << numero << " es " << perfecto;  
   

return 0; 
}
