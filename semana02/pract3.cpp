#include<stdio.h>
#include<math.h>
int main(){
    float D,d;
    printf("ingrese la diagonal mayor:");
    scanf("%f",&D);
    printf("ingrese la diagonal menor:");
    scanf("%f",&d);
    double A=(d*D)/2;
    double L=sqrt(pow(d/2,2)+pow(D/2,2));
    double P=4*L;
    printf("el area del rombo es:%.0f\n",A);
    printf("el lado del rombo es:%.0f\n",L);
    printf("el perimetro del rombo es:%.0f\n",P);
    return 0;
}