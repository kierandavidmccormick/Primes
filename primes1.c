#include <stdio.h>
#include <time.h>
#define PRIME 0
#define NPRIME 1
#define UNDEFINED -999
#define END -1000
//calculates the prime factorization of a number
//far slower than primes2
void printFullArray(int array[]);
void printUniqueArray(int array[]);
void markNonPrimes(int array[], int k);
void setArray(int array[], int value);
int getLength(int array[]);
int main(){
	int number = 34569;
	int newnumber = number;
	int prnumbers[number];
	int factors[number];
	prnumbers[number - 1] = END;
	setArray(prnumbers, PRIME);
	factors[number - 1] = END;
	setArray(factors, UNDEFINED);
	for (int i = 2, j = 0; i <= number; i++){
		if ((newnumber % i == 0) && (prnumbers[i] != NPRIME)){
			factors[j] = i;
			j++;
			newnumber = newnumber / i;
			markNonPrimes(prnumbers, i);
			i--;
		} else if (number % i != 0) {
			markNonPrimes(prnumbers, i);
		}
	}
	printf("\n*** PR1: The prime factors of %3d are:\n", number);
	printUniqueArray(factors);
	printf("\n*** PR1: CPU time: %5lu\n", clock());
	return 0;
}
void printFullArray(int array[]){
	printf("\n");
	for (int i = 0; i <= getLength(array); i++){
		printf("%3d: %3d\n", i, array[i]);
	}
	printf("\n");
}
void printUniqueArray(int array[]){
	printf("\n");
	for (int i = 0, mult = 1; i <= getLength(array); i++){
		if ((array[i] == UNDEFINED) || (array[i] == END)){
			break;
		} else if (array[i] == array[i + 1]) {
			mult++;
		} else {
			if (mult == 1){
				printf("%3d\n", array[i]);
			} else {
				printf("%3d, multiplicity %2d\n", array[i], mult);
				mult = 1;
			}
		}
	}
	printf("\n");
}
void markNonPrimes(int array[], int k){
	for (int l = k, i = k * 2, a = getLength(array); i < a; i = i + l){
		array[i] = NPRIME;
	}
}
void setArray(int array[], int value){
	for (int i = 0, a = getLength(array); i < a; i++){
		array[i] = value;
	}
}
int getLength(int array[]){
	int i = 0;
	while (array[i] != END){
		i++;
	}
	return i;
}