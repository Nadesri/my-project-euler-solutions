// Power digit sum
// Problem 16
// 215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

// What is the sum of the digits of the number 21000?


#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

int main() {

	int result; // Starter assumes the result is some integer (this probably isn't always the case)
	int digits[500] = {0};
	int head;

	int start = clock();

	digits[0] = 1;
	for (int i=0; i<1000; i++) {
		// Doubling operation
		for (int j=0; j<(500); j++) {
			digits[j] += digits[j];
		}
		// Carry over the digits to the next guy
		for (int j=0; j<500-1; j++) {
			digits[j+1] += digits[j]/10;
			digits[j] = digits[j]%10;
		}
	}

	result = 0;
	for (int i=0; i<500; i++) {
		result += digits[i];
	}

	int end = clock();
	cout << "Result: " << result << endl;
	cout << "Time elapsed: " << ((end-start)*1000)/CLOCKS_PER_SEC << " milliseconds." << endl;
	cout << "Time Resolution: " << CLOCKS_PER_SEC << endl;
	return 0;
}