#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 vector<string> textos;
  string palabras;
  cout<<"ingrese palabras(";
  cout<<"escriba (fin) para terminar):";
  while(true)
  {
    cin>>palabras;
    if(palabras=="fin")
    {
    	break;
    }
  textos.push_back(palabras);
  
  }
  string concatenar ;
  for (string palabras : textos)
  {
   	concatenar += palabras;
  }
  cout << concatenar;
return 0;
}






