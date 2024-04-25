#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>

class Pila{
    class Nodo{
        public:
            T* valor;
            Nodo* anterior = nullptr;

            Nodo(T &valor):valor(&valor){}
    };

    private:
        Nodo* ultimo = nullptr;
        int tamano = 0;

    public:
    	~Pila(){clear();}

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
                tamano--;
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

        void push_at(int index, T &valor){
            if(index<0 or index>tamano) return;
            struct Nodo* new_nodo = new Nodo(valor);
            Nodo* nodo = ultimo;
            Nodo* aux;
            for (int i = 0; i < index; i++){
                aux = nodo;
                nodo = nodo->anterior;
            }
            if(aux) aux->anterior = new_nodo;
            new_nodo->anterior = nodo;
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

class Persona{
    private:
        string nombre;
        short int edad;
        string motivo;
        short int gravedad;
    public:
        Persona(string nombre, short int edad, string motivo, short int gravedad)
                :nombre(nombre), edad(edad), gravedad(gravedad), motivo(motivo){}
        
        Persona(){}
                
        friend std::ostream& operator<<(std::ostream& os, const Persona& p){
            os << "(" << "Nombre: "<< p.nombre << 
//			", edad: " << p.edad << 
//			", motivo: " << p.motivo <<
			", gravedad: " << p.gravedad << ")";
            return os;
        }

        short int get_edad(){return edad;}
        short int get_gravedad(){return gravedad;}
};

void agregar_prioridad(Pila<Persona>* cola, Persona* new_persona){
	int pos = 0;
	short int gravedad1, gravedad2, edad1, edad2;
	cola->push(*new_persona);
	for (int persona = 1; persona < cola->size(); persona++){
		gravedad1 = new_persona->get_gravedad();
		gravedad2 = cola->get(persona).get_gravedad();
		if (gravedad1 > gravedad2){	
			++pos;
		}
		else if(gravedad1 == gravedad2){
			edad1 = new_persona->get_edad();
			edad2 = cola->get(persona).get_edad();
			++pos;
			if(edad1 < 12 or edad1 > 65){
				--pos;
				if(edad1 < 12 and edad1 >= edad2){
					++pos;
				}
				else if(edad1 > 65 and edad1 <= edad2){
					++pos;
				}
			}
		}
	}
	if(pos != 0){
		cola->pop();
		cola->push_at(pos, *new_persona);
	}
	cout << "su posicion en la cola de espera es: " << pos+1 << endl;
}

int main(){
	string nombre, motivo;
	short int edad, gravedad, input;
	Pila<Persona> cola;
	Persona *new_persona;
	Persona s; 
	
	while(input != 4){
		cout << "\nSeleccione una opcion:\n"
		"1.Ingresar Paciente\n"
		"2.Pasar siguiente paciente\n"
		"3.Mostrar la cola\n"
		"4.Salir\n" << endl;
		cin >> input;
		
		switch (input){
			case 1:
				cout << "A continuacion ingrese informacion del paciente" << endl;
				cout << "Nombre: ";
				cin >> nombre;
				cout << "Edad: ";
				cin >> edad;
				cout << "Motivo: ";
				cin >> motivo;
				cout << "gravedad: ";
				cin >> gravedad;
				new_persona = new Persona(nombre, edad, motivo, gravedad);
				agregar_prioridad(&cola, new_persona);
				break;
			case 2:
				if (cola.size() > 0){
					cout << "el paciente que sale es: " << cola.top() << endl;
					cola.pop();
				}
				if (cola.size() > 0){
					cout << "el siguiente es: " << cola.top() << endl;
				}else{
					cout << "la cola esta vacia" << endl;
				}
				break;
			case 3:
				cola.mostrar();
				break;
			case 4:
				break;
			default:
				cout << "opcion no disponible, intente otra vez" << endl;
		}
	}
    return 0;
}
