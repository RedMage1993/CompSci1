// Author: Fritz Ammon
// Date: 10/18/2012
// Program: Assignment #6
// Description: The program will read multiple data sets and generate a report for each
// followed by a summary. The program will use batch processing for data input.
//
// Input (via batch processing)
// The file containing the data is going to start with the number of lines following
// that number, which tells us how many students to process.
// Each line will contain the student's identification number (int), first name initial (char),
// surname initial (char), and # of credits requested (int).
// If the number of credits is valid, there will be a residency code (char).
// If the residency code is N (for non-resident, and not R for resident), then there will be
// a housing code. If the housing code is H [for on-campus housing, and not O for off-campus (no fee)],
// then there is a meal code. If the meal code is M (for meals, and not N for no meals), then there is a fee.
//
// Process
// Students are allowed to register for 1-21 credits (inclusive).
// Resident students pay $130.00 per credit, non pay $285.00 per credit plus $6200.00 per semester for out-of-state fees.
// Housing is only for non-resident students and is $3500.00 per semester.
// Meals are only available to non-residents with housing for $2000.00 per semester.
//
// Output
// Will display name, section #, and assignment # follow by at least 1 blank line.
// For each student (line/data set), display a report with labels left justified. Values
// should be right justified.
// The labels should always include student ID# and initials.
// If the number of requested credits was invalid, display an appropriate error message with credits requested.
// If the number of requested credits was okay, display residency status, credits requested, and tuition (including
// out-of-state fees for non-residents).
// If there are any other fees, display them only if they are non-zero.
// Display the total due.
// There should be a blank between each student's report and final total report.
// The final total report at the end should include the valid and invalid request count, and
// total fees due.
// All dollar amounts should start with a $ and have 2 digits after the decimal.

#include <iostream>
#include <iomanip>

using namespace std;

int CREDIT_REQ_MIN = 1; 	  // The minimum number of credits that can be requested.
int CREDIT_REQ_MAX = 21;	  // The maximum number of credits that can be requested.
double COST_CREDIT_RES = 130.00;  // Cost per credit for residents.
double COST_CREDIT_NON = 285.00;  // Cost per credit for non-residents.
double NON_SEM_FEE = 6200.00; 	  // Out-of-state fee non-resident pays per semester.
double HOUSING_PER_SEM = 3500.00; // Cost for housing for non-residents per semester.
double MEALS_PER_SEM = 2000.00;   // Cost of meals for housing non-residents per semester.

int main()
{
    int noLinesInFile = 0; 	// The number of lines, or students, to make a report for.
    int studentId = 0;		// The idenitification number of the student.
    char firstNameInit = '\0';  // The initial of the student's first name.
    char lastNameInit = '\0'; 	// The initial of the student's last name.
    int noCreditsReq = 0; 	// The number of credits requested by the student.
    char resCode = '\0'; 	// The student's residency code.
    char housingCode = '\0'; 	// A non-resident's housing code.
    char mealCode = '\0'; 	// The meal code of a non-resident who has housing.
    double stuTotalDue = 0.0; 	// Total amount due for semester for student, mainly tuition.
    int noValidReq = 0; 	// Number of valid credit requests.
    int noInvalidReq = 0; 	// Number of invalid credit requests.
    double finalTotalDue = 0.0; // Final amount due inlcuding every student.
    
    cout << "Fritz Ammon   Assignment #6   Section #1001\n\n";
    
    cout << fixed << showpoint;
    cout << setprecision(2);
    
    cin >> noLinesInFile; // Get the number of lines in the input file.
    
    // Execute the following set of commands for every student/line.
    for (int line = 0; line < noLinesInFile; line++)
    {
        cin >> studentId;	// Get the student Id.
        cin >> firstNameInit;	// Get the first name initial.
        cin >> lastNameInit;	// Get the last name initial.
        
	// Display the student Id and initials right justified
	// with appropriate labels left justified.
        cout << left << setw(28) << "Student #:"
             << right << setw(15) << studentId << endl;
        cout << left << setw(28) << "Initials:"
             << right << setw(14) << firstNameInit << lastNameInit << endl;
             
        cin >> noCreditsReq; // Get the number of credits requested.
        if (noCreditsReq < CREDIT_REQ_MIN || noCreditsReq > CREDIT_REQ_MAX)
        { // Number of credits requested is out of bounds.
            cout << "Sorry your request for " << noCreditsReq << " credits is invalid\n\n";
            noInvalidReq++; // Increment the number of invalid requests.
            continue;	    // Skip to the next student request.
        }
        
        cin >> resCode; // Get the residency code.
        if (resCode == 'N')
        { // Non-resident.
            stuTotalDue += noCreditsReq * COST_CREDIT_NON; // Calculate the tuition.
            stuTotalDue += NON_SEM_FEE;			   // Include non-resident fee.
            
	    // Display residency status.
            cout << left << setw(28) << "Residency status:"
                 << right << setw(15) << "non-resident" << endl;
        }
        else
        { // Resident.
            stuTotalDue += noCreditsReq * COST_CREDIT_RES; // Calculate tuition, no fees.
            
	    // Display residency status.
            cout << left << setw(28) << "Residency status:"
                 << right << setw(15) << "resident" << endl;
        }
        
	// Display the number of requested credits.
        cout << left << setw(28) << "Credits:"
             << right << setw(15) << noCreditsReq << endl;
             
	// Display the tuition total.
        cout << left << setw(28) << "Tuition:"
             << '$' << right << setw(14) << stuTotalDue << endl;
             
        if (resCode == 'N') // If there was a non-resident, then there is a housing code.
        {
            cin >> housingCode; // Get the housing code.
            if (housingCode == 'H')
            { // Student is on campus.
		// Display housing fee.
                cout << left << setw(28) << "Housing:"
                     << '$' << right << setw(14) << HOUSING_PER_SEM << endl;
                
                stuTotalDue += HOUSING_PER_SEM; // Add housing fee to student total due.
                
                cin >> mealCode; // Get meal code.
                if (mealCode == 'M')
                { // Student gets meals.
		    // Display meal fee.
                    cout << left << setw(28) << "Meals:"
                         << '$' << right << setw(14) << MEALS_PER_SEM << endl;
                    
                    stuTotalDue += MEALS_PER_SEM; // Add meal fee to student total due.
                }
            }
        }
        
	// Display student total due.
        cout << left << setw(28) << "Total due:"
             << '$' << right << setw(14) << stuTotalDue
             << endl << endl;
        
        noValidReq++; // Increment number of valid requests.
        
        finalTotalDue += stuTotalDue; // Include student total in final total due.
        stuTotalDue = 0; // Reset student total for next student request.
    }
    
    // Display valid request and invalid request count and total fees due.
    cout << "FINAL TOTALS:\n";
    cout << left << setw(28) << "Valid request count:"
         << right << setw(15) << noValidReq << endl;
    cout << left << setw(28) << "Invalid request count:"
         << right << setw(15) << noInvalidReq << endl;
    cout << left << setw(28) << "Total fees due:"
         << '$' << right << setw(14) << finalTotalDue
         << endl;
    
    return 0;
}
