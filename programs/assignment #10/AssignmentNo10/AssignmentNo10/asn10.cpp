//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//void printLabelData(ofstream& stream, char label[]);
//int getNoFactors(int value);
//
//int main()
//{
//	int values[50] = {0};
//	string fileName = "";
//	int valuesLen = 0;
//	double average = 0.0;
//	double variance = 0.0;
//	int valueMin = 0;
//	int valueMax = 0;
//	int noFactors = 0;
//	int noNonPrime = 0;
//	ifstream inData;
//	ofstream otData;
//
//	cout << "Please enter name of input file\n";
//	cin >> fileName;
//
//	inData.open(fileName.c_str());
//
//	while (inData >> values[valuesLen])
//	{
//		average += values[valuesLen];
//
//		if (values[valuesLen] > valueMax)
//			valueMax = values[valuesLen];
//
//		if (values[valuesLen] < valueMin)
//			valueMin = values[valuesLen];
//
//		valuesLen++;
//	}
//
//	average /= valuesLen;
//	inData.close();
//
//	otData.open("ammonfhw10.out");
//
//	otData << fixed << showpoint;
//	otData << setprecision(3);
//
//	otData << "Fritz Ammon  Assignment #10  Section #1001\n\n";
//	otData << "NUMBERS READ FROM INPUT FILE\n";
//
//	for (int value = 0, count = 0; value < valuesLen; value++)
//	{
//		otData << setw(8) << values[value];
//		variance += pow(values[value] - average, 2.0);
//
//		if (++count == 4)
//		{
//			count = 0;
//			otData << endl;
//		}
//	}
//
//	variance /= valuesLen;
//	otData << endl << endl;
//
//	printLabelData(otData, "# values read:");
//	otData << valuesLen << endl;
//
//	printLabelData(otData, "average:");
//	otData << average << endl;
//
//	printLabelData(otData, "variance:");
//	otData << variance << endl;
//
//	printLabelData(otData, "standard deviation:");
//	otData << sqrt(variance) << endl;
//
//	printLabelData(otData, "largest value:");
//	otData << valueMax << endl;
//
//	printLabelData(otData, "smallest value:");
//	otData << valueMin << endl;
//
//	otData << "\nPRIME NUMBERS\n";
//	for (int value = 0, count = 0; value < valuesLen; value++)
//	{
//		noFactors = getNoFactors(values[value]);
//		if (noFactors == 2)
//		{
//			otData << setw(8) << values[value];
//
//			if (++count == 4)
//			{
//				count = 0;
//				otData << endl;
//			}
//		}
//	}
//
//	otData << endl << endl;
//
//	otData << setw(8) << "NONPRIME" << endl;
//	otData << setw(8) << "NUMBER"
//		   << setw(15) << "# FACTORS" << endl;
//
//	// swap method -- putll all non prime in the back of array
//	// if not prime, swap with end of array - noNonPrime, increase noNonPrime
//
//	for (int value = 0; value < valuesLen; value++)
//	{
//		noFactors = getNoFactors(values[value]);
//		if (noFactors > 2)
//		{
//			otData << setw(8) << values[value];
//			otData << setw(15) << noFactors << endl;
//
//			noNonPrime++;
//		}
//	}
//
//	otData << "# of positive, nonprime values: "
//		   << noNonPrime << endl;
//
//	otData.close();
//
//	return 0;
//}
//
//void printLabelData(ofstream& stream, char label[])
//{
//	stream << left << setw(20) << label;
//	stream << right << setw(12);
//}
//
//int getNoFactors(int value)
//{
//	int noFactors = 0;
//
//	for (int divisor = 1; divisor <= value; divisor++)
//	{
//		if (value > 0 && value % divisor == 0)
//			noFactors++;
//	}
//
//	return noFactors;
//}