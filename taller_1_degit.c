#include<stdio.h>

#define true 1
#define false 0
void main()
{
    int n,num2, div, mod, i, j, band=true;
    int cont_ceros=0, cont_par=0, cont_impar=0, cont_primo=0;
    
    printf("Ingrese una cantidad de iteraciones:\n");
    do{
    scanf("%d", &n);}while(n<0);
       
         for(i=1;i<=n;i++){
        printf("ingrese el numero %d\n", i);
        scanf("%d", &num2);
          div==num2;
        
        do{
        mod= div%10;
        div= div/10;
        if(mod==0);{
        cont_ceros=cont_ceros+1;}
        }while(div!=0);
        
          if(num2 % 2==0){
          cont_par=cont_par+1;}
          else{
          cont_impar=cont_impar+1;}
        
        if(num2>2){
        j=2;
        do{
        if(num2%j==0)
        {
        band=false;
        }
        j=j+1;
        }while((j<=num2-1) && (band==true));
        }
          if(band==true){
            cont_primo=cont_primo+1;
           
        }
        
        }
    printf("la cantidad de pares es: %d\n", cont_par);
    printf("la cantidad de impares es: %d\n", cont_impar);
    printf("la cantidad de ceros es:%d\n", cont_ceros);
    printf("la cantidad de primos es:%d\n", cont_primo);
    }
    