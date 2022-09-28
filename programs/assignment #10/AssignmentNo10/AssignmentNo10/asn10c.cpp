// Fritz Ammon
// Assignment #10
// Section #1001
//
// This program reads a series of integers from a file
// using an ifstream object and, while keeping track of
// how many numbers were read, calculates the sum, average,
// variance, and standard deviation. It also finds all
// prime numbers, and prime numbers along with how many
// factors that number has.
//
// Besides prompting the user for the name of a file to
// read from, the program writes all data and results
// to a file ammonfhw10.out using an ofstream object.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int getSum(const int set[], int size);
double getAverage(int sum, int size);
double getVariance(double average, int set[], int size);
int getMin(const int set[], int size);
int getMax(const int set[], int size);
int getNoFactors(int num);

int main()
{
	int set[50] = {0}; // An array that holds the series of integers.
	int size = 0; // The length of set, or the number of integers read.
	double average = 0.0; // The sum of all numbers in set divided by size.
	double variance = 0.0; // The sum of all numbers in set minus the average divided by size.
	int noFactors = 0; // The number of factors found for a nonprime number.
	int noNonPrime = 0; // The number of nonprime numbers found in set.
	string fileName = ""; // The name of the file in which to read the series of integers.
	ifstream inFile; // The ifstream object that will open the file for reading.
	ofstream otFile; // The ofstream object that will open a file for writing results.

	// Prompt user for name of file.
	cout << "Please enter name of input file\n";
	cin >> fileName; // Read name of file into string object.

	inFile.open(fileName.c_str()); // Open file with c-string version of string object.

	// Read in the series of integers into set.
	while (inFile >> set[size])
		size++;

	inFile.close(); // Close the file since we're done reading from it.

	average = getAverage(getSum(set, size), size); // Calculate average of set.
	variance = getVariance(average, set, size); // Calculate variance of set.

	otFile.open("ammonfhw10.out"); // Create or open the file to write to.

	otFile << "Fritz Ammon  Assignment #10  Section #1001";
	
	otFile << endl << endl;

	otFile << "NUMBERS READ FROM INPUT FILE\n";

	// Print all of the numbers that were read from inFile.
	for (int i = 0; i < size; i++)
	{
		if (i % 4 == 0) // Make sure only 4 numbers are printed per line.
			otFile << endl;

		otFile << setw(10) << set[i]; // Print the number right-aligned.
	}

	otFile << endl << endl;

	otFile << fixed << showpoint;
	otFile << setprecision(3); // Set the floating point precision to 3.

	// Print the calculated numbers.
	otFile << left << setw(20) << "#values read:"
		   << right << setw(12) << size << endl; // Print the length of the array.
	otFile << left << setw(20) << "average:"
		   << right << setw(12) << average << endl;
	otFile << left << setw(20) << "variance:"
		   << right << setw(12) << variance << endl;
	otFile << left << setw(20) << "standard deviation:"
		   << right << setw(12) << sqrt(variance) << endl; // Calculate and print std deviation.
	otFile << left << setw(20) << "largest value:"
		   << right << setw(12) << getMax(set, size) << endl; // Find largest number and print.
	otFile << left << setw(20) << "smallest value:"
		   << right << setw(12) << getMin(set, size); // Find smallest number and print.

	otFile << endl << endl;

	otFile << "PRIME NUMBERS\n";

	// Look through the set for prime numbers and print them.
	for (int i = 0, c = 0; i < size; i++)
	{
		// Prime number must have two factors, 1 and itself.
		if (set[i] > 1 && (noFactors = getNoFactors(set[i])) == 2)
		{
			if (c++ == 4) // Only print 4 per line.
			{
				otFile << endl;
				c = 1;
			}

			otFile << setw(10) << set[i]; // Print prime number right-aligned.
		}
	}

	otFile << endl << endl;

	otFile << setw(10) << "NONPRIME" << endl;
	otFile << setw(10) << "NUMBER";
	otFile << setw(15) << "# FACTORS" << endl;

	// Print the nonprime numbers with the number of factors they have.
	for (int i = 0; i < size; i++)
	{
		// Any number that has more than two factors.
		if (set[i] > 1 && (noFactors = getNoFactors(set[i])) > 2)
		{
			otFile << setw(10) << set[i];
			otFile << setw(15) << noFactors << endl; // Show number of factors.
			noNonPrime++;
		}
	}

	otFile << "# of positive, nonprime values: "
		   << noNonPrime << endl; // Print number of composite numbers found.

	otFile.close();

	return 0;
}

int getSum(const int set[], int size)
// set is an array holding a series of integers.
// size is the length of the array.
// Returns the sum of all the integers in the array.
{
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += set[i];

	return sum;
}

double getAverage(int sum, int size)
// sum is the sum of all integers in a set.
// size is the number of integers that were added.
// Returns the average of a set of integers.
{
	return sum / size;
}

double getVariance(double average, int set[], int size)
// average is the average number of set.
// set is an array holding the series of integers.
// size is the length of the array.
// Returns the variance of set.
{
	double variance = 0.0;

	for (int i = 0; i < size; i++)
		variance += pow(set[i] - average, 2.0);

	return variance / size;
}

int getMin(const int set[], int size)
// set is an array holding a series of integers.
// size is the length of the array.
// Returns the smallest number in set.
{
	int min = 0;

	for (int i = 0; i < size; i++)
	{
		if (set[i] < min)
			min = set[i];
	}

	return min;
}

int getMax(const int set[], int size)
// set is an array holding a series of integers.
// size is the length of the array.
// Returns the largest number in set.
{
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		if (set[i] > max)
			max = set[i];
	}

	return max;
}

int getNoFactors(int num)
//  num is the number used in counting the number of factors.
// Used to tell whether or not num is prime or composite.
// Returns the number of factors num holds.
{
	int noFactors = 0;

	// Start at 1 because we cannot divide by 0.
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0) // Evenly divisible.
			noFactors++;
	}

	return noFactors;
}