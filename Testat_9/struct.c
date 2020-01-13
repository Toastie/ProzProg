#include <stdio.h>

struct student {
    char vname[30];
    char nname[30];
    int matrikel;
    char adresse[100];
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
    struct student student1 = {"Anna", "Musterfrau", 22222, "Am Schwarzenberg - Campus 3", 4};
    struct student student2 = {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2};
    struct student student3 = {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8};

    printf("---------------------------------------------------\n");
    ausgabe(student1);
    ausgabe(student2);
    ausgabe(student3);

    struct student zwischen = student1;
    student1 = student3;
    student3 = zwischen;

    printf("\n\n Erster und Letzter Student vertauscht!\n\n");

    printf("---------------------------------------------------\n");
    ausgabe(student1);
    ausgabe(student2);
    ausgabe(student3);

    return(0);
}