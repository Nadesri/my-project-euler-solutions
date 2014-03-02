// Summation of primes
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

// Find the sum of all the primes below two million.

#include <iostream>
#include <math.h>
using namespace std;

bool isprime(unsigned long long int factor);

int main() {
	unsigned long long int result = 0;

	for (unsigned long long int i=2; i<2000000; i++) {

		if (isprime(i)) {
			result += i;
		}
	}

	cout << "Result: " << result << endl;

	return 0;
}

bool isprime(unsigned long long int factor) {

	for (unsigned long long int i=2; i<=(sqrt(factor)); i++) {
		if (factor%i==0) {
			return false;
		}
	}
	return true;

}