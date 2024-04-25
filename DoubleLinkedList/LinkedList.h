#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
	struct Nodo{
    	int valor;
    	Nodo* anterior = nullptr;
    	Nodo* siguiente = nullptr;
        
		Nodo(int _valor){
    		valor = _valor;
		}
	};
	
    public:
    	LinkedList();
    	bool empty();
	    int size();
	    void clear();
	    void mostrar();
	    void push_back(int);
	    void push_front(int);
	    void insert(int, int);
	    int get(int);
		void replace(int, int);
		void pop_back();
		void pop_front();
		void erase(int);

    protected:
    private:
    	Nodo* ultimo = nullptr;
    	Nodo* primero = nullptr;
    	int tamano = 0;
    	
    	Nodo* buscar_nodo(int);
		  	
    	void delete_node(Nodo*);
};

#endif
