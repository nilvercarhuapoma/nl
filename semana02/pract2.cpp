#include<stdio.h>
#include<math.h>
int main(){
    float altura,base;
    printf("ingrese la altura:");
    scanf("%f",&altura);
    printf("ingrese la base:");
    scanf("%f",&base);
    float A=altura*base;
    double P=2*(base+altura);
    double D=sqrt(pow(base,2)+pow(altura,2));
    printf("el area del retangulo es:%.0f\n",A);
    printf("el perimetro del rectangulo es:%.0f\n",P);
    printf("la diagonal del rectangulo es:%.0f\n",D);
    return 0;

}
