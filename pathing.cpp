#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <map>
#include <mysql/mysql.h>
#include "funkcja_v2.cpp"

using namespace std;
bool CheckDirection;
map<int, pair<int, int>> cords;
MYSQL_ROW row;
MYSQL_RES *res;
MYSQL *connection = mysql_init(NULL);
string zapytanie;
const char *query;
MYSQL *db = mysql_real_connect(connection, "localhost", "norbert", "", "pociag_v3", 0, NULL, 0);
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
    pair<double, double> Q = make_pair(stoi(map[name_1].first, nullptr, 10), stoi(map[name_1].second, nullptr, 10));
    pair<double, double> P = make_pair(stoi(map[name_2].first, nullptr, 10), stoi(map[name_2].second, nullptr, 10));
    cout << name_1 << " -> " << name_2 << endl;
    getLineLength(P, Q);
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
    Between("Wrocław", "Kraków");
    // Between("Gdańsk", "Zakopane");
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
    for (const auto &elem : cords)
    {
        if (CheckDirection)
        {
            // pierwsze x
            for (size_t i = 1; i <= s; i++)
            {
                // Wypisuje linie trasy
                // cout << elem.first << ", " << elem.second.first << ", " << elem.second.second << "\n";
                if (allmap[i].second >= elem.second.first && allmap[i].second <= elem.second.second && allmap[i].first == elem.first)
                {
                    // Wypisuje możliwe przystanki
                    // cout << elem.first << ", " << elem.second.first << ", " << elem.second.second << "\n";
                    cout << allmap[i].first << ", " << allmap[i].second << endl;
                }
            }
        }
        else
        {
            // pierwsze y
            for (size_t i = 1; i <= s; i++)
            {
                // Wypisuje linie trasy
                // cout << elem.first <<", "<< elem.second.first << ", " <<  elem.second.second  <<  "\n";
                if (allmap[i].first >= elem.second.first && allmap[i].first <= elem.second.second && allmap[i].second == elem.first)
                {
                    // Wypisuje możliwe przystanki
                    // cout << elem.first <<", "<< elem.second.first << ", " <<  elem.second.second  <<  "\n";
                    cout << allmap[i].first << ", " << allmap[i].second << endl;
                    // x, y
                }
            }
        }
    }

    return 0;
}