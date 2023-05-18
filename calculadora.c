#include<stdio.h>

int suma(int a, int b);
int resta(int a, int b);
int mult(int a, int b);
int div(int a, int b);

int main()
{
int decision, num1=0, num2=0, res=0;
    printf("Ingrese una operación a ejecutar\n\n Suma:1\n Resta:2\n Multiplicación:3\n División:4\n");
    scanf("%d", &decision);
    printf("Ingrese dos numeros\n");
    
    switch(decision){
    case 1:
    printf("Numero 1\n");
    scanf("%d", &num1);
    printf("Numero 2\n");
    scanf("%d", &num2);
    res=suma(num1, num2);
    break;
    case 2:
    printf("Numero 1\n");
    scanf("%d", &num1);
    printf("Numero 2\n");
    scanf("%d", &num2);
    res=resta(num1,num2);
    break;
    case 3:
    printf("Numero 1\n");
    scanf("%d", &num1);
    printf("Numero 2\n");
    scanf("%d", &num2);
    res=mult(num1, num2);
    break;
    case 4:
    printf("Numero 1\n");
    scanf("%d", &num1);
    printf("Numero 2\n");
    scanf("%d", &num2);
    if(num2==0){
printf("!Operador inválido!\n No se puede dividir entre 0\n\n");
} else{
    res=div(num1, num2);
}
    break;
    default:
    printf("VALOR INVALIDO\n\n");
    break;
}
printf("El resultado es %d", res);
    return 0;
}

int suma(int a, int b)
{
int c;
c= a+b;
return c;
}

int resta(int a, int b){
int c;
c= a-b;
return c;
}

int mult(int a, int b){
int c;
c= a*b;
return c;
}

int div(int a, int b){
int c;
c=a/b;
return c;
}
