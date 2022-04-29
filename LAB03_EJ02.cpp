#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//20193061

bool EsBisiesto(int a){
	if(a%4 == 0)
		if(a%100 == 0 && a%400 != 0)
			return false; //No es bisiesto
		else
			return true; //Si es bisiesto
	else
		return false; //No es bisiesto
}

int main(int argc, char *argv[]) {
	int a;
	
	cout << "Año? ";
	cin >> a;
	
	if (EsBisiesto(a) == true)
		cout << "Es bisiesto";
	else
		cout << "No es bisiesto";
	
	return 0;
}

