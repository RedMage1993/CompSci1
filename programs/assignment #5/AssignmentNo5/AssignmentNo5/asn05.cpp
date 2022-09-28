// Fritz Ammon
// Section #1001
// Assignment #5
//
// Description: This program's main purpose is to display given
// fractions by the user (via c input stream) in a formatted manner
// on the screen.
//
// Input: The program will prompt the user for a fraction and read it.
// The program will read in the numerator as an int (num), read or
// ignore the forward slash, and finally read the denominator as an int (den).
// The user may include whitespaces in the line with the given fraction.
//
// Process: If the fraction is valid, meaning that denominator is not
// zero and that the numerator and denominator exists, then...
// if the fraction is negative, the signed integer will be the numerator
// if both numerator and denominator are negative, then the fraction is positive
// if the fraction is improper, then it should be converted to a whole or mixed number
// No simplifying will be done.
//
// Output: My name, section number, and assignment number will be displayed. If valid,
// the given fraction will be printed without any whitespaces, followed by " = "
// and the formatted fraction. If the formatted fraction includes a whole number,
// then there will be a space between the whole number and the numerator.
// If invalid, display only the input values and an appropriate error message.

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int num = 0; // Numerator of given fraction.
	int den = 0; // Denominator of given fraction.
	int quo = 0; // Integral quotient of fraction (whole number result from division).
	int rem = 0; // Remainder of division.

	// Display name, assignment and section number.
	cout << "Fritz Ammon    Assignment #5    Section 1001\n";

	// Prompt the user for the fraction.
	cout << "Please enter a fraction (numerator / denominator)\n";
	cin >> num; // Read the numerator.
	cin.ignore(200, '/'); // Ignore the foreward slash.
	cin >> den; // Read the denominator.

	// Display the given fraction.
	cout << num << '/' << den;

	if (den == 0) // Validate fraction.
		cout << " is an invalid fraction and cannot be reformatted";
	else if (num == 0) // Entire fraction is zero. (optional catch)
		cout << " = 0";
        else
        { // Fraction is valid and not zero.
            cout << " = ";

            if (num < 0 ^ den < 0) // If one but not both are negative
                cout << '-';       // print a minus sign.
        
	    quo = abs(num / den); // Get the positive quotient.
	    rem = abs(num % den); // Get the positive remainder.

	    // Display appropriate formatted fraction.
	    if (quo > 0) // There was a whole number.
                cout << quo << ' '; // Add a space in case there is a remainder.
            if (rem > 0) // There was a remainder.
                cout << rem << '/' << abs(den); // Make sure den is positive.
        }

	cout << endl;

	return 0;
}