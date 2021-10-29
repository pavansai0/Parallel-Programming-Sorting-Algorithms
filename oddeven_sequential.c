#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX_VALUE 1000
void swap(int * x, int * y)

{

    int temp;

 

    temp = *x;

    *x = *y;

    *y = temp; 

}

 

/* sorts the array using oddeven algorithm */

void oddeven_sort(int * x,int MAX)

{

    int sort = 0, i;

 

    while (!sort)

    {

        sort = 1;

        for (i = 1;i < MAX;i += 2)

        {

            if (x[i] > x[i+1])

            {

                swap(&x[i], &x[i+1]);

                sort = 0;

            }

        }

        for (i = 0;i < MAX - 1;i += 2)

        {

            if (x[i] > x[i + 1])

            {

                swap(&x[i], &x[i + 1]);

                sort = 0;

            }

        }

    }
}

void generate_array(int* a, int size)
{
    int i = 0;
	
	srand(time(NULL));

	for(i = 0; i < size; i++)
    {
		a[i] = rand() % MAX_VALUE;
    }
} 

int main(int argc, char** argv)

{

    clock_t t; 
    int size = atoi(argv[1]);
    int *a = (int*)calloc(size, sizeof(int));
    int i;

 

    generate_array(a,size);


    t = clock();
    oddeven_sort(a,size);
    t = clock() - t;    
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("OddEvenSort-Sequential\n");
    printf("%f seconds\n", time_taken);


}




