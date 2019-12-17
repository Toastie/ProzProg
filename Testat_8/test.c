#include <stdio.h>
#include <stdlib.h>


//Länge des Arrays muss im ersten wert gespeichert werden!



void printArray(int *array){
    int l = (sizeof(array) / sizeof(int));
    printf("Array = {%d",array[0]);
    for (int i = 1; i < l; i++){
        printf(", %d",array[i]);
    }
    printf("}\n");
    return;
}

int istNichtLeer(int *array){
    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++){
        if(array[i] == 0){
            return(0);
        }
    }
    return(1);
}

void splitArray(int *array,int *links, int *rechts){
    int laenge;

    laenge = sizeof(array) / sizeof(int);

    if(laenge % 2 == 0){
        links = malloc((laenge / 2) * sizeof(int));
        rechts = malloc((laenge / 2) * sizeof(int));
        for (int i = 0; i < (laenge / 2); i++){
            links[i] = array[i];
        }
        for (int i = 0; i < (laenge / 2); i++){
            rechts[i] = array[(i + (laenge /2))];
        }
    }else
    {
        links = malloc((laenge / 2) * sizeof(int));
        rechts = malloc((1 + (laenge / 2)) * sizeof(int));
        for (int i = 0; i < (laenge / 2); i++){
            links[i] = array[i];
        }
        for (int i = 0; i <= (laenge / 2); i++){
            rechts[i] = array[(i + (laenge / 2))];
        }
        
    }

}

void mergeArrays(int *array, int *links, int *rechts){
    int i,j,z;
    z = 0;
    while(istNichtLeer(links) && istNichtLeer(rechts)){
        i = j = 0;
        while (links[i] == 0){
            i++;
        }
        while (rechts[j] == 0){
            j++;
        }
        
        if(links[i] > rechts[j]){
            array[z] = links[i];
            links[i] = 0;
        }else{
            array[z] = rechts[j];
            rechts[j] = 0;
        }
        z++;
    }

    while (istNichtLeer(links)){
        i = 0;
        while(links[i] == 0){
            i++;
        }
        array[z] = links[i];
        links[i] = 0;
        z++;
    }
    
    while (istNichtLeer(rechts)){
        i = 0;
        while (rechts[i] == 0){
            i++;
        }
        array[z] = rechts[i];
        rechts[i] = 0;
        z++;
    }
    return;
}

int main(){
    int *array,*links,*rechts;
    array = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++){
        array[i] = i;
    }

    printArray(array);

    splitArray(array,links,rechts);

    printArray(links);
    printArray(rechts);

    mergeArrays(array,links,rechts);

    printArray(array);

    return(0);
}