/***************************************************************************/
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// CURSO 2019-2020
//
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
// GRUPO C
//
// EXAMEN PRÁCTICO 1 - NOVIEMBRE 2019
// 
// ¡RELLENAD LOS SIGUIENTES DATOS!
//
// Apellidos: ¿?
// Nombre:  ¿?
//
// GRUPO DE PRÁCTICAS: 1
// EJERCICIO: 2
//
// Fecha: 4/XI/2019
// 
// Ordenador (ver etiqueta): ¿?
//
/*********************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main() {
   
   cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

   int intervalo1, intervalo2, n_de_n_perfectos, var_intercambio, numero,
       divisor, suma, ndenperf_interv_con_mas=0;
   char opcion;
   string inter_con_mas_perf, separador="====================================";

   do {
      
      //entrada (apartado 1)
      cout<<endl<<"Introduzca un entero positivo ";
      do {
      cin>>intervalo1;
      }while (intervalo1<=0);
      
      cout<<"Introduzca otro entero positivo ";
      do {
      cin>>intervalo2;
      }while (intervalo2<=0);
      
      
      //calculos y salidas (apartado 1)
      if (intervalo1>intervalo2) { //si el intervalo introducido fuese [8,2] lo 
                                   //transformo en [2,8], para que el numero mas 
                                   //chico sea el primero
       var_intercambio=intervalo1;
       intervalo1=intervalo2;
       intervalo2=var_intercambio;  
      }
      
      n_de_n_perfectos=0;
      cout<<"Numeros perfectos entre "<<intervalo1<<" y "<<intervalo2<<":";
      for (int i=intervalo1; i<=intervalo2; i++) {
         
         suma=0;
         numero=i;
         divisor=floor(numero/2);
         while (divisor>=1) { //suma de los divisores de un numero
            if ((numero%divisor==0)&&(divisor!=numero))
               suma+=divisor;
            divisor--;
         }
         
         if (suma==numero){
            n_de_n_perfectos++;
            if (n_de_n_perfectos>=2)
               cout<<",";
            cout<<" "<<suma;
         }
      }
      if (n_de_n_perfectos==0)
         cout<<" ninguno";
         
         
      //calculos (apartado 3)   
      if (n_de_n_perfectos >= ndenperf_interv_con_mas) {
         ndenperf_interv_con_mas=n_de_n_perfectos;
         inter_con_mas_perf='['+to_string(intervalo1)
                            +','+to_string(intervalo2)+']';
      }
      
      
      //entrada (apartado 2)
      cout<<endl<<"Quiere volver a empezar? [S/N] ";
      do {
         cin>>opcion;
         opcion=toupper(opcion);
      } while ((opcion!='Y')&&(opcion!='S')&&(opcion!='N'));

   } while ((opcion=='S')||(opcion=='Y'));
   
   //salida (apartado 3)
   cout<<endl<<separador<<endl;
   cout<<"El intervalo con mas numeros perfectos de los que ha introducido es "
       <<inter_con_mas_perf<<"."<<endl<<"Tiene "<<ndenperf_interv_con_mas
       <<" numeros perfectos";
   
   
	return 0;
}

/***************************************************************************/
/***************************************************************************/
