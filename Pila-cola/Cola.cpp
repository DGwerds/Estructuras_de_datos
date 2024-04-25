#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Cola{
    struct Nodo{
        T* valor;
    	Nodo* anterior = nullptr;

        Nodo(T &valor):valor(&valor){}
    };

    private:
        Nodo* ultimo = nullptr;
        int tamano = 0;
        
    public:
    	~Cola(){clear();}

        int size(){return tamano;}

        T top(){return *ultimo->valor;}
 
        void clear(){
            Nodo* nodo = ultimo;
            Nodo* aux;
            while (nodo != NULL) {
                aux = nodo->anterior;
				delete nodo->valor;
	            delete nodo;
    	        nodo = aux;
        		--tamano;
			}
            ultimo = nullptr;
        }

        void mostrar(){
            Nodo* nodo = ultimo;
            cout << "{";
            while (nodo) {
                cout << *nodo->valor;
                nodo = nodo->anterior;
                if (nodo){
                    cout << ", ";
                } 
            }
            cout << "}" << endl;
        }

        void push(T &valor){
            struct Nodo* new_nodo = new Nodo(valor);
            new_nodo->anterior = ultimo;
            ultimo = new_nodo;
            ++tamano;
        }

        void pop(){
            Nodo* aux = ultimo;
            ultimo = ultimo->anterior;
            delete aux->valor;
            delete aux;
            --tamano;
        }

        T get(int index){
			Nodo* nodo = ultimo;
			for (int i = 0; i < index; i++){
                nodo = nodo->anterior;
            }
    		return *nodo->valor;
		}
};

class Objeto{
    private:
        int dato;
    public:
        Objeto(int dato):dato(dato){}
                
        friend std::ostream& operator<<(std::ostream& os, const Objeto& p){
            return os << p.dato;
        }
};

int main(){
	Cola<Objeto> c;
	Objeto *o1 = new Objeto(1);
	Objeto *o2 = new Objeto(2);
	Objeto *o3 = new Objeto(3);
	c.push(*o1);
	c.push(*o2);
	c.push(*o3);
	return 0;
}
