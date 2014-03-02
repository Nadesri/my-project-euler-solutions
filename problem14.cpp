// Longest Collatz sequence
// Problem 14
// The following iterative sequence is defined for the set of positive integers:

// n → n/2 (n is even)
// n → 3n + 1 (n is odd)

// Using the rule above and starting with 13, we generate the following sequence:

// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

// Which starting number, under one million, produces the longest chain?

// NOTE: Once the chain starts the terms are allowed to go above one million.



#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

unsigned long collatz(unsigned long i);

int main() {

	unsigned long result;

	int start = clock();

	int counts;
	int maxcounts = 0;
	unsigned long current;
	for (int starti=500001; starti<1000000; starti+=2) {
		counts = 0;
		current = collatz(starti);
		counts++;
		while (current!=1) {
			current = collatz(current);
			counts++;
		}

		if (counts>maxcounts) {
			maxcounts = counts;
			result = starti;
		}
	}

	int end = clock();
	cout << "Result: " << result << endl;
	cout << "Time elapsed: " << ((end-start)*1000)/CLOCKS_PER_SEC << " milliseconds." << endl;
	cout << "Time Resolution: " << CLOCKS_PER_SEC << endl;
	return 0;
}

unsigned long collatz(unsigned long i) {
	if (i%2==0) {
		return i/2;
	} else {
		return i*3+1;
	}
}