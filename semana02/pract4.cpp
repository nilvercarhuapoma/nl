#include<stdio.h>
#include<math.h>
int main(){
    float B,b,h;
    printf("ingrese la base mayor:");
    scanf("%f",&B);
    printf("ingrese la base menor:");
    scanf("%f",&b);
    printf("ingrese la altura:");
    scanf("%f",&h);
    double A=((b+B)*h)/2;
    printf("el area del trapecio:%.0f",A);
    getchar();
}