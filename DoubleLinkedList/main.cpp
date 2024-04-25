#include "LinkedList.h"
#include <iostream>

using std::cout;
using std::endl;


int main(){
    LinkedList l1;
    l1.push_back(21);
    l1.push_front(13);
    l1.insert(0, 12);
	l1.mostrar(); 
	l1.erase(3);
	l1.mostrar();
	l1.clear();
	l1.mostrar();
}
