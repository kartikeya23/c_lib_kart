#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"

// Structure Definition
	int numOfDigits(unsigned int num);
	unsigned int factorial(int n);
	unsigned int perm(int n, int r);
	unsigned int comb(int n, int r);
	unsigned int lcm(unsigned int num1, unsigned int num2);
	unsigned int hcf(unsigned int num1, unsigned int num2);
	void printPascal(int n);

unsigned int factorial(int n){
	//Using recursion, finds the factorial of the number
	// Equivalent to "!" operation
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

unsigned int perm(int n, int r){
	// nPr = n! / (n-r)!
	return (factorial(n) / factorial(n-r));
}

unsigned int comb(int n, int r){
	// nCr = n! / r! (n-r)! = nPr / r!
	return (perm(n, r) / factorial(r));
}

int numOfDigits(unsigned int num){
	int dgt = 0;
	while((num /= 10) != 0)
		dgt++;
	return dgt + 1;
}

unsigned int hcf(unsigned int num1, unsigned int num2){
	int max = 1, i;
	for (i = 2; i <= abs(num2 - num1);  ++i){
		if (num1 % i == 0 && num2 % i == 0){
			if (i > max)
				max = i;
		}
	}
	return max;
}

unsigned int lcm(unsigned int num1, unsigned int num2){
	return num1 * num2 / hcf(num1, num2);
}

void printPascal(int n){
	int x, i;
	long int pascal[n+1][n+1];
	for (i = 0; i <= n; ++i){
		if (i == 0)
			pascal[i][0] = 1;
		else{
			pascal[i][0] = pascal[i][i] = 1;
			for (x = 1; x < i; ++x)
				pascal[i][x] = pascal[i-1][x] + pascal[i-1][x-1];
		}
	}
	for (i = 0; i <= n; ++i){
		for (x = 0; x <= i; ++x){
			printf("%d ", pascal[i][x]);
		}
		printf("\n");
	}
	return;
}
