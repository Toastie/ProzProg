#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"
#define MAX 100

struct student{
    char *vname;
    char *nname;
    int matrikel;
    char *adresse;
    int PflichtKurse;
    struct student *vor;
    struct student *nach;
};

struct student *init(char vname[MAX], char nname[MAX], int matrikel, char adresse[MAX], int kurs, struct student *vor){

    static struct student *x;

    x = malloc(sizeof(struct student));

    x->vname = malloc(MAX * 8);
    x->nname = malloc(MAX * 8);
    x->adresse = malloc(MAX * 8);

    x->vname = vname;
    x->nname = nname;
    x->matrikel = matrikel;
    x->adresse = adresse;    
    x->PflichtKurse = kurs;

    x->vor = vor;
    x->nach = NULL;

    if(vor != NULL){
        vor->nach = x;
    }

    return x;
}

void ausgabe(struct student *x){     
    printf("Vorname:                    %s\n",x->vname);
    printf("Nachname:                   %s\n",x->nname);
    printf("Matrikelnummer:             %d\n",x->matrikel);
    printf("Adresse:                    %s\n",x->adresse);
    printf("Abgeschlossene Pflichkurse: %d\n",x->PflichtKurse);
    printf("---------------------------------------------------\n");
    
    if(x->nach != NULL){
        ausgabe(x->nach);
    }else{
        printf(RED"\nEnde der Liste erreicht!\n"RESET);
    }
    
    return;
}   

void del(struct student *x){
    if(x->nach ==  NULL){
        x->vor->nach = NULL;
        return;
    }else{
        x->vor->nach = x->nach;
        x->nach->vor = x->vor;
        return;
    }
}

void einf(struct student *x,struct student *vor, struct student *nach){
    vor->nach = x;
    x->vor = vor;
    x->nach = nach;
    nach->vor = x;
}


void tauschen(struct student *x, struct student *y){
    struct student *zwischen;

    x->vor->nach = y;
    
    zwischen = y->vor;

    y->vor = x->vor;

    x->vor = zwischen;

    x->vor->nach = x;

    zwischen = y->nach;

    y->nach = x->nach;

    y->nach->vor = y;

    x->nach = zwischen;

    x->nach->vor = x;

    return;
}


int main(){

    struct student *student1;
    struct student *student2;
    struct student *student3;
    struct student *student4;
    struct student *student5;

    struct student *test;

    test = init("real","test",1,"lol",4,NULL);

    student1 = init("Anna","Musterfrau",22222,"Am Schwarzenberg - Campus 3", 4,NULL);
    student2 = init("Hans", "Peter", 44444, "Kasernenstraße 12", 2, student1);
    student3 = init("Lisa", "Lusitg",66666, "Denickestrasse 15", 8,student2);
    student4 = init("test","nachname",88888,"Erpelweg 13",9,student3);
    student5 = init("test2","nachname2",11111,"testweg 12",12,student4);

    ausgabe(student1);

    tauschen(student3,student4);

    ausgabe(student1);

    del(student3);

    ausgabe(student1);


    free(student1);
    free(student2);
    free(student4);
    free(student5);

}