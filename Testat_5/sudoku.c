#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9]={
    {4,1,0,0,6,5,0,0,7},
    {0,0,6,0,0,7,4,8,0},
    {2,0,7,4,9,0,0,0,6},
    {0,6,0,0,7,0,1,0,0},
    {3,0,1,5,0,0,0,7,2},
    {0,9,0,0,4,2,3,0,8},
    {1,0,8,6,0,0,0,2,9},
    {0,2,0,0,1,8,6,4,0},
    {6,0,0,3,0,0,0,1,0}
    };

int original[9][9]={
    {4,1,0,0,6,5,0,0,7},
    {0,0,6,0,0,7,4,8,0},
    {2,0,7,4,9,0,0,0,6},
    {0,6,0,0,7,0,1,0,0},
    {3,0,1,5,0,0,0,7,2},
    {0,9,0,0,4,2,3,0,8},
    {1,0,8,6,0,0,0,2,9},
    {0,2,0,0,1,8,6,4,0},
    {6,0,0,3,0,0,0,1,0}
    };

void printSudoku(int sudoku[9][9]){     //Gibt das aktuelle Sudoku aus
    printf("  |  ");
    //Ausgabe der Spaltenzahl
    for (int i = 1; i < 10; i++){
        printf("%d  ",i);
        if(i  % 3 == 0 && i != 0){
            printf("|  ");
        }
    }
    printf("\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < 9; i++){
        //Ausgabe der Zeilenzahl
        printf("%d |  ",i + 1);
        for (int j = 0; j < 9; j++){    //Ausgabe der Zahl im Sudoku
            if(sudoku[i][j] != 0){
                printf("%d  ", sudoku[i][j]);
            }
            else{       //Falls die Zahl 0 ist ist die Zelle leer und wird nicht ausgegeben
                printf("   ");
            }
            if((j + 1) % 3 == 0 && j != 0){ //Ausgabe der Blockgrenzen zur besseren Übersicht
                printf("|  ");
            }
        }
        if ((i + 1) % 3 == 0){          //Ausgabe der Blockgrenze zur besseren Übersicht
            printf("\n---------------------------------------");
        }
        printf("\n");
    }
}

int eingabePruefen(int x, int y, int z){    //Prüft die Eingabe auf zulässigkeit
    //Spalte überprüfen, falls die Eingabe bereits vorhanden ist wird 1 zurückgegeben
    for (int i = 0; i < 9; i++){
        if (z == sudoku[i][y]){
            return(1);
        }
    }

    //Zeile überprüfen, falls die Eingabe nicht zulässig ist wird 2 zurückgegeben
    for (int i = 0; i < 9; i++){
        if (z == sudoku[x][i]){
            return(2);
        }
    }

    //Block finden und Anfangskoordinate als x / y Wert setzen
    if(x <= 2){
        x = 0;
    }
    else if(x <= 5){
        x = 3;
    }
    else{
        x = 6;
    }

    if(y <= 2){
        y = 0;
    }
    else if(y <= 5){
        y = 3;
    }
    else{
        y = 6;
    }

    //Block überprüfen, falls die Eingabe unzulässig ist wird 3 zurückgegeben
    for (int i = x; i < (x + 3); i++){
        for (int j = y; j < (y + 3); j++){
            if(z == sudoku[i][j]){
                return(3);
            }
        }   
    }
    //Falls die Eingabe zulässig ist wird 4 zurückgegeben
    return(4);
}

int nullenVorhanden(int sudoku[9][9]){      //Prüft ob Nullen vorhanden sind, wenn keine vorhanden sind ist das Sudoku gelöst (keine falschen Eingaben möglich)
    //Geht alle Elemente des Arrays durch, wenn eines Null ist wird 1 zurückgegeben (von der while-Schleife als true interpretiert)
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudoku[i][j] == 0){
                return(1);
            }
        }
    }
    return(0);
}

int main(){
    int x,y,z;
    x = y = z = 0;
    printSudoku(sudoku);
    //Abfrage der Eingabe, während das Sudoku noch nicht gelöst ist
    while(nullenVorhanden(sudoku)){
        printf("Zeile:");
        scanf("%d",&x);
        printf("Spalte:");
        scanf("%d",&y);
        printf("Einzufügende Zahl:");
        scanf("%d",&z);
        x--;
        y--;
        //Abfrage ob die eingegebenen Koordinaten / Werte im Wertebereich [1,9] liegen
        if(x < 9 && y < 9 && x >= 0 && y >= 0 && z < 10 && z > 0){
            //Prüfen ob das Element im ursprünglichem Sudoku vorhanden war, falls ja ist ein verändern nicht zulässig
            if(original[x][y] == 0){
                //Unterscheidung der unterschiedlichen Fehler um die unzulässigkeit der Eingabe zu begründen
                switch (eingabePruefen(x,y,z)){
                case 1: printf("Eingabe ungültig, Zahl in der Spalte bereits vorhanden.\n"); break;
                case 2: printf("Eingabe ungültig, Zahl in der Zeile bereits vorhanden.\n"); break;
                case 3: printf("Eingabe ungültig, Zahl im Block bereits vorhanden.\n"); break;
                case 4: system("@cls||clear"); sudoku[x][y] = z; printSudoku(sudoku); break;
                }
            }
            else{
                printf("Dieser Wert darf nicht verändert werden!\n");
            }
        }
        else{
            printf("Ihre Eingaben liegen nicht im Wertebereich [1,9]\n");
        }
    }
    //Ausgabe der Gratulation zum lösen des Sudokus
    printf("Congratulations, you've won!");
    return(0);
}  