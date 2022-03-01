#include <iostream>
#include <ctime>
using namespace std;

unsigned int fib(unsigned int n) {
	if (n < 2) 
		return n;
	return fib(n-1) + fib(n-2);
}

unsigned int fibIter(unsigned int n) {
	if (n < 2)
		return n;
	else {
		int tmp, current=1, last=0;
		for (int i = 2; i <= n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

int main() {
	clock_t start, end;

	start = clock();
	cout << "fib(20) = " << fib(20) << endl;
	end = clock();
	cout << "took " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	start = clock();
	cout << "fibIter(20) = " << fibIter(20) << endl;
	end = clock();
	cout << "took " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	return 0;
}
