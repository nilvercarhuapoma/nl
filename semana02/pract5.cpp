#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c,h;
    printf("ingrese el lado1:");
    scanf("%f",&a);
    printf("ingrese el lado2:");
    scanf("%f",&c);
    printf("ingrse la base:");
    scanf("%f",&b);
    printf("ingrese la altura:");
    scanf("%f",&h);
    double A=(b*h)/2;
    double P=a+b+c;
    printf("el area del traingulo es:%.0f\n",A);
    printf("el perimetro del triangulo es:%.0f\n",P);
    getchar();

}