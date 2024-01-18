#include<iostream>
#include<conio.h>
using namespace std;
int main (){
int a=8,b1,b2,b3,b4,b5;
b1=a++ + a--;
b2=a++ + a++;
b3=a-- + a--;
b4=--a + --a;
b5=--a + a++;
cout<<"es:"<<a<<" "<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<" "<<b5<<endl;
  return 0;
}