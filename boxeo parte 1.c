#include<stdio.h>

int main(){
int i, j,dec, rmj1=0, rmj2=0, rmj3=0, rcj1=0, rcj2=0, rcj3=0;
int tmj1=0, tmj2=0, tmj3=0, tcj1=0, tcj2=0, tcj3=0;
float bolsa_ganador=100000, bolsa_perdedor=60000;
int gj1=0, gj2=0, gj3=0;
    for(i=1; i<=12; i++){
    printf("Ingrese al ganador del round %d\n Mayweather=1, Canelo:2\n\n", i);
    printf("Juez 1");
    scanf("%d", &dec);
        switch(dec){
        case 1:
        rmj1=rmj1+1;
        tmj1=tmj1+10;
        break;
        case 2:
        rcj1=rcj1+1;
        tcj1=tcj1+10;
        break;
        default:
        printf("VALOR INVALIDO, COLOQUE UN VALOR CORRECTO\n\n");
        do{
        scanf("%d", &dec);
        }while((dec>2)&&(dec<0));
        break;
        }
        printf("Juez 2");
    scanf("%d", &dec);
        switch(dec){
        case 1:
        rmj2=rmj2+1;
        tmj2=tmj2+10;
        break;
        case 2:
        rcj2=rcj2+1;
        tcj2=tcj2+10;
        break;
        default:
        printf("VALOR INVALIDO, COLOQUE UN VALOR CORRECTO\n\n");
        do{
        scanf("%d", &dec);
        }while((dec>2)&&(dec<0));
        break;
        }
        printf("Juez 3");
    scanf("%d", &dec);
        switch(dec){
        case 1:
        rmj3=rmj3+1;
        tmj3=tmj3+10;
        break;
        case 2:
        rcj3=rcj3+1;
        tcj3=tcj3+10;
        break;
        default:
        printf("VALOR INVALIDO, COLOQUE UN VALOR CORRECTO\n\n");
        do{
        scanf("%d", &dec);
        }while((dec>2)||(dec<0));
        break;
        }
        printf("¿Hubo caida?\n (S=1/N=0)\n");
        do{
        scanf("%d", &j);
        if((j>1)||(j<0)){
        printf("VALOR INVALIDO, INTRODUZCA UN VALOR CORRECTO\n");
        }
        }while((j>1)||(j<0));
        if(j==1){
        printf("seleccione al caido\n Mayweather=1, Canelo=2\n");
        scanf("%d", &dec);
        switch(dec){
        case 1:
        tmj1=tmj1-2;
        tmj2=tmj2-2;
        tmj3=tmj3-2;
        break;
        case 2:
        tcj1=tcj1-2;
        tcj2=tcj2-2;
        tcj3=tcj3-2;
        break;
        default:
        printf("VALOR INVALIDO, COLOQUE UN VALOR CORRECTO\n\n");
        do{
        scanf("%d", &dec);
        }while((dec>2)||(dec<0));
        break;
        }
                }
           }
        if(rmj1>rcj1){
        gj1=1;
        }else{
            if(rmj1==rcj1){
            gj1=3;
            }else{
                gj1=2;
                }
        }
        if(rmj2>rcj2){
        gj2=1;
        }else{
            if(rmj2==rcj2){
            gj2=3;
            }else{
                gj2=2;
                }
        }
        if(rmj3>rcj3){
        gj3=1;
        }else{
            if(rmj3==rcj3){
            gj3=3;
            }else{
                gj3=2;
                }
        }
        if((gj1==1)&&(gj2==1)&&(gj3==1)){
        bolsa_ganador=bolsa_ganador+(bolsa_ganador*0.1);
        printf("El ganador de la batalla por UD es Floyd Mayweather\n\n");
        }else{
            if((gj1==2)&&(gj2==2)&&(gj3==2)){
            bolsa_ganador=bolsa_ganador+(bolsa_ganador*0.1);
            printf("El ganador de la batalla por UD es Saúl \"Canelo\" Álvarez\n\n");
            }else{
                  if(((gj1==1)&&(gj2==1)&&(gj3==2))||((gj1==1)&&(gj2==2)&&(gj3==1))||((gj1==2)&&(gj2==1)&&(gj3==1))){
                  bolsa_ganador=bolsa_ganador+(bolsa_ganador*0.05);
            printf("El ganador de la batalla por SD es Floyd Mayweather\n\n");
                  }else{
            if(((gj1==1)&&(gj2==2)&&(gj3==2))||((gj1==2)&&(gj2==2)&&(gj3==1))||((gj1==2)&&(gj2==1)&&(gj3==2))){
            bolsa_ganador=bolsa_ganador+(bolsa_ganador*0.05);
            printf("El ganador de la batalla por SD es Saúl \"Canelo\" Álvarez\n\n");
                  }else{
            if(((gj1==1)&&(gj2==1)&&(gj3==3))||((gj1==1)&&(gj2==3)&&(gj3==1))||((gj1==3)&&(gj2==1)&&(gj3==1))){
            bolsa_ganador=bolsa_ganador+(bolsa_ganador*0.15);
            printf("El ganador de la batalla por MD es Floyd Mayweather\n\n");
          }else{
            bolsa_ganador=bolsa_ganador+(bolsa_ganador*0.15);
            printf("El ganador de la batalla por MD es Saúl \"Canelo\" Álvarez\n\n");
        
             }}}}}
        printf("Las ganancias del ganador son %f\n\n",bolsa_ganador);
        printf("Las ganancias del perdedor son %f\n\n", bolsa_perdedor);
        printf("Rounds ganados de Maywheater(Juez 1): %d\n", rmj1);
        printf("Rounds ganados de Canelo(Juez 1): %d\n", rcj1);
        printf("Puntos de Mayweather(Juez 1): %d\n Puntos de Canelo (Juez 1): %d\n", tmj1, tcj1);
        printf("Rounds ganados de Maywheater(Juez 2): %d\n", rmj2);
        printf("Rounds ganados de Canelo(Juez 2): %d\n", rcj2);
        printf("Puntos de Mayweather(Juez 2): %d\n Puntos de Canelo (Juez 2): %d\n", tmj2, tcj2);
        printf("Rounds ganados de Maywheater(Juez 3): %d\n", rmj3);
        printf("Rounds ganados de Canelo(Juez 3): %d\n", rcj3);
        printf("Puntos de Mayweather(Juez 3): %d\n Puntos de Canelo (Juez 3): %d\n", tmj3, tcj3);
return 0;
}