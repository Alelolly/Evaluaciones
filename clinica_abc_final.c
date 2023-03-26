#include<stdio.h>

void main(){

int n=0, i, dia=0, mes=0, año=0, ced=0, edad=0, mod;
int cont_f=0, cont_m=0, cont_may=0, cont_men=0, cont_desc15=0, cont_desc35=0;
char sexo;

printf("ingrese la cantidad de pacientes\n");
do{
scanf("%d", &n);
}while(n<=0);

    for(i=1;i<=n;i++){
    printf("ingrese los datos del paciente numero %d\n", i);
       
        printf("cedula de identidad: ");
        do{
        scanf("%d", &ced);
        }while(ced<=0);
        
         printf("sexo:");
        do{
        scanf("%c", &sexo);
        }while((sexo!='f')&&(sexo!='m'));
        if(sexo=='f'){
        cont_f=cont_f+1;
        } else{
        cont_m=cont_m+1;}
        
        printf("edad:");
        do{
        scanf("%d", &edad);
        }while(edad<1);
        
        printf("fecha de nacimiento:\n");
        printf("dia:");
        do{
        scanf("%d", &dia);
        } while((dia<1)&&(dia>31));
        
        printf("mes:");
        do{
        scanf("%d", &mes);
        } while((mes<1)&&(mes>12));
        
        printf("año:");
        do{
        scanf("%d", &año);
        } while(año<1);
        if(edad>=18){
        cont_may=cont_may+1;
        } else{
            cont_men=cont_men+1;
            }
        
        mod=ced%10;
        if((sexo=='f')&&(mod%2==0)){
        cont_desc15=cont_desc15+1;
        }
        
        if((sexo=='m')&&(edad>=60)){
        cont_desc35=cont_desc35+1;
        }
    }
    printf("la cantidad de pacientes femeninos son: %d\n", cont_f);
    printf("la cantidad de pacientes masculinos son: %d\n", cont_m);
    printf("la cantidad de pacientes mayores de edad son: %d\n", cont_may);
    printf("la cantidad de pacientes menores de edad son: %d\n", cont_men);
    printf("pacientes con descuento del 15 por ciento: %d\n", cont_desc15);
    printf("pacientes con descuento del 35 por ciento: %d\n", cont_desc35);
}
    