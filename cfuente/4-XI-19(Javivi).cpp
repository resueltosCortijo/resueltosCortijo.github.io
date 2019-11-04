/***************************************************************************/
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
// CURSO 2019-2020
//
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
// GRUPO C
//
// EXAMEN PR�CTICO 1 - NOVIEMBRE 2019
// 
// �RELLENAD LOS SIGUIENTES DATOS!
//
// Apellidos: Exp�sito Mart�nez
// Nombre:  Javier
//
// GRUPO DE PR�CTICAS: 1 
// EJERCICIO: 1 
//
// Fecha: 4-11-2019
// 
// Ordenador (ver etiqueta): ei140204 Isla 3 PC 3
//
/*********************************************************************/

#include<iostream>
#include<iomanip>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	int suma=0;
	int num=0;
	int num_alejado=0;
	int dist=0;
	bool encontrado=false;
	string continua;
  do{
     cout<<"Introduzca un �n�mero mayor o igual a 0"<<endl;
	  cin>>num;
	  for(int i=0;i<num && encontrado==false;i++){
	     for(int j=1;j<num && encontrado==false;j++){
            if((num-i)%j==0){
               suma=suma+j;
              if(suma==num-i){
                 encontrado=true;
               }
            }
        }
        if(encontrado==false){
        suma=0;
        }
     }
     
      if(num-suma>dist){
         num_alejado=num;
         dist=num-suma;
      }
     cout<<"El numero perfecto mas cercano al numero introducido es "<<suma<<endl;
     suma=0;
     encontrado=false;
     cout<<"Introduzca si quiere continuar SI o NO"<<endl;
     cin>>continua;
   }while(continua =="SI");
   
   cout<<"El numero mas alejado es: "<<num_alejado;
   
	return 0;
}

/***************************************************************************/
/***************************************************************************/
