#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()

{
   int intentos=5,a,b=0;
   srand(time(NULL));    
   a=1+rand()%1001;
   printf("Se a escogido un numero al azar \n");
   for(int i=0;i<=4;i++){
       printf("\nEl numero es:");
       scanf("%d",&b);  

       if(b==a){
           printf("\nperfecto has adivino el numero en %d ",intentos);
           break;

       }else{
           printf("\nincorrecto!");
           if(b>a){
               printf("\nel numero digitado es mayor.");
           }else{
               printf("\nel numero digitado es menor.");
           }
           intentos--;
           printf("\nintentos restantes:%d",intentos);

           if(intentos==0){
               printf("\n Perdiste!. El numero corrrecto era:%d",a);
           }
       }
   }  
       return 0;
}