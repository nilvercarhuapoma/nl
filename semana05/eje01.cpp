#include <iostream>
#include <ctime>
#include<vector>
using namespace std;
int main(){
    vector<int>vect;
    int *p=&vect[0];
    vect.push_back(15);
    vect.push_back(6);
    vect.push_back(5);
    vect.push_back(12);
    vect.push_back(9);
    for(size_t i=0;i<vect.size();i++){
        cout<<*(p+i)<<" ";
    

    }
}