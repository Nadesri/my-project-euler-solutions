// Lattice paths
// Problem 15
// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

// How many such routes are there through a 20×20 grid?

#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

int main() {

	unsigned long long result=0; // Starter assumes the result is some integer (this probably isn't always the case)

	int start = clock();

	const int n = 20+1;

	unsigned long long mygrid[n][n];

	// Initialize grid
	for (int i=0; i<n; i++) {
		mygrid[i][0] = 1;
		mygrid[0][i] = 1;
	}

	for (int i=1; i<n; i++) {
		for (int j=1; j<n; j++) {
			mygrid[i][j] = mygrid[i-1][j]+mygrid[i][j-1];
		}
	}
	result = mygrid[n-1][n-1];

	int end = clock();
	cout << "Result: " << result << endl;
	cout << "Time elapsed: " << ((end-start)*1000)/CLOCKS_PER_SEC << " milliseconds." << endl;
	cout << "Time Resolution: " << CLOCKS_PER_SEC << endl;
	return 0;
}