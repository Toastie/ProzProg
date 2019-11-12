#include <stdio.h>
#include <stdint.h>

int main(){
 // Variablen
 uint16_t Zahl;
 int potenz;
 Zahl = 99999999999;

printf("%hu \n", Zahl);

 //Schleife um zu testen ob die aktuelle 2er Potenz in die Zahl passt
 for (int i = 16; i >= 0; i--){
     potenz = 1;
     
     //Bilden der aktuellen 2er Potenz, immer um einen geringer pro Schleifendurchlauf  (2^i)
     for (int d = i; d > 0; d--){
         potenz = potenz * 2;
     }

     //Test ob die aktuelle Potenz in die Zahl passt, falls ja wird diese von der Zahl abgezogen und mit dem Rest weitergearbeitet
     if (Zahl - potenz >= 0){
         //Wenn die Potenz passt wird eine 1 ausgegeben
         printf("1");
         Zahl = Zahl - potenz;
     }
     //Falls die Potenz nicht passt wird eine 0 ausgegeben    
     else{
        printf("0");
    }
 }
 printf("\n");
 return(0);
}
