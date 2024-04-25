#include <iostream>
#include <vector>

using namespace std;

float sumar(float a, float b){return a+=b;}

float restar(float a, float b){return a-=b;}

float multiplicar(float a, float b){return a*=b;}
    
float dividir(float a, float b){return a/=b;}

int main() {
  typedef float (*ptr)(float, float);
  vector<ptr> tabla;
  tabla.push_back(sumar);
  tabla.push_back(restar);
  tabla.push_back(multiplicar);
  tabla.push_back(dividir);
  
  cout << tabla[0](3, 4) << endl;
  cout << tabla[1](3, 4) << endl;
  cout << tabla[2](3, 4) << endl;
  cout << tabla[3](3, 4) << endl;
  return 0;
}
