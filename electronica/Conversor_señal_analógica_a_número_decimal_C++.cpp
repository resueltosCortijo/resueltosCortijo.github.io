//Permitido uso publico y profesional
//Programa distribuido sin licencia

#include<iostream>

using namespace std;

int main(){
	
	double va, lsb;
	const double LSB = 0.00483789062;
	int NumVa;
	
cout << "Introduce lsb: "; cin >> lsb;	
	do{
	cout << "Introduce Va: "; cin >> va;
	NumVa = (va + lsb/2)/lsb;
	cout << "Numero Va: " << NumVa;
	cout << endl;
	cout << endl;
    }while(true);
	
	return 0;
}
