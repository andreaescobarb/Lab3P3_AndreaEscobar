#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;
int menu();
void printMatriz(int**, int);
int*** crearMatriz(int);
int** Matrix(int);
bool verifyyear(int, int, int);

int main(){
	bool resp=true;
	while(resp){
		switch(menu()){
			case 1:{
				

				break;
				   }

			case 2:{

				break;
				   }

			case 3:{
				cout<<"Ingrese fecha en el formato YYYYMMDD"<<endl;
				int fecha;
				cin>>fecha;
				stringstream ss;
				ss<<fecha;
				string date = ss.str();
				

				while(date.length()!=8){
					cout<<"Lo sentimos, fecha invalida"<<endl<<"Ingrese fecha de nuevo"<<endl;
					ss.str("");
					cin>>fecha;
					ss<<fecha;
					date=ss.str();
					cout<<date.length();
				}
				
				string ano="";
				string mes="";
				string dia="";
				
				ano=date.substr(0,4);
				mes=date.substr(4,2);
				dia = date.substr(6,2);
				cout<<ano<<" "<<mes<<" "<<dia<<endl;
				

				int ano1=atoi(ano.c_str());
				int mes1=atoi(mes.c_str());
				int dia1=atoi(dia.c_str());
				cout<<ano1<<mes1<<dia1<<endl;

				if(verifyyear(ano1,mes1,dia1)==false){
					cout<<"Lo sentimos fecha inexistente"<<endl;

				}
				
				break;
				   }

			case 4:{
				resp = false;
				break;
				   }
		}
	}

	return 0;
}

int menu(){
	cout<<"			MENU"<<endl<<"Ingrese una opcion"<<endl<<"1- Ejercicio1 Poda y Busca"<<endl<<"2- Ejercicio2 (Teorema de Ruffini)"<<endl<<"3- Ejercicio 3 (Fechas)"<<endl<<"4- Salir"<<endl;
	int op;
	cin>>op;
	return op;
}

int*** crearMatriz(int size){
	int*** matriz = new int**[size];
	for(int i=0;i<size;i++){
		matriz[i] = new int *[3];
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<3;j++){
			matriz[i][j] = new int[size];
		}
	}
	return matriz;
}

/*int** Matrix(int size){
	int** m = new int[size];
	for(int i=0;i<size;i++){
		m[i] = new temp[size];
		for(int j=0;j<size;j++){
			
		}
	}
}

string fechas()const{
	stringstream ss;
	int ano;
	cout<<"Ingrese ano"<<endl;
	cin>>ano;
	int mes;
	cout<<"Ingrese mes"<<endl;
	cin>>mes;
	int dia;
	cout<<"Ingrese dia"<<endl;
	cin>>dia;
	
}*/

bool verifyyear(int ano, int mes, int dia){
	bool verify=false;
	if(ano<0||mes<1||dia<1){ //verifico que no sea un numero negativo
		verify=false;
	}

	if(ano%4==0){   //verifico ano bisiesto
		if(mes==02){
			if(dia==29){
				verify==true;
			}
		}
	} 
	
	else{
		if(mes==1||mes==3||mes==4||mes==7||mes==8||mes==10||mes==12){  //verifico meses con 31 dias
			if(dia<32&& dia>0){
				verify=true;
			}
		}	

		if(mes == 2){					//veriifico febrero
			if(dia<28&&dia>0){
				verify = true;
			}
		}
		if(mes==4||mes==6||mes==9||mes==11){ //verifico meses con 30 dias
			if(dia<31&&dia>0){
				verify=true;
			}
		}
	}
	return verify;
}





