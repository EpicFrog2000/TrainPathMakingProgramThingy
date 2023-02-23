#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <map>
#include <mysql/mysql.h>
#include "funkcja_v2.cpp"
using namespace std;
int main(){
    /*
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    //printf ("lines %d\n", w.ws_row); // max: 57
    //printf ("columns %d\n", w.ws_col); // max: 236
    */
    //Pobierz dane stacji z bazy danych i dodaj je do mapy
    map<string, pair<string,string>> map;
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *connection = mysql_init(NULL);
    MYSQL *db;
    db = mysql_real_connect(connection, "localhost", "norbert", "", "pociag_v3", 0, NULL, 0);
    const char *query;
    /*
    string zapytanie = "SELECT `Nazwa_stacji`,`Poz_x`,`Poz_y` FROM stacje;"; // query text
    query = zapytanie.c_str();
    mysql_query(connection, query);
    res = mysql_store_result(connection);
	while (row = mysql_fetch_row(res)){   
	    //cout << row[0] << row[1]<< row[2]<<  endl;
        pair<string,string> value(row[1],row[2]);
        map[row[0]] = value;
	}
    mysql_close(connection);
    //wypisz dane w mapie
    for(const auto& elem : map){
        cout << "Miasto: " <<elem.first << " Pozycja x: " << elem.second.first << " Pozycja y: " << elem.second.second << "\n";
    }
    */
    string zapytanie = "SELECT `Nazwa_stacji`,`Poz_x`,`Poz_y` FROM stacje WHERE Nazwa_stacji in ('Kraków','Warszawa');"; //Wybierz miasto
    query = zapytanie.c_str();
    mysql_query(connection, query);
    res = mysql_store_result(connection);
	while (row = mysql_fetch_row(res)){
        pair<string,string> value(row[1],row[2]);
        map[row[0]] = value;
	}
    mysql_close(connection);
    pair<double, double> Q = make_pair(stoi(map["Warszawa"].first, nullptr, 10), stoi(map["Warszawa"].second, nullptr, 10));
    pair<double, double> P = make_pair(stoi(map["Kraków"].first, nullptr, 10), stoi(map["Kraków"].second, nullptr, 10));
    getLineDirection(P, Q); // Wypisuje wzór prostej lini miedzy dwoma miastami oraz x,y przez ktore ta linia przechodzi

    return 0;
}
