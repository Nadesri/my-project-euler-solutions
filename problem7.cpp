// 10001st prime
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10001st prime number?

#include <iostream>
using namespace std;
bool isprime(unsigned long long int factor);

int main() {
	int numprimes = 0;
	int i=1;
	while (numprimes<10001) {
		i++;
		if (isprime(i)) {
			numprimes++;
		}
	}

	cout << "Result: " << i << endl;
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