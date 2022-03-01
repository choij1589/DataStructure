#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double slowPower(double x, int n) {
	double res = 1.;
	for (int i = 0; i < n; i++)
		res *= x;
	return res;
}

double power(double x, int n) {
	if (n==0)
		return 1.;
	else if (n%2 == 0)
		return power(x*x, n/2);
	else
		return x*power(x*x, (n-1)/2);
}

int main() {
	clock_t start, end;

	start = clock();
	cout << "pow(2, 500) = " << pow(2, 500) << endl;
	end = clock();
	cout << "took " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	start = clock();
	cout << "slowPower(2, 500) = " << slowPower(2, 500) << endl;
	end = clock();
	cout << "took " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	start = clock();
	cout << "power(2, 500) = " << power(2, 500) << endl;
	end = clock();
	cout << "took " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	return 0;
}

