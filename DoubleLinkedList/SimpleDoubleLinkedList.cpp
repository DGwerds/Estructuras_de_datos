#include <iostream>

using std::cout;
using std::endl;

template <class T>

class LinkedList{	
	struct Nodo{
    	T valor;
    	Nodo* anterior = nullptr;
    	Nodo* siguiente = nullptr;
        
		Nodo(T valor):valor(valor){}
	};
	
	private:
		Nodo* ultimo = nullptr;
    	Nodo* primero = nullptr;
    	int tamano = 0;
		
		Nodo* buscar_nodo(int index){
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
		
		void delete_node(Nodo* nodo){
			delete nodo;
			--tamano;
		}
	
	public:	
		bool empty(){
		    return (tamano == 0);
		}
		    	
		int size(){
			return tamano;
		}
			        
		void clear(){
			Nodo* nodo = primero;
			Nodo* aux;
			while (nodo != NULL) {
			    aux = nodo->siguiente; 
			    delete nodo;
			    nodo = aux;
			    --tamano;
			}
			ultimo = nullptr;
			primero = nullptr;
		}
			        
		void mostrar(){
			Nodo* nodo = primero;
			cout << "{";
			while (nodo) {
			    cout << nodo->valor;
			    nodo = nodo->siguiente;
				if (nodo){
					cout << ", ";
				} 
			}
			cout << "}" << endl;
		}
			    
		void push_back(T _valor){
			struct Nodo* n = new Nodo(_valor);
			n->anterior = ultimo;
			if (ultimo){
			    ultimo->siguiente = n;
			}
			else if(!primero){
			    primero = n;
			}
			ultimo = n;
			++tamano;
		}
		
		void push_front(T _valor){
			struct Nodo* n = new Nodo(_valor);
			n->siguiente = primero;
			if (primero){
			    primero->anterior = n;
			}
			else if(!ultimo){
				ultimo = n;
			}
			primero = n;
			++tamano;
		}
			    
		void insert(int index, T _valor){
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
		    ++tamano;
		    return;
		}
			    
		int get(int index){
			Nodo* nodo = buscar_nodo(index);
		    if (nodo == nullptr) return 0;
		    return nodo->valor;
		}
		
		void replace(int index, T _valor){
			buscar_nodo(index)->valor = _valor;
		}
		
		void pop_back(){
			Nodo* aux = ultimo;
			if(ultimo == primero){
				clear();
				return;
			}
			ultimo->anterior->siguiente = nullptr;
			ultimo = ultimo->anterior;
			delete_node(aux);
		}
		
		void pop_front(){
			Nodo* aux = primero;
			if (aux == ultimo){
				clear();
				return;
			}
			primero->siguiente->anterior = nullptr;
			primero = primero->siguiente;
			delete_node(aux);
		}
		
		void erase(int index){
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
};

int main(){
	LinkedList<float> l1;
    l1.push_back(1.2);
	l1.mostrar(); 
    l1.push_front(2);
	l1.mostrar(); 
    l1.insert(1, 9.8);
	l1.mostrar(); 
    l1.insert(3, 5);
	l1.mostrar(); 
	l1.replace(0, 4);
	l1.mostrar(); 
	l1.pop_back();
	l1.mostrar(); 
	l1.pop_front();
	l1.mostrar(); 
	return 0;
}



