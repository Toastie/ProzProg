#include <stdio.h>

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

int main(){
    int x,y,z;
    x = y = z = 0;
    printSudoku(sudoku);
    while(1){
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
                sudoku[x][y] = z;
                printSudoku(sudoku);
            }
            else{
                printf("Dieser Wert darf nicht verändert werden!\n");
            }
        }
        else{
            printf("Ihre Eingaben liegen nicht im Wertebereich [1,9]\n");
        }
    }
    return(0);
}