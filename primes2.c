#include <stdio.h>
#define UNDEFINED -999
//calculates the prime factorization of a number
//far faster than primes1
void printArray(int array[], int size);
void setArray(int array[], int size, int value);
int main(){
	int number = 24;
	int newnumber = number;
	int factors[number];
	setArray(factors, number, UNDEFINED);
	for (int i = 2, j = 0; i <= (number / 2) + 1; i++){
		if (newnumber % i == 0){
			newnumber = newnumber / i;
			factors[j] = i;
			i--;
			j++;
		}
	}
	printArray(factors, number);
	return 0;
}
void printArray(int array[], int size){
	printf("\n");
	for (int i = 0; i <= size; i++){
		if (array[i] != UNDEFINED){
			printf("%3d: %3d\n", i, array[i]);
		}
	}
	printf("\n");
}
void setArray(int array[], int size, int value){
	for (int i = 0; i <= size; i++){
		array[i] = value;
	}
}