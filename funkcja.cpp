// TOP 10 NIEPOTRZEBNIE SKOMPLIKOWANYCH PROGRAMOW! NR.3: 
#include <iostream> 
#include <math.h>
#include <queue>
using namespace std;
// Function to find the line given two points
void lineFromPoints(pair<double, double> P, pair<double, double> Q)
{
    double a = Q.second - P.second;
    double b = P.first - Q.first;
    double c = a * (P.first) + b * (P.second);
    cout << "A(" << P.first << "; " << P.second << ")"<< " B(" << Q.first << "; " << Q.second << ")" <<endl;
    if (a == 0 && b == 0)
    {
        cout << "punkt"<< endl;
    }else if (a == 0)
    {
        cout << "rownolegla do osi y - idzie pionowo"<< endl;
    }else if (b == 0)
    {
        cout << "rownolegla do osi x - idzie poziomo"<< endl;
    }else{
        cout << "x= " << -a/b << "y + " << c/b << endl;
    }
    //cout << "y= " << -b /a << "x + " << c/a << endl;
queue <int> unikalne;
    //check czy jest bardziej pionowa niz pozioma
    if (abs(a)>abs(b))
    {
        cout << "bardziej pionowa CZYLI policz jakie iksy są od igreków: "<< P.second <<" do " << Q.second << endl;
        if (P.second >  Q.second){
            int first = ceil(((-b/a)*Q.second) + (c/a));
            //unikalne.push(ceil(((-b/a)*Q.second) + (c/a)));
            for (size_t i = Q.second; i < P.second; i++){
                if (first != ceil(((-b/a)*i) + (c/a))){
                    unikalne.push(ceil(((-b/a)*i) + (c/a)));
                    first = ceil(((-b/a)*i) + (c/a));
                }
            }
        }else{
            int first = ceil(((-b/a)*P.second) + (c/a));
            //unikalne.push(ceil(((-b/a)*P.second) + (c/a)));
            for (size_t i = P.second; i < Q.second; i++){
                if (first != ceil(((-b/a)*i) + (c/a))){
                    unikalne.push(ceil(((-b/a)*i) + (c/a)));
                    first = ceil(((-b/a)*i) + (c/a));
                }
            }
        }
        while(!unikalne.empty()){
		cout<<" "<<unikalne.front();
		unikalne.pop();
        }
    }else if (abs(a)<abs(b)){
        cout << "bardziej pozioma CZYLI policz jakie igreki są od iksów: "<< P.first <<" do " << Q.first << endl;                  //TODO WEŹ POKAŻ TYLKO UNIKALNE
        if (P.first >  Q.first){
            int first = ceil(((-a/b)*P.first) + (c/b));
            //unikalne.push(ceil(((-a/b)*P.first) + (c/b)));
            for (size_t i = Q.first; i < P.first; i++){
                if (first != ceil(((-a/b)*i) + (c/b))){
                    unikalne.push(ceil(((-a/b)*i) + (c/b)));
                    first = ceil(((-a/b)*i) + (c/b));
                }
            }
        }else{
            int first = ceil(((-a/b)*Q.first) + (c/b));
            //unikalne.push(ceil(((-a/b)*Q.first) + (c/b)));
            for (size_t i = P.first; i < Q.first; i++){
                if (first != ceil(((-a/b)*i) + (c/b))){
                    unikalne.push(ceil(((-a/b)*i) + (c/b)));
                    first = ceil(((-a/b)*i) + (c/b));
                }
            }
        }
        while(!unikalne.empty()){
		cout<<" "<<unikalne.front();
		unikalne.pop();
        }
	}
    else if (abs(a) == abs(a)){
        cout << "y = x" << endl;
    }
}
// Function to find length of line given two points WHY? MIGHT NEED LATER LOL
void lengthOfLine(pair<double, double> P, pair<double, double> Q)
{
    cout << sqrt(pow(Q.first - P.first, 2) + pow(Q.second - P.first, 2) * 1.0);
}


int main()
{

    pair<double, double> P = make_pair(10, 20);
    pair<double, double> Q = make_pair(20, 50);
    lineFromPoints(P, Q);
    return 0;
}