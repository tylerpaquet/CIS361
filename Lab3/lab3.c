// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main ()
{
	const int MaxSize = 25000;
	int i, j, temp;


	// Part one: processing a statically allocated array

	clock_t begin1 = clock();
	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

	/*for(i = 0; i < MaxSize; i++)		//print presorted array
	{
		printf("%d\n", staticArray[i]);
	}*/

	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}
	clock_t end1 = clock();
	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

	/*for(i = 0; i < MaxSize; i++)		//print sorted array
        {
                printf("%d\n", staticArray[i]);
        }*/



	// Part two: processing a dynamically allocated array

	clock_t begin2 = clock();
	int max = 25000;
	int * dynamicArray = calloc(max, sizeof(int));	//declare dynamic array

	for(i = 0; i < max; i++)			//initialize array with values
	{
		*(dynamicArray + i) = max - i;		//descending sequence
	}

	/*for(i = 0; i < max; i++)			//print presorted array
	{
		printf("%d\n", *(dynamicArray + i));
	}*/

	/*for(i = 0; i < max - 1; i++)			//bubble sort array data
	{
		for(j = max - 1; j > i; j--)
		{
			if (*(dynamicArray + (j-1)) > *(dynamicArray + j))
			{
				temp = *(dynamicArray + (j-1));
				*(dynamicArray + (j-1)) = *(dynamicArray + j);
				*(dynamicArray + j) = temp;
			}
		}
	}*/
	int *p;
	for(i = 0; i < max - 1; i++)			//faster bubble sort utilizing pointers
	{
		for(p = dynamicArray + (max - 1); p > dynamicArray + i; p--)
		{
			if((*(p-1) > *p))
			{
				int temp = *(p - 1);
				*(p - 1) = *p;
				*p = temp;
			}
		}
	}
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

	 /*for(i = 0; i < max; i++)                        //print sorted array
        {
                printf("%d\n", *(dynamicArray + i));
        }*/





	// Display the amount of time used for each part above

	printf("Time spent to initialize and bubble sort static array: %.2lf\n", time_spent1);
	printf("Time spent to initialize and bubble sort dynamic array: %.2lf\n", time_spent2);


	return 0;
}
