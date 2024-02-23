#include <stdio.h>
#include <stdlib.h> //added

int search(int numbers[], int low, int high, int value) 
{
	//Beginning of implementation
	if (low <=high) { //if low > high, value not found
		int mid = low + (high-low)/2; //calculate mid index

		if (numbers[mid] == value){ //check if value is at mid index
			return mid; 
		}
		if (numbers[mid]>value){ //if value is less, look left half
			return search(numbers, low, mid-1, value);
		}
		return search(numbers, low, mid -1, value); //if value is larder, search right half
		//End of implementation
	}	
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}