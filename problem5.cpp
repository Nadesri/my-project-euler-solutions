// Smallest Multiple
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>
using namespace std;
bool isprime(unsigned long long int factor);

int main() {
	int maxnumber = 20;
	int result    = 1;

	for (int i=2; i<=maxnumber; i++) {
		if (result%i!=0) {
			for (int j=2; j<=i; j++) {
				if (((result*j)%i)==0) {
					result *= j;	
				}
			}
		}
	}
	cout << endl;

	cout << "Result: " << result << endl;
	return 0;
}