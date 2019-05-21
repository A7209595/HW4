
#include <iostream>
#include <string>
#include "Complex.h"
using namespace std;

int main()
{
	// Create and initialize two Complex numbers r1 and r2.
	Complex r1(3, 4);
	Complex r2(2, -4);
	Complex r3(3, -1);
	Complex r4(4, 3);
	Complex r5(5, 6);
	// Test relational operators
	

	// Test toString, add, subtract, multiply, and divide operators
	cout << "first=" << r1 + (r2 * r3) << endl;
	cout << "second=" << r4 - r5 << endl;
	cout << "++first=" << ++(r1 + (r2 * r3)) << endl;
	cout << "--second=" << --(r4 - r5) << endl;
	
	system("pause");
	return 0;
}