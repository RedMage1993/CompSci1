// Fritz Ammon
// Section #1001
// Assignment #7
//
// Description: This program reads a file containing student grades data
// via the Linux redirection operator and provides the user with class
// statistics, including the progress of each student.
//
// Input: The data file is seperated in parts by a sentinel.
// The program first reads a first set of numbers representing the
// possible points to earn for each assignment given so far. Then, it will
// read a student ID code consisting of 4 characters (1 letter, 2 numbers,
// and 1 more letter). The program reads scores for each student until the
// sentinel is reached, and then the process repeats until the end-of
// -file bit is signaled.
//
// Process: Computes the sum of possible points that a student can earn,
// the sum of points earned by each student, and then finds each of those
// student's percentage and letter grade. The program also keeps track of
// the number of students in the class in and uses this number to calculate
// the class average (percentage and points).
//
// Output: Prints out name, assignment and section number, followed by a
// blank line. The program then displays labels for an ID code, points earned,
// percentage, and grade for each student. The ID code is left justified while
// all other computed values are right justified. Then, the class size, total
// points possible, average point total, and average percentage are printed
// out with values right justified.

#include <iostream>
#include <iomanip>

using namespace std;

const int SENTINEL = -1; // Used to indicate that the end of a part
			 // of the file has been reached.

int main()
{
	// c1 and c4 are letters, c2 and c3 are numbers.
	char c1, c2, c3, c4; // Make up a 4-character student ID code.
	int points; // The points to be read one at a time.
	int possiblePoints = 0; // The sum of the points possible per assignment.
	int pointsEarned; // The sum of the points earned on each assignment.
	double score; // Calculated by pointsEarned / possiblePoints.
	int noStudents = 0; // The class size, or number of students in the class.
	int avgPointTotal = 0; // The sum of each student's pointsEarned divided by noStudents.
	double avgPercentage = 0.0; // The sum of each student's percentage divided by noStudents.

	cout << fixed << showpoint;
	cout << setprecision(2);

	cout << "Fritz Ammon   Assignment #7   Section #1001\n\n";

	// Print out labels.
	cout << left << setw(15) << "ID CODE";
	cout << right << setw(6) << "POINTS";
	cout << setw(10) << "PCT";
	cout << setw(10) << "GRADE" << endl;

	cin >> points; // Read initial points.
	while (points != SENTINEL) // Until sentinel is reached.
	{
		possiblePoints += points;
		cin >> points;
	}

	// Continue loop while cin has not signaled any errors and
	// and temp is not equal to the sentinel.
	do
	{
		cin >> c1 >> c2 >> c3 >> c4; // Read the student ID code.

	        pointsEarned = 0; // Reset for new student's total.

		cin >> points; // Read all of the student's scores.
		while (points != SENTINEL)
         	{
			pointsEarned += points;
			cin >> points;
		}

		// Calculate score (must make division double)
		score = static_cast<double> (pointsEarned) / possiblePoints * 100;

		// Print out student's ID, points earned, percentage, and letter grade.
		cout << c1 << c2 << c3
		     << left << setw(12) << c4;
		cout << right << setw(6) << pointsEarned;
		cout << setw(10) << score;
		cout << setw(10);

		// Print out appropriate letter grade.
		switch (static_cast<int> (score / 10))
		{
		case 10:
		case 9:		// 90 - 100
			cout << 'A';
			break;
		case 8:		// 80 - 89
			cout << 'B';
			break;
		case 7:		// 70 - 79
			cout << 'C';
			break;
		case 6:		// 60 - 69
			cout << 'D';
			break;
		default:	// 0 - 59
			cout << 'F';
			break;
		}

		cout << endl;

		// Keep track of class stats.
		avgPointTotal += pointsEarned;
		avgPercentage += score;

		noStudents++;
	} while (!cin.eof()); // We don't need to error-error check, just use eof.

	cout << endl;

	// Print out class statistics with labels.
	cout << left << setw(28) << "Class size:"
		 << right << setw(6) << noStudents << endl;
	cout << left << setw(28) << "Total points possible:"
		 << right << setw(6) << possiblePoints << endl;
	cout << left << setw(28) << "Average point total:"
		 << right << setw(6) << static_cast<double> (avgPointTotal) / noStudents << endl;
	cout << left << setw(28) << "Average percentage:"
		 << right << setw(6) << avgPercentage / noStudents << endl;

	return 0;
}