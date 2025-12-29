#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class MovieData     {
private:
        string title;
        string director;
        int yearReleased;
        int runningTime;
        double productionCost;
        double firstYearRevenues;
public:
    MovieData(string t, string d, int y, int r, double p, double f); 
    MovieData();
    void Settitle(string t);
    void Setdirector(string d); 
    void SetyearReleased(int y);
    void SetrunningTime(int r);
    void SetproductionCost(double p);
    void SetfirstYearRevenues(double f); 
    string Gettitle(); 
    string Getdirector(); 
    int GetyearReleased(); 
    int GetrunningTime();
    double GetproductionCost();
    double GetfirstYearRevenues();
};

