#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <mysql/mysql.h>
#include <vector>
#include "funkcja_v2.cpp"

using namespace std;
int CheckDirection;
pair<int, int> e;
map<int, pair<int, int>> cords;
MYSQL_ROW row;
MYSQL_RES *res;
MYSQL *connection = mysql_init(NULL);
string zapytanie;
const char *query;
MYSQL *db = mysql_real_connect(connection, "localhost", "norbert", "", "pociag_v3", 0, NULL, 0);
pair<double, double> Q;
pair<double, double> P;
void Between(string name_1, string name_2)
{
    map<string, pair<string, string>> map;
    zapytanie = "SELECT `Nazwa_stacji`,`Poz_x`,`Poz_y` FROM stacje WHERE Nazwa_stacji in ('" + name_1 + "','" + name_2 + "');";
    query = zapytanie.c_str();
    mysql_query(connection, query);
    res = mysql_store_result(connection);
    while (row = mysql_fetch_row(res))
    {
        pair<string, string> value(row[1], row[2]);
        map[row[0]] = value;
    }
    Q = make_pair(stoi(map[name_1].first, nullptr, 10), stoi(map[name_1].second, nullptr, 10));
    P = make_pair(stoi(map[name_2].first, nullptr, 10), stoi(map[name_2].second, nullptr, 10));
    cout << name_1 << " ("<< Q.first << ", " << Q.second << ") -> " << name_2 << " ("<< P.first << ", " << P.second << ")\n";
    e = make_pair(stoi(map[name_1].first, nullptr, 10), stoi(map[name_1].second, nullptr, 10));
    //getLineLength(P, Q);
    getLineDirection(P, Q, cords, CheckDirection);
}
int main()
{
/*
struct winsize w;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//printf ("lines %d\n", w.ws_row); // max: 57
//printf ("columns %d\n", w.ws_col); // max: 236
*/
//Between("Wrocław", "Kraków");
//Between("Radom", "Katowice"); // horizontal line
//Between("Pruszków", "Brzeg"); //vertical line
//Between("Gdańsk", "Zakopane");
Between("Suwałki", "Gryfice");
//get all stations
zapytanie = "SELECT `Id_przy`,`Poz_x`,`Poz_y` FROM stacje;";
query = zapytanie.c_str();
mysql_query(connection, query);
res = mysql_store_result(connection);
map<int, pair<int, int>> allmap;
while (row = mysql_fetch_row(res))
{
    pair<int, int> value(stoi(row[1]), stoi(row[2]));
    allmap[stoi(row[0])] = value;
}
int s = allmap.size();

//Get only posrednie stacje
vector<pair<int, int>> PosrednieStacje;    
for (const auto &elem : cords)
{
    if (CheckDirection == 0){
        for (size_t i = 1; i <= s; i++)
        {
            if (allmap[i].second >= elem.second.first && allmap[i].second <= elem.second.second && allmap[i].first == elem.first)
            {
                PosrednieStacje.emplace_back(allmap[i].first, allmap[i].second);
            }
        }
    }else if (CheckDirection == 1){
        for (size_t i = 1; i <= s; i++)
        {
            if (allmap[i].first >= elem.second.first && allmap[i].first <= elem.second.second && allmap[i].second == elem.first)
            {
                PosrednieStacje.emplace_back(allmap[i].second, allmap[i].first);           
            }
        }
    }else if(CheckDirection == 2){
        for (size_t i = 1; i <= s; i++)
        {
            if(allmap[i].first == elem.first && allmap[i].second >= elem.second.first && allmap[i].second <= elem.second.second){
                PosrednieStacje.emplace_back(allmap[i].first, allmap[i].second);  
            }
        }
    }else if(CheckDirection == 3){
        for (size_t i = 1; i <= s; i++)
        {
            if(allmap[i].first == elem.first && allmap[i].second >= elem.second.first && allmap[i].second <= elem.second.second){
                PosrednieStacje.emplace_back(allmap[i].first, allmap[i].second);  
            }   
        }
    }
}

vector<pair<int,int>> CordsToDraw;
vector<pair<int,int>> points; //wszystkie stacje trasy
points.emplace_back(Q);
for (const auto &elem : PosrednieStacje)
{
    points.emplace_back(elem.first, elem.second);
}
points.emplace_back(P);

cords.clear();


for (const auto &elem : points)
{
cout << elem.first << ", " << elem.second << endl;
}
cout << "\n";

pair<int, int> current;
bool FirstIteration = true;
for (const auto &elem : points){
    if (FirstIteration){current = make_pair(elem.first,elem.second);FirstIteration = false;continue;}
    //cout << current.first << ", " << current.second << " -> current station" <<endl;
    getLineDirection(current, elem, cords, CheckDirection);
    for (const auto &eleme : cords){
        if (CheckDirection == 1)
        {
            //cout << eleme.first<<", "<< ((eleme.second.first)+3) << endl;
            CordsToDraw.emplace_back(eleme.first, eleme.second.first+ODCHYLENIE);
        }else{
            //cout << ((eleme.second.first)+3)<<", "<< eleme.first << endl;
            CordsToDraw.emplace_back( eleme.second.first+ODCHYLENIE, eleme.first);
        }
    }
    cords.clear();
    current = elem;
    //cout << current.first << ", " << current.second << " -> next station" <<endl;
}
//allmap - > wszystkie stacje
//PosrednieStacje - > posrednie stacje
//Q ->  x,y pocz stacji
//P - > x,y konc stacji
//CordsToDraw -> tory kolejowe
DrawMap(allmap, Q, P, PosrednieStacje, CordsToDraw);
return 0;
}