// Fritz Ammon
// Assignment #4
// Section #1001
//
// Design an interactive program to read 5 double values representing the exterior length of a wall (meters),
// the exterior width of a wall (meters), the height of the wall (meters), the thickness of a wall (centimeters) and,
// the width of the opening (meters). The width of the opening is assumed to be smaller than that of the length of a wall.
// The program should compute the amount of concrete needed (cubic meters), the estimated cost of the concrete required,
// estimated labor, overhead, and total cost of the job. As output it should display a detailed job cost estimate
// formatted as requested.
//
// Equations used for this program:
// w * l * h = entire volume
// (w - thickness) * (l - thickness) * h = inner volume
// thickness * w * h = opening
// entire volume - inner volume - opening = concrete required

#include <iostream>
#include <iomanip>

using namespace std;

const double METER_PER_CM = 0.01; // one centimeter equals 0.01 meters (multiply by this to change to meters)
const double COST_CONCRETE_PER_CU = 81.00; // multiply this by concrete required (cubic meters)
const double COST_LABOR_OF_CONCRETE = 0.60; // multiply this by concrete cost to get cost of labor
const double COST_OVERHEAD_OF_LABOR = 0.20; // multiply this by costs of labor to get overhead and other costs

int main()
{
	double lenOfWall = 0.0; // exterior length of the wall in meters
	double wdthOfWall = 0.0; // exterior width of the wall in meters
	double hghtOfWall = 0.0; // height of wall in meters
	double thickness = 0.0; // thickness of wall in centimeters
	double wdthOfOpen = 0.0; // width of opening on long wall
	double concNeeded = 0.0; // concrete needed for the job in cubic meters
	double costOfConc = 0.0; // cost of concrete needed
	double costOfLabor = 0.0; // the cost of the labor
	double costOfOverhead = 0.0; // other costs and overhead
	double costTotal = 0.0; // the sum of all of the costs

	// Input
	cout << "Enter exterior length of wall in meters: "; // prompt user for length of wall
	cin >> lenOfWall; // read length of wall

	cout << "Enter exterior width of wall in meters: "; // prompt user for width of wall
	cin >> wdthOfWall; // read width of wall

	cout << "Enter height of wall in meters: "; // prompt user for height of wall
	cin >> hghtOfWall; // read height of wall

	cout << "Enter thickness of wall in centimeters: "; // prompt user for thickness of walls
	cin >> thickness; // read thickness of walls

	cout << "Enter length of opening in meters: "; // prompt user for width/length of opening
	cin >> wdthOfOpen; // read width/length of opening
	cout << endl;
	// end of Input

	// Process
	// calculate concrete needed
	concNeeded = (lenOfWall * wdthOfWall * hghtOfWall); // the entire solid
	concNeeded -= ((lenOfWall - (thickness * METER_PER_CM) * 2) * (wdthOfWall - (thickness * METER_PER_CM) * 2) * hghtOfWall); // remove smaller solid
	concNeeded -= (thickness * METER_PER_CM * wdthOfOpen * hghtOfWall); // remove opening

	// calculate costs of complete job
	costOfConc = COST_CONCRETE_PER_CU * concNeeded; // $81.00 per cubic meter of concrete
	costOfLabor = COST_LABOR_OF_CONCRETE * costOfConc; // 60% of cost of concrete
	costOfOverhead = COST_OVERHEAD_OF_LABOR * costOfLabor; // 20% of the cost of labor
	costTotal = costOfConc + costOfLabor + costOfOverhead; // total estimated cost for the job
	// end of Process

	// Output
	cout << "Fritz Ammon  Section #1001  Assignment #4" << endl;

	cout << setfill('-'); // padding will be hyphens
	cout << setw(47) << '\n'; // set field width to 47

	cout << "JOB COST ESTIMATE" << endl;
	cout << "Wall Dimensions:" << endl;
	
	cout << fixed << showpoint; // force zeros and point to show
	cout << setprecision(3); // 3 digits after whole number

	cout << setfill(' ');

	// display all of the dimensions of the solid
	// left justifying labels and right justifying numbers
	cout << left << setw(30) << " Length:" << right;
	cout << setw(7) << lenOfWall << " m" << endl;

	cout << left << setw(30) << " Width:" << right;
	cout << setw(7) << wdthOfWall << " m" << endl;

	cout << left << setw(30) << " Height:" << right;
	cout << setw(7) << hghtOfWall << " m" << endl;

	cout << left << setw(30) << " Thickness:" << right;
	cout << setw(7) << thickness * METER_PER_CM << " m" << endl;

	cout << left << setw(30) << " Opening:" << right;
	cout << setw(7) << wdthOfOpen << " m" << endl << endl;

	// display amount of concrete needed
	cout << left << setw(30) << "Estimated concrete needed:" << right;
	cout << setw(7) << concNeeded << " cu m" << endl << endl;

	cout << setprecision(2); // 2 digits after whole number

	cout << left << setw(36) << "Estimated concrete cost:" << right;
	cout << '$' << setw(9) << costOfConc << endl;

	cout << left << setw(36) << "Estimated labor cost:" << right;
	cout << '$' << setw(9) << costOfLabor << endl;

	cout << left << setw(36) << "Estimated overhead cost:" << right;
	cout << '$' << setw(9) << costOfOverhead << endl;

	cout << left << setw(36) << "Estimated total cost:" << right;
	cout << '$' << setw(9) << costTotal << endl;

	cout << setfill('-');
	cout << setw(47) << '\n';
	// end of Output

	return 0;
}