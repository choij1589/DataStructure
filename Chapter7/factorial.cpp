#include <iostream>
#include <ctime>
using namespace std;

unsigned int factorial(unsigned int n) {
	if (n==1) 
		return 1;
	else
		return (n*factorial(n-1));
}

unsigned int factorialIter(unsigned int n) {
	unsigned int result = 1;
	for (unsigned int i = 1; i <= n; i++)
		result *= i;
	return result;
}

int main() {
	clock_t start = clock();
	cout << "[Factorial-Recursion] Result: " << factorial(30) << endl;
	clock_t end = clock();
	cout << "[Factorial-Recursion] " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	start = clock();
	cout << "[Factorial-Iteration] Result: " << factorialIter(30) << endl;
	end = clock();
	cout << "[Factorial-Iteration] " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	return 0;
}
