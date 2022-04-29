#include <iostream>
using namespace std;

//EDUARDO GERMAN RUIZ MAMANI
//CUI 20193061

bool EsBisiesto(int a) {
	if(a%4 == 0)
		if(a%100 == 0 && a%400 != 0)
		return false; //No es bisiesto
		else
			return true; //Si es bisiesto
		else
			return false; //No es bisiesto
}

bool Validacion(int d,int m,int a) {
	if (m > 0 && m <= 12){
		if (d > 0 && d <= 31){
			if (m == 4 || m == 6 || m == 9 || m == 11){
				if (d != 31)
					return true;
				else
					return false;
			} else if(m == 2){
				if (d == 30 || d == 31)
					return false;
				else if (EsBisiesto(a) == true || d == 29)
					return false;
				else
					return false;
			} else
				return true;
		} else
		   return false;
	} else
		return false;
}

void LeerFecha(int &d,int &m,int &a) {
	do {
		cout << "Año? ";
		cin >> a;
		cout << "Mes? ";
		cin >> m;
		cout << "Dia? ";
		cin >> d;
		
		if (Validacion(d,m,a) == false){
			cout<<"FECHA INVALIDA! Ingrese los datos de nuevo"<<endl;
			cout<<endl;
		} else
			break;
		
	} while (true);
}

int DiasDelMes(int m, int a) {
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	else if (m == 2){
		if(EsBisiesto(a) == 1)
			return 29;
		else
			return 28;
	} else
		return 31;
}

void Edad(int &dE, int &mE, int &aE) {
	
	int d, m, a, dA, mA, aA;
	
	cout << "Fecha de Nacimiento: " << endl;
	LeerFecha(d, m, a);
	cout << "Fecha Actual: " << endl;
	LeerFecha(dA, mA, aA);
	
	if (aA == a) {
		if (mA == m)
			dE = dA - d;
		else {
			if (mA - 1 != m)
				mE = mA - m - 1;
			
			if (dA >= d) {
				mE++;
				dE = dA - d;
			} else
				dE = DiasDelMes(m, a) - d + dA;
		}
	} else {
		if (aA - 1 != a)
			aE = aA - a - 1;
		
		if (mA > m) {
			aE++;
			if (dA >= d) {
				mE++;
				dE = dA - d;
			}
		} else if (mA == m)
			if (dA >= d) {
				aE++;
				dE = dA - d;
			}
		else {
			mE = 12 - m + mA - 1;
			if (dA >= d) {
				mE++;
				dE = dA - d;
			} else
				dE = DiasDelMes(m, a) - d + dA;
		}
		
		if (mE == 12)
			aE++;
		
	}
}

int main(int argc, char *argv[]) {
	int dE = 0, mE = 0, aE = 0;
	
	Edad(dE, mE, aE);
	
	cout << "Edad actual: " << aE << " años, " << mE << " meses y " << dE << " días.";
	
	return 0;
}

