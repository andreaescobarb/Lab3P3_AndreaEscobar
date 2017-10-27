#include <iostream>
using namespace std;
int menu();

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
