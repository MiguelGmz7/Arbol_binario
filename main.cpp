#include <iostream>
using namespace std;

class Nodo{
	public:
	int elemento;
	Nodo *izq,*der;
};

Nodo *ABB = NULL;

Nodo *crearNodo(int x){
	Nodo *aux = new Nodo();
	
	aux->elemento = x;
	aux->der = NULL;
	aux->izq = NULL;
	
	return aux;
}

class Arbol{
public:
void imprimir(Nodo *ABB, int cont);
void menu();
void insertarNodo(Nodo *&ABB, int n);
void preOrden(Nodo *ABB);
void inOrden(Nodo *ABB);
void postOrden(Nodo *ABB);
};



int main(){
	Arbol a;
	a.menu();
	return 0;
}

void Arbol::menu(){
	int elemento,opc;
	while(opc !=6){
        system("cls");
		cout<< "========================================="<<endl;
		cout<< "Teclea el indice de la opción que deseas utilizar."<<endl;
		cout<<"1 - Insertar" <<endl;
		cout<<"2 - Imprimir" <<endl;
		cout<<"3 - PreOrden: " <<endl;
		cout<<"4 - InOrden: " <<endl;
		cout<<"5 - PostOrden: " <<endl;
		cout<<"6 - Salir" <<endl;
		cout<< "========================================="<<endl;
		cin>>opc;
		
		switch(opc){
			cout<<"======================================"<<endl;
			case 1: cout<<"Teclea un numero entero para insertar en el nodo: "<<endl;
			cout<<"======================================"<<endl;
					cin>>elemento;
					insertarNodo(ABB, elemento);
					cout<<endl;
					break;
					system("pause");
			case 2: 
					cout<<"======================================"<<endl;
					cout<<"Imprimiendo el Arbol:"<<endl;
					cout<<"======================================"<<endl;
					imprimir(ABB,0);
					cout<<endl;
                    system("pause");
					break;
			
			case 3: 
					cout<<"======================================"<<endl;
					cout<<"Recorriendo el arbol en PreOrden: "<<endl;
					cout<<"======================================"<<endl;
					preOrden(ABB);
					cout<<endl;
                    system("pause");
					break;
					
			case 4: 
					cout<<"======================================"<<endl;
					cout<<"Recorriendo el arbol en InOrden: "<<endl;
					cout<<"======================================"<<endl;
					inOrden(ABB);
					cout<<endl;
                    system("pause");
					break;
					
			case 5:
					cout<<"======================================"<<endl;
					cout<<"Recorriendo el arbol en PostOrden: "<<endl;
					cout<<"======================================"<<endl;
					postOrden(ABB);
					cout<<endl;
					system("pause");
					break;
		}

	}
}

void Arbol::insertarNodo(Nodo *&ABB, int x){
	if(ABB == NULL){
		Nodo *aux = crearNodo(x);
		ABB = aux;
	}
	else{
		int auxi = ABB->elemento;
		if(x < auxi){
			insertarNodo(ABB->izq,x);
		}
		else{
			insertarNodo(ABB->der,x);
		}
	}
}

void Arbol::imprimir(Nodo *ABB, int cont){
	if(ABB == NULL){
		return;
	}
	else{
		imprimir(ABB->der, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"   ";
		}
		cout<<ABB->elemento<<endl;
		imprimir(ABB->izq,cont+1);
	}
}

void Arbol::preOrden(Nodo *ABB){
	if(ABB == NULL){
		return;
	}
	else{
		cout<<ABB->elemento<<" - ";
		preOrden(ABB->izq);
		preOrden(ABB->der);
	}
}

void Arbol::inOrden(Nodo *ABB){
	if(ABB == NULL){
		return;
	}
	else{
		inOrden(ABB->izq);
		cout<<ABB->elemento<<" - ";
		inOrden(ABB->der);
	}
}

void Arbol::postOrden(Nodo *ABB){
	if(ABB == NULL){
		return;
	}
	else{
		postOrden(ABB->izq);
		postOrden(ABB->der);
		cout<<ABB->elemento<<" - ";
	}
}
