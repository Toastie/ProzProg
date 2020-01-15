#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct student{
    char vname[MAX];
    char nname[MAX];
    int matrikel;
    char adresse[MAX];
    int PflichtKurse;
};

void ausgabe(struct student x){
    printf("Vorname:                    %s\n",x.vname);
    printf("Nachname:                   %s\n",x.nname);
    printf("Matrikelnummer:             %d\n",x.matrikel);
    printf("Adresse:                    %s\n",x.adresse);
    printf("Abgeschlossene Pflichkurse: %d\n",x.PflichtKurse);
    printf("---------------------------------------------------\n");
    return;
}

int main(){

    struct student student[3] = {{"Anna", "Musterfrau", 22222, "Am Schwarzenberg - Campus 3", 4},
                                 {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2},
                                 {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8}
                                };

    struct student zwischen;

    system("clear");

   for(int i = 0; i < 3; i++){
       ausgabe(student[i]);
   }

    printf("\x1B[31m""Vertausche Werte...\n""\x1B[0m");
    zwischen = student[0];
    student[0] = student[2];
    student[2] = zwischen;
 
    for(int i = 0; i < 3; i++){
       ausgabe(student[i]);
   }

}
