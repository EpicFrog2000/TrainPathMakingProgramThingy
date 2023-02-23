#include <iostream>
#include <map>
#include <cmath>
using namespace std;
void getLineDirection(pair<double, double> P, pair<double, double> Q)
{
    double x1 = P.first, y1 = P.second;
    double x2 = Q.first, y2 = Q.second;

    // Check if line is a point
    if (x1 == x2 && y1 == y2)
    {
        cout << "Line is a point: (" << x1 << ", " << y1 << ")" << endl;
        return;
    }

    // Check if line is vertical
    if (x1 == x2)
    {
        cout << "Line is vertical, x = " << x1 << endl;
        return;
    }

    // Check if line is horizontal
    if (y1 == y2)
    {
        cout << "Line is horizontal, y = " << y1 << endl;
        return;
    }

    // Calculate the slope of the line
    double slope = (y2 - y1) / (x2 - x1);

    // Calculate the y-intercept of the line
    double y_intercept = y1 - slope * x1;

    // Print out the equation of the line in slope-intercept form
    cout << "Equation of the line: y = " << slope << "x + " << y_intercept << endl;

    // Print out all the integer values of x and y between the two points
    if (abs(slope) <= 1)
    {
        double start = min(x1, x2);
        double end = max(x1, x2);
        for (int i = (int)start; i <= (int)end; i++)
        {
            double y = slope * i + y_intercept;
            cout << "x = " << i << ", y = " << round(y) << endl;
        }
    }
    else
    {
        double start = min(y1, y2);
        double end = max(y1, y2);
        for (int i = (int)start; i <= (int)end; i++)
        {
            double x = (i - y_intercept) / slope;
            cout << "x = " << round(x) << ", y = " << i << endl;
        }
    }
}
//int main()
//{
//   pair<double, double> P = make_pair(23, 84);
//    pair<double, double> Q = make_pair(1, 25);
//    getLineDirection(P, Q);
//    return 0;
//}