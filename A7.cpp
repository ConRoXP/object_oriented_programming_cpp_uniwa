/*
Write a class that will represent a date (day, month, year).  
The object of the class will be initialized with the three values or with another object of the same class.  
The class will support the following functions:  

● Creation of a new date by incrementing an existing date by N months (overloading of a '+' operator).  
● Return the date as a string.  
● Overloading of the '>' operator.  

Write a function which sorts a date table.  
Write a main function which demonstrates the operation of the above.  
*/

#include <iostream>
#include <vector>
using namespace std;

class Date{
    private:
    int year, day, month;

    public:
    Date();
    Date(int, int, int);
    Date(const Date&);
    ~Date();

    Date &operator+(const int);
    string toString();
    bool operator>(const Date&);

    int getYear() const;
    int getMonth() const;
    int getDay() const;
};

Date::Date(){}

//Initialization with a date
Date::Date(int d, int m, int y){
    day= d;
    month= m+ day/30;
    year= y+ month/12;

    day= day%30;
    month= month%12;
}

//Initialization with an object
Date::Date(const Date& obj){
    day= obj.day;
    month= obj.month;
    year= obj.year;
}

Date::~Date(){}

//Overloading '+'
Date &Date::operator+(const int N){
    month+= N;
    year+= month/12;

    month= month%12;

    return *this;
}

//Return as string
string Date::toString(){
    string d= to_string(day);
    string m= to_string(month);
    string y= to_string(year);

    string t= d+'/'+m+'/'+y;
    return t;
}

//Overloading '>'
bool Date::operator>(const Date& obj){
    if(year> obj.year) return 1;
    else if(year== obj.year){
        if(month> obj.month) return 1;
        else if(month== obj.month){
            if(day> obj.day) return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

/*Getters*/
int Date::getYear() const{
    return year;
}

int Date::getMonth() const{
    return month;
}

int Date::getDay() const{
    return day;
}


void display(vector<Date>& vect){
    for(int i=0; i< vect.size(); i++){
        cout<< vect[i].getDay() << '/' << vect[i].getMonth() << '/' << vect[i].getYear() << endl;
    }
}

//Bubble Sort
void sort(vector<Date>& vect){
    int size= vect.size();
    for(int i=0; i< size-1; i++){
        for(int j=0; j< size-i-1; j++){
            if(vect[j]> vect[j+1]){
                swap(vect[j], vect[j+1]);
            }
        }
    }
}

int main(){
    //Initialization
    vector<Date> vector;
    Date d1(3, 11, 3455);
    Date d2(75, 43, 223);
    Date d3(d1);

    //Return as string
    cout<< "d1: " << d1.toString() << endl;
    cout<< "d2: " << d2.toString() << endl;
    cout<< "d3: " << d3.toString() << endl;

    //Overloaded '+' demonstration
    d1+12;
    cout<< "d1+ 12= " << d1.toString() << endl;

    //Creating a table of dates and sorting it
    vector.push_back(d1);
    vector.push_back(d2);
    vector.push_back(d3);

    cout<< "Sorting array and printing..." << endl;
    sort(vector);
    display(vector);

    return 0;
}
