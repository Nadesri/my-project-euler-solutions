// Largest Prime Factor
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <time.h>
using namespace std;

bool isprime(unsigned long long int factor);

int main() {
	int start = clock();
	unsigned long long int i=2;
	unsigned long long int factor;
	unsigned long long int mynumber = 600851475143;

	while (i<mynumber) {
		if (mynumber%i==0) {
			factor = mynumber/i;
			if (isprime(factor)) {
				cout << "Found the result with factor: " << i << endl;
				i=mynumber; // Break while loop.
			}
		}
		i++;
	}

	cout << "Result: " << factor << endl;
	int end = clock();
	cout << "Time Elapsed: " << (end-start)*1000/CLOCKS_PER_SEC << " milliseconds." << endl;
	return 0;
}

bool isprime(unsigned long long int factor) {

	for (unsigned long long int i=2; i<factor; i++) {
		if (factor%i==0) {
			return false;
		}
	}
	return true;

}