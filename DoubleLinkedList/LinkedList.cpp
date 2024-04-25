#include "LinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

LinkedList::LinkedList(){}

LinkedList::Nodo* LinkedList::buscar_nodo(int index){
	Nodo* nodo;
	if(index < 0 or index > tamano){
        cout << "Out of index" << endl;
        return nullptr;
    }
	if(index <= tamano/2){
        nodo = primero;
        for (int i = 0; i < index; i++){
            nodo = nodo->siguiente;
        }
    }else{
        nodo = ultimo;
        for (int i = 0; i < index-tamano; i++){
            nodo = nodo->anterior;
        }
    }
    return nodo;
}
    	
void LinkedList::delete_node(Nodo* nodo){
	delete nodo;
	tamano--;
}
    	
bool LinkedList::empty(){
    return (tamano == 0);
}
    	
int LinkedList::size(){
	return tamano;
}
	        
void LinkedList::clear(){
	Nodo* nodo = primero;
	Nodo* aux;
	while (nodo != NULL) {
	    aux = nodo->siguiente; 
	    delete nodo;
	    nodo = aux;
	    tamano--;
	}
	ultimo = nullptr;
	primero = nullptr;
}
	        
void LinkedList::mostrar(){
	Nodo* nodo = primero;
	cout << "{ ";
	while (nodo != NULL) {
	    cout << nodo->valor << " ";
	    nodo = nodo->siguiente; 
	}
	cout << "}" << endl;
}
	    
void LinkedList::push_back(int _valor){
	struct Nodo* n = new Nodo(_valor);
	n->anterior = ultimo;
	if (ultimo){
	    ultimo->siguiente = n;
	}
	else if(!primero){
	    primero = n;
	}
	ultimo = n;
	tamano++;
}

void LinkedList::push_front(int _valor){
	struct Nodo* n = new Nodo(_valor);
	n->siguiente = primero;
	if (primero){
	    primero->anterior = n;
	}
	else if(!ultimo){
		ultimo = n;
	}
	primero = n;
	tamano++;
}
	    
void LinkedList::insert(int index, int _valor){
    struct Nodo* n = new Nodo(_valor);
    Nodo* nodo = buscar_nodo(index);
    if (nodo == nullptr) return;
    n->siguiente = nodo;
    n->anterior = nodo->anterior;
    if(nodo->anterior){
    	nodo->anterior->siguiente = n;
    }else{
    	primero = n;
    }
    nodo->anterior = n;
    tamano++;
    return;
}
	    
int LinkedList::get(int index){
	Nodo* nodo = buscar_nodo(index);
    if (nodo == nullptr) return 0;
    return nodo->valor;
}

void LinkedList::replace(int index, int _valor){
	buscar_nodo(index)->valor = _valor;
}

void LinkedList::pop_back(){
	Nodo* aux = ultimo;
	ultimo->anterior->siguiente = nullptr;
	ultimo = ultimo->anterior;
	delete_node(aux);
}

void LinkedList::pop_front(){
	Nodo* aux = primero;
	primero->siguiente->anterior = nullptr;
	primero = primero->siguiente;
	delete_node(aux);
}

void LinkedList::erase(int index){
	Nodo* aux = buscar_nodo(index);
	if (index == 0){
		pop_front();
		return;
	}else if(index == tamano+1){
		pop_back();
		return;
	}
	if (aux->siguiente){
		aux->siguiente->anterior = aux->anterior;
	}
	if (aux->anterior){
		aux->anterior->siguiente = aux->siguiente;
	}
	delete_node(aux);
}


