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
string fechas(int, int, int);


int main(){
	bool resp=true;
	vector<string> dates;
	vector<int> f;
	vector<string> ordenadas;
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
					//cout<<date.length();
				}
				
				string ano="";
				string mes="";
				string dia="";
				
				ano=date.substr(0,4);
				mes=date.substr(4,2);
				dia = date.substr(6,2);
				//cout<<ano<<" "<<mes<<" "<<dia<<endl;
				
				f.push_back(fecha);

				int ano1=atoi(ano.c_str());
				int mes1=atoi(mes.c_str());
				int dia1=atoi(dia.c_str());
			//	cout<<ano1<<mes1<<dia1<<endl;

				if(verifyyear(ano1,mes1,dia1)==false){
					cout<<"Lo sentimos fecha inexistente!!"<<endl;

				} else{
					cout<<fechas(ano1, mes1, dia1)<<endl;
					dates.push_back(fechas(ano1,mes1, dia1));
					cout<<dates.size();
					cout<<endl;
					cout<<"-----------------------------------------------------"<<endl;
					cout<<"Ingrese opcion"<<endl<<"1- Listar todo"<<endl<<"2- Listar ordenado"<<endl;
					int op;
					cin>>op;
					switch(op){
						case 1:{
							cout<<"-------------------------------"<<endl;
							for(int i=0;i<dates.size();i++){
								cout<<dates[i]<<endl;
							}
						
							break;
							   }
						case 2:{
							int m;
							cout<<"--------------------------------"<<endl;
							for(int i=0;i<f.size();i++){

									if(f[i]>f[i+1]){
										m = f[i+1];
										f.at(i+1)= f[i];
										f.at(i) = m;
										cout<<"Entra"<<endl;
									}
								
							}

							for(int i=0;i<f.size();i++){
								cout<<f[i]<<endl;
							}

							break;
							   }
					}

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
		cout<<"Entra a fecha negativa"<<endl;
		verify=false;
	}else{

		if(ano%4==0){   //verifico ano bisiesto
			if(mes==2){
				if(dia==29){
					verify==true;
				}
			}
			else{
				if(mes == 1||mes == 3 || mes == 5|| mes ==7||mes == 8|| mes == 12){
					if(dia<32){
						verify = true;
					}
				}
				if(mes ==4|| mes ==6|| mes == 9||mes == 11){
					if(dia<31){
						verify = true;
					}
				}
			}
		} 
	
		else{
			if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){  //verifico meses con 31 dias
				if(dia<32){
					verify=true;
				}
			}	

			if(mes == 2){					//veriifico febrero
				if(dia<28){
					verify = true;
				}
			}
			if(mes==4||mes==6||mes==9||mes==11){ //verifico meses con 30 dias
				if(dia<31){
					verify=true;
				}
			}
		}
	}
	return verify;
}


string fechas(int ano, int mes, int dia){
	string day="";
	string month="";
	string year="";
	
	stringstream wholedate;
	string fechacompleta;

	stringstream ss;
	ss.str("");
	ss<<ano;
	string yyyy = ss.str();
	string century = yyyy.substr(0,2);
	string ycent = yyyy.substr(2,2);
	
	int j = atoi(century.c_str()); //centuria
	int k = atoi(ycent.c_str());  //ano de la centuria

	//cout<<century<<" "<<ycent<<endl;
	int d=dia;
	int m = mes;

	int parte1 = (m+1)*2.6;

	int parte2 = k/4;

	int parte3 = j/4;

	int h = d+parte1+k+parte2+parte3-(2*j);

	if(h%7==0){
		day="Sabado ";
	} else if(h%7==1){
		day ="Domingo ";
	} else if(h%7==2){
		day = "Lunes ";
	} else if(h%7==3){
		day = "Martes ";
	} else if(h%7==4){
		day = "Miercoles ";
	} else if(h%7==5){
		day = "Jueves ";
	} else if(h%7==6){
		day = "Viernes ";
	} 
	
	if(mes ==1){
		month = "Enero";
	} else if(mes==2){
		month = "Febero";
	} else if(mes == 3){
		month = "Marzo";
	} else if(mes == 4){
		month = "Abril";
	} else if(mes ==5 ){
		month = "Mayo";
	} else if(mes == 6){
		month = "Junio";
	} else if(mes ==7){
		month = "Julio";

	} else if(mes == 8){
		month = "Agosto";
	} else if(mes == 9){
		month = "Septiembre";
	} else if(mes == 10){
		month = "Octubre";

	} else if(mes == 11){
		month = "Noviembre";
	} else if(mes == 12){
		month = "Diciembre";
	}
//	cout<<day<<" "<<d<<" de "<<month<<" de " <<ano<<endl;
	wholedate.str("");
	wholedate<<day<<" "<<d<<" de "<<month<<" de "<<ano;

	fechacompleta=wholedate.str();

	return fechacompleta;
}








