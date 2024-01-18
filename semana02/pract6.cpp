#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c,R;
    printf("ingrse el lado1:");
    scanf("%f",&a);
    printf("ingrse el lado2:");
    scanf("%f",&b);
    printf("ingrse el lado3:");
    scanf("%f",&c);
    
    printf("ingrse el Radio:");
    scanf("%f",&R);
    double S=(a*b*c)/(4*R);
    printf("el area del triangulo inscrito es:%.0f",S);
    getchar();

}