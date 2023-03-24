#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

int const ODCHYLENIE =3;

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
        //cout << "Line is a point: (" << x1 << ", " << y1 << ")" << endl;
        return;
    }

    // Check if line is vertical
    if (x1 == x2)
    {
        //cout << "Line is vertical, x = " << x1 << endl;
        double start = min(y1, y2);
        double end = max(y1, y2);
        pair<int,int> value(start-ODCHYLENIE,end+ODCHYLENIE);
        cords[x1] = value;
        CheckDirection = 3;
    return;
    }

    // Check if line is horizontal
    if (y1 == y2)
    {
        //cout << "Line is horizontal, y = " << y1 << endl;
        double start = min(x1, x2);
        double end = max(x1, x2);
        pair<int,int> value(start-ODCHYLENIE,end+ODCHYLENIE);
        cords[y1] = value;
        CheckDirection = 3;
    return;
    }

    // Calculate the slope of the line
    double slope = (y2 - y1) / (x2 - x1);

    // Calculate the y-intercept of the line
    double y_intercept = y1 - slope * x1;

    // Print out the equation of the line in slope-intercept form
    //cout << "Equation of the line: y = " << slope << "x + " << y_intercept << endl;

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
                pair<int,int> value(round(y)-ODCHYLENIE,round(y)+ODCHYLENIE);
                cords[i] = value;
                CheckDirection = 1;
            }else{
                pair<int,int> value(i-ODCHYLENIE,i+ODCHYLENIE);
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
                pair<int,int> value(i-ODCHYLENIE,i+ODCHYLENIE);
                cords[round(x)] = value;
                CheckDirection = 1;
            }else{
                pair<int,int> value(round(x)-ODCHYLENIE,round(x)+ODCHYLENIE);
                cords[round(i)] = value;
                CheckDirection = 0;
            }
        }
    }
}
void getLineLength(pair<int, int> P, pair<int, int> Q){
cout << "dystans od pocz stacji: " << sqrt((Q.first-P.first)*(Q.first-P.first)+(Q.second-P.second)*(Q.second-P.second)) << endl;
//return sqrt((Q.first-P.first)*(Q.first-P.first)+(Q.second-P.second)*(Q.second-P.second));
}
void DrawMap(const map<int, pair<int, int>> &mapa, const pair<double, double> Q, const pair<double, double> P, vector<pair<int, int>> PosrednieStacje, vector<pair<int,int>> CordsToDraw) {
    int IsThere; //0-puste, 1-Stacjazwykła, 2-stacjaTrasy, 3-stacjaKON, 4-stacjaPOCZ, 5-Trasa
    for (size_t i = 0; i <10; i++){
        cout << "__"<<i;
    }
    for (size_t i = 10; i <100; i++){
        cout << "_"<<i;
    }
    cout << "_100\n";

    for (size_t i = 0; i <= 100; i++) {
        cout << "|";
        for (size_t j = 0; j <= 100; j++) {
            IsThere = 0;
            for (const auto &elem : mapa)
            {
                if (elem.second.first == j && elem.second.second == i)
                {
                    IsThere = 1;
                }
            }
            for (const auto &elem : CordsToDraw)
            {
                if (elem.first == j && elem.second == i)
                {
                    IsThere = 5;
                }
            }
            for (const auto &elem : PosrednieStacje)
            {
                if (elem.first == j && elem.second == i)
                {
                    IsThere = 2;
                }
            }
            if (Q.first == j && Q.second == i)
            {
                IsThere = 4;
            }else if(P.first == j && P.second == i){
                IsThere = 3;
            }
            if(IsThere==1){
                cout << " S ";
            }else if (IsThere == 4){
                cout << "POC";
            }else if (IsThere == 5){
                cout << " # ";
            }else if (IsThere == 3){
                cout << "KON";
            }else if (IsThere == 2){
                cout << "_S_";
            }else{
                cout << "   ";
            }
        }
        cout << "|" << i << "\n";
    }
    cout << " " << string(303, '-') << "\n";
}

//int main()
//{
//   pair<double, double> P = make_pair(23, 84);
//    pair<double, double> Q = make_pair(1, 25);
//    getLineDirection(P, Q);
//    return 0;
//}