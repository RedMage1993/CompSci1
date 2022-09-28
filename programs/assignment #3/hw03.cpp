// Fritz Ammon
// Assignment #3
// Section #1001
//
// Design an interactive program to read 6 integer values representing a, b, c, d, e, and f, respectively.
// The program should compute the values of x and y using Cramer's rule. As output it should display the
// equations being solved and the solutions for x and y, appropriately labeled.

#include <iostream>

using namespace std;

int main()
{
	int a, b, c; // the numeric constants of the first equation
	int d, e, f; // the numeric constants of the second equation
	double x, y; // the values to be computed

	cout << "Fritz Ammon  Assignment #3  Section 1001\n";

	cout << "Enter the integer values for equation 1 (a, b, c)\n"; // prompt for a, b, and c
	cin >> a >> b >> c; // read three integers and store into a, b, and c

	cout << "Enter the integer values for equation 2 (d, e, f)\n"; // prompt for d, e, and f
	cin >> d >> e >> f; // read three integers and store into d, e, and f

	// calculate x and y using Cramer's rule
	x = (c * e - f * b) / (a * e - d * b);
	y = (a * f - d * c) / (a * e - d * b);

	// print the original equations after substituting the 6 numeric constants
	cout << "In the equations:\n"
	     << a << "x + " << b << "y = " << c << endl
	     << d << "x + " << e << "y = " << f << endl;

	// print the computed values x and y
	cout << "x = " << x << endl
	     << "y = " << y << endl; 

	return 0;
}