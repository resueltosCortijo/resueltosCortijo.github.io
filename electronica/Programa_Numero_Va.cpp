//Permitido uso publico y profesional
//Programa distribuido sin licencia

#include<iostream>

using namespace std;

int main(){
	
	double va;
	const double LSB = 0.00483789062;
	int NumVa;
	
	do{
	cout << "Introduce Va: "; cin >> va;
	NumVa = (va + LSB/2)/LSB;
	cout << "Numero Va: " << NumVa;
	cout << endl;
	cout << endl;
    }while(va != 9);
	
	return 0;
}
