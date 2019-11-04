/*************************************************************************/
// ¿?, examen C1
//
// DNI: ¿?
//
// 05 11 2019
//
/*************************************************************************/

/*
  Este programa encuentra el número perfecto más cercano al introducido (cuyos
  divisores tienen como suma al mismo número).
  
  Cada vez que se ejecuta pregunta si se quiere seguir introduciendo numeros
  
  Para todos los números introducidos dirá cuál es el más alejado de su número
  perfecto
  
*/

#include <iostream>
#include <iomanip>

using namespace std;

/***************************************************************************/
// Función que devuelve si un número es número perfecto //PRE: numero>0
bool EsPerfecto(int numero) {
	int suma_divisores = 0;
	double tope = numero/2.0+1; // para no buscar divisores que no hay 
	
	for (int candidato=1; candidato<tope; candidato++) {
		
		if (numero%candidato == 0)
			suma_divisores += candidato; // si candidato es divisor de numero
	}
	bool es_perfecto = (suma_divisores == numero);
	return es_perfecto;
}

/**************************************************************************/
/**************************************************************************/


int main () {
	
	
	// Apartado 2: Hacer un bucle que pregunte cada vuelta si se quiere seguir 
	// 	introduciendo números: Se encerrará el apartado 1 en un bucle 
	// 	que al terminar cada vuelta pregunte si se quiere seguir
	
	
	// Bucle de calcular perfectos cercanos
	bool seguir_calculando_perfectos = true;
	
	// Apartado 3: cual es el más alejado de su número perfecto?
	// o sea, cual tiene la mayor distancia? Se guardará el número cuya
	// distancia sea la mayor de momento, y el numero al que corresponde.
	
	int distancia_del_mayor = -1; // Deben ser declaradas fuera del bucle while
	int numero_a_mayor_distancia = -1;
	
	while (seguir_calculando_perfectos) {
		
		// Apartado 1: El número perfecto más cercano al num introducido
		
		// Entrada de datos: número entero positivo
		int num_entrada;
		do {
			cout << "Introduzca un numero entero mayor que 0: ";
			cin >> num_entrada;
		} while (num_entrada <= 0);
		
		// Cálculos 
		bool perfecto_encontrado = false;
		int distancia = 0;
		
		
		while (!perfecto_encontrado) {
			
			int perfecto_superior = num_entrada + distancia;
			int perfecto_inferior = num_entrada - distancia;
			
			if (EsPerfecto(perfecto_superior)) {
				
				perfecto_encontrado = true;
				cout << "El numero " << perfecto_superior << " es el perfecto"
				     << " mas cercano." << endl;
				     
					// Guardar el número y la distancia en el caso de que sea
					// la distancia máxima
					if (distancia > distancia_del_mayor)
				   	numero_a_mayor_distancia = num_entrada;
				   	distancia_del_mayor = distancia;
				     
			}  // Si ese numero es perfecto, no es necesario comprobar el otro
			
			else if (perfecto_inferior>0) { // si el inferior es positivo,puede ser
				if (EsPerfecto(perfecto_inferior)) {
					perfecto_encontrado = true;
					cout << "El numero " << perfecto_inferior << " es el perfecto"
					     << " mas cercano." << endl;
					     
					// Guardar el número y la distancia en el caso de que sea la
					// distancia máxima
					if (distancia > distancia_del_mayor)
						numero_a_mayor_distancia = num_entrada;
						distancia_del_mayor = distancia;
					
				}
			}
			distancia++;
		}
	
	// Preguntar si usuario desea seguir calculando perfectos
	char respuesta_usuario;
	bool respuesta_admisible;
	
	do {
		cout << endl << endl;
		cout << "Seguir calculando perfectos? [s/n]: ";
		cin >> respuesta_usuario;
		respuesta_admisible = (toupper(respuesta_usuario) == 'S' || 
										toupper(respuesta_usuario) == 'N');
										
	} while (!respuesta_admisible);
	
	// cambiar la variable del bucle según la respuesta del usuario
	if (respuesta_usuario == 'N' || respuesta_usuario == 'n')
		seguir_calculando_perfectos = false;
		
	
	}  // Fin del bucle while (seguir_calculando_perfectos)
	
	
	// Salida de datos: el más alejado de su número perfecto
	cout << endl << "----------Estadistica:-----------" << endl;
	cout << "De los numeros introducidos, el de mayor distancia a su perfecto"
		  << " es: " << numero_a_mayor_distancia << endl << endl;
	
	
	return 0;
}  // FIN de la función main 
