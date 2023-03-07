#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int const odchylenie = 2;
enum LineType {
    HORIZONTAL,
    VERTICAL
};

LineType getLineType(int x1, int y1, int x2, int y2) {
    float angle = atan2(abs(y2 - y1), abs(x2 - x1));
    if (angle <= M_PI / 4) {
        return HORIZONTAL;
    } else {
        return VERTICAL;
    }
}

void getLineDirection(pair<double, double> P, pair<double, double> Q, map<int, pair<int,int>> &cords, int &CheckDirection)
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
        double start = min(y1, y2);
        double end = max(y1, y2);
        pair<int,int> value(start-odchylenie,end+odchylenie);
        cords[x1] = value;
        CheckDirection = 3;
    return;
    }

    // Check if line is horizontal
    if (y1 == y2)
    {
        cout << "Line is horizontal, y = " << y1 << endl;
        double start = min(x1, x2);
        double end = max(x1, x2);
        pair<int,int> value(start-odchylenie,end+odchylenie);
        cords[y1] = value;
        CheckDirection = 3;
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
            if (getLineType(P.first, P.second,Q.first, Q.second)==HORIZONTAL)
            {
                pair<int,int> value(round(y)-odchylenie,round(y)+odchylenie);
                cords[i] = value;
                CheckDirection = 1;
            }else{
                pair<int,int> value(i-odchylenie,i+odchylenie);
                cords[round(y)] = value;
                CheckDirection = 0;
            }
        }
    }
    else
    {
        double start = min(y1, y2);
        double end = max(y1, y2);
        getLineType(P.first, P.second,Q.first, Q.second);
        for (int i = (int)start; i <= (int)end; i++)
        {
            double x = (i - y_intercept) / slope;
            if (getLineType(P.first, P.second,Q.first, Q.second)==HORIZONTAL)
            {
                pair<int,int> value(i-odchylenie,i+odchylenie);
                cords[round(x)] = value;
                CheckDirection = 1;
            }else{
                pair<int,int> value(round(x)-odchylenie,round(x)+odchylenie);
                cords[round(i)] = value;
                CheckDirection = 0;
            }
        }
    }
}
void getLineLength(pair<double, double> P, pair<double, double> Q){
cout<<"Odległość między stacjami wynosi: "<<sqrt((Q.first-P.first)*(Q.first-P.first)+(Q.second-P.second)*(Q.second-P.second))<<endl;
}
//int main()
//{
//   pair<double, double> P = make_pair(23, 84);
//    pair<double, double> Q = make_pair(1, 25);
//    getLineDirection(P, Q);
//    return 0;
//}