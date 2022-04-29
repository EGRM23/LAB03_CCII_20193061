#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

int potencia(int num, int ptc) {
	int resul = 1;
	
	if (ptc != 0)
		for (int i = 1; i <= ptc; i++)
			resul *= num;
	
	return resul;
}

int main(int argc, char *argv[]) {
	int num, ptc;
	
	cout << "Numero: ";
	cin >> num;
	cout << "Potencia: ";
	cin >> ptc;
	cout << "Resultado: " << potencia(num, ptc);
	return 0;
}

