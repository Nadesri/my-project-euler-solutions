// Largest Palindrome Number
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
using namespace std;
bool ispalindrome(int a);

int main() {

	int result = 0;
	int current;
	for (int j=1; j<1000; j++) {
		for (int i=1; i<1000; i++) {
			current = i*j;
			if (ispalindrome(current)&&(current>result)) {
				result = current;
			}
		}
	}

	cout << "Result: " << result << endl;

	return 0;
}

bool ispalindrome(int a) {
	if (a<10) {
		return true; // all single digit numbers are palindromes.
	}

	int window    = 10;
	int numdigits = 2;
	while ((window*10)<=a) {
		window *= 10;
		numdigits++;
	}

	// cout << "Number of digits: " << numdigits << endl;

	int *forward  = new int[numdigits]();
	int digit;

	for (int i=0; i<numdigits; i++) {
		digit       = a%10;
		forward[i]  = digit;

		a /= 10;
	}

	bool result = true;
	for (int i=0; i<numdigits; i++) {
		result = result && (forward[i]==forward[numdigits-i-1]);
	}

	return result;
}