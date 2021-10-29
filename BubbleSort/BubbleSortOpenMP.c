

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<omp.h>

static int *integer_array;

void swap(int*, int, int); //function to swap two integer values
void print(int);              //function to print our global array.
void initializeIntegerArray(int); //function to initialize array dynamically with random numbers.
void sorts(int);

int main(int argc, char* argv[]){
    clock_t t;
    int i,j;
    int NO_OF_ITEMS=100000;
    NO_OF_ITEMS = atoi(argv[1]);
    initializeIntegerArray(NO_OF_ITEMS);
    //printf("\n\n------Before Sorting------\n\n");
    //print();
    t = clock();
    sorts(NO_OF_ITEMS);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    //printf("\n\n------After  Sorting------\n\n");
    //print(NO_OF_ITEMS);
    printf("BubbleSort-OpenMP\n");
    printf("%f seconds\n", time_taken);
    free(integer_array);
    return 0;
}
void sorts(int NO_OF_ITEMS)
{
    int i,j;
    for(i=0;i<NO_OF_ITEMS;i++){
        int first=i%2;
        #pragma omp parallel for default(shared),shared(integer_array,first)
        for(j=first;j<NO_OF_ITEMS-1;j+=2){
            if (integer_array[j] > integer_array[j+1]){
                swap(integer_array,j,j+1);
            }
        }
    }
}



void swap(int* v, int a, int b){
    unsigned temp;
    temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void print(int NO_OF_ITEMS) {
    int i;
    printf("\n----------------OUR INTEGER ARRAY----------------\n\n");
    for (i = 0; i < NO_OF_ITEMS; i++) {
        printf("%d\t", integer_array[i]);
    }
    printf("\n\n----------------INTEGER ARRAY PRINTED----------------\n");
}

void initializeIntegerArray(int NO_OF_ITEMS){
    int i;time_t t;
    integer_array = (int *) malloc(NO_OF_ITEMS*sizeof(int)); //DMA
    srand((unsigned) time(&t)); //randomizing everytime
    for (i = 0; i < NO_OF_ITEMS; i++) {
        integer_array[i] = rand() % (1000 + 1 - 0) + 0; //Generating random numbers between 0-1000
    }
}
