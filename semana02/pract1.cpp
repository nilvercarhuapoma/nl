#include<stdio.h>
#include<cmath>
int main(){
float lado;
printf("ingrese el lado:" );
scanf("%f",&lado);
float A=pow(lado,2);
double D=sqrt(2.0)*lado;
float P=lado*4;
printf("el area del cuadrado es:%.0f\n",A);
printf("el perimetro del cuadrado es:%.0f\n",P);
printf("la diagonal el cuadrado es:%.4f\n",D);
return 0;
}