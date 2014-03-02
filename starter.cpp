// Project Euler Starter Template. Includes timing function (and maybe other features, added as needed)


#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

int main() {

	int result; // Starter assumes the result is some integer (this probably isn't always the case)

	int start = clock();

	// Put your code in here.

	int end = clock();
	cout << "Result: " << result << endl;
	cout << "Time elapsed: " << ((end-start)*1000)/CLOCKS_PER_SEC << " milliseconds." << endl;
	cout << "Time Resolution: " << CLOCKS_PER_SEC << endl;
	return 0;
}