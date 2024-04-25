#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <class T>
class Arbol{
	struct Nodo{
//        T* valor[2];
        string nombre = "";
    	vector<Nodo*> nodos;
        Nodo(string nombre):nombre(nombre){}
    };
    
    private:
        Nodo* raiz = nullptr;
        int altura = 0;
        int orden = 3;
        
        vector<string> split(string path){
			vector<string> output; 
			string temp = "";
			for (char chr : path){
				if (chr != '/'){
					temp += chr;
					continue;
				}
				output.push_back(temp);
				temp = "";
			}
			output.push_back(temp);
			return output;
		}

    public:
    	void mostrar(){
            Nodo* nodo = raiz;
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

        void add(string path, string nombre){
            struct Nodo* new_nodo = new Nodo(nombre);
        	path = split(path);
            if(altura == 0){
            	raiz = new_nodo;
            	return;
			}
			short int n_nodos = aux->nodos.size();
			Nodo *aux = raiz;
			for(int nivel = 0; nivel < altura; nivel++){
				for(int nodo = 0; nodo < n_nodos; nodo++){
					if(aux->nodos[nodo]->nombre == path[nivel]){
						aux = aux->nodos[nodo];
					}
				}
				for(int nodo = 0; nodo < n_nodos; nodo++){
					if(aux->nodos[nodo] == nullptr){
						aux->nodos[nodo].push_back(new_nodo);
						if(tam_path > altura){
							++altura;
						}
						return;
					}
					cout << "No hay espacio disponible " << orden << "/" << orden << endl;
				}
			}
        }
};

//class O(){}
struct Nodo{
//        T* valor[2];
        string nombre = "";
    	vector<Nodo*> nodos;
        Nodo(string nombre):nombre(nombre){}
    };

int main(){
	Arbol<int> a;
	a.add("", "r");
	a.add("r", "nodo1");
	a.add("raiz", "nodo2");
	a.add("raiz/nodo2", "nodo2,1");
	vector<Nodo*> nodos;
	
	a.mostrar();
	
	string path = "1/2/33";
	vector<string> v = split(path);
	
	
	return 0;
}
