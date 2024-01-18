#include<stdio.h>
#include<math.h>
int main (){
    float a,b,c;
    printf("ingrese el lado1:");
    scanf("%f",&a);
    printf("ingrese el lado2:");
    scanf("%f",&b);
    printf("ingrese el lado3:");
    scanf("%f",&c);
    float p=(a+b+c)/2;
    double S=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("el semi perimetro del triangulo es :%.1f\n",p);
    printf("el area del traingulo es :%f\n",S);

    getchar();
}