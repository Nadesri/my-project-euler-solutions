// Special Pythagorean triplet
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a, b, c;

	for (a=1; a<1000; a++) {
		for (b=1; b<1000; b++) {
			for (c=1; c<1000; c++) {
				if ((a+b+c)==1000) {
					if (pow(a,2)+pow(b,2)==pow(c,2)) {
						cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
						cout << "Therefore, the result is: " << a*b*c << endl;
						break;
					}
				}
			}
		}
	}

	return 0;
}