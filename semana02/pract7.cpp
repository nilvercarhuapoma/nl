#include<stdio.h>
#include<math.h>
int main (){
    float a,b,c,r;
    printf("ingres el lado1:");
    scanf ("%f",&a);
    printf("ingres el lado2:");
    scanf ("%f",&b);
    printf("ingres el lado3:");
    scanf ("%f",&c);
    printf("ingres el radio:");
    scanf ("%f",&r);
    double P=(a+b+c)/2;
    double S=r*P;
    printf("el semiperimetro del triangulo circunscrito es:%.0f\n",P);
    printf("el area del triangulo circunscrito es:%.0f\n",S);
    getchar();

}
