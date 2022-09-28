//Fritz Ammon
//Section #1001
//Assignment #8
//The following program will read the x and y coordinates of several pairs
//of points. For each pair of points, it will:
//    print the points' coordinates with labels
//    if the points are the same, it will display an appropriate message
//    if the points are different, it will:
//         determine and display the length of the line segment
//          connecting the 2 points 
//         determine and display the slope of the line defined by the 2 points

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void getpoint(double&,double&);
void printpoint(double,double);
double find_distance(double,double,double,double);
double find_slope(double,double,double,double);
void y_intercept (double,double,double);

int main()
{
  double pt1_x, pt1_y;     // x and y coordinates for point 1
  double pt2_x, pt2_y;     // x and y coordinates for point 2
  double slope;            // slope of the line between the 2 points
  double length;           // length of line segment between the 2 points

  cout << "Fritz Ammon   Section #1001   Assignment #8\n\n";

  cout << fixed << showpoint << setprecision(1);

  getpoint(pt1_x,pt1_y);
  while (cin)
    {
      getpoint(pt2_x, pt2_y);
      cout << "Point 1: ";
      printpoint(pt1_x,pt1_y);
      cout << endl << "Point 2: ";
      printpoint(pt2_x,pt2_y);
      cout << endl;

      if (pt1_x == pt2_x && pt1_y == pt2_y)
	cout << "The 2 points given are the same." << endl;
      else
	{
	  length = find_distance(pt1_x,pt1_y,pt2_x,pt2_y);
	  cout << "The length of the line segment between the 2 points is " << length << endl;
	  if (pt1_x != pt2_x)
	    {
	      slope = find_slope(pt1_x,pt1_y,pt2_x,pt2_y);
	      cout << "The slope of the line between the 2 points is " << slope << endl;
	      y_intercept(slope,pt1_x,pt1_y);
	    }
	  else
	    cout << "The slope of the line between the 2 points is undefined." << endl;
	}
      cout << endl;
      getpoint(pt1_x,pt1_y);
    }
  return 0;
}
void getpoint(double& x, double& y)
//Read the x and y coordinates of a point. The values are passed back to the
//calling function.
{
  cin >> x >> y;
}
void printpoint(double x, double y)
//Given the x and y coordinates of a point, display the value with parentheses and
//a comma separating the x and y values. (Standard point form)
{
  cout << "(" << x << "," << y << ")";
}
double find_distance(double x1, double y1, double x2, double y2)
//Given the x and y coordinates of two points, find the length of the
//line segment between them (distance).
{
	return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}
double find_slope(double x1, double y1, double x2, double y2)
//Given the x and y coordinates of two points, find the slope of the
//line segment between them.
{
	return (y2 - y1) / (((y2 - y1) == 0.0) ?  abs(x2 - x1) : (x2 - x1));
}
void y_intercept(double slope, double x, double y)
//Given the slope of the line between the two points and the coordinates
//of either of the two points, find the y-intercept, or the line coordinates
//at which the line intercepts the y-axis, and print them out.
{
	cout << "The y_intercept for the line is (0," << y - slope * x << ")\n";
}
