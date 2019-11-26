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

void printSudoku(int sudoku[9][9]){
    printf("  |  ");
    for (int i = 1; i < 10; i++){
        printf("%d  ",i);
        if(i  % 3 == 0 && i != 0){
            printf("|  ");
        }
    }
    printf("\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < 9; i++){
        printf("%d |  ",i + 1);
        for (int j = 0; j < 9; j++){
            if(sudoku[i][j] != 0){
                printf("%d  ", sudoku[i][j]);
            }
            else{
                printf("   ");
            }
            if((j + 1) % 3 == 0 && j != 0){
                printf("|  ");
            }
        }
        if ((i + 1) % 3 == 0){
            printf("\n---------------------------------------");
        }
        printf("\n");
    }
}

int eingabePruefen(int x, int y, int z){
    //Spalte überprüfen
    for (int i = 0; i < 9; i++){
        if (z == sudoku[i][y]){
            return(1);
        }
    }

    //Zeile überprüfen
    for (int i = 0; i < 9; i++){
        if (z == sudoku[x][i]){
            return(2);
        }
    }

    //Block finden und anfangskoordinate als x / y Wert setzen
    printf("%d %d\n",x,y);
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
    
    printf("%d ",x);
    printf("%d\n",y);
    //Block überprüfen
    for (int i = x; i < (x + 3); i++){
        for (int j = y; j < (y + 3); j++){
            if(z == sudoku[i][j]){
                return(3);
            }
        }   
    }
    return(4);
}

int nullenVorhanden(int sudoku[9][9]){
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
    while(nullenVorhanden(sudoku)){
        printf("Zeile:");
        scanf("%d",&x);
        printf("Spalte:");
        scanf("%d",&y);
        printf("Einzufügende Zahl:");
        scanf("%d",&z);
        x--;
        y--;
        if(x < 9 && y < 9 && x >= 0 && y >= 0 && z < 10 && z > 0){
            if(original[x][y] == 0){
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
    printf("Congratulations, you've won!");
    return(0);
}  