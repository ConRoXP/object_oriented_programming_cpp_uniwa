/*
Write a class that will represent a time of day (hour, minutes, seconds).  
The object of the class will be initialized with three values or with another object of the same class.  
The class will support the following functions:

● The creation of a new moment in time by incrementing an existing moment by a number of seconds (overloading of a '+' operator).  
● The creation of a new moment in time resulting from incrementing by another object of the class (overloading of a '+' operator).  
● Return the time as a string.  
● Equality check between two objects of the class (overloading operator "==").  

Write a main function which demonstrates the operation of the class.  
*/

#include <iostream>
using namespace std;

class Time{
    private:
    int seconds, minutes, hours;

    public:
    Time();
    Time(int, int, int);
    Time(const Time&);
    ~Time();

    Time &operator+(const int);
    Time &operator+(const Time&);
    string toString();
    bool operator==(const Time&);
};

/*Constructors*/

//Default Constructor
Time::Time(){}

//Initializing with three values
Time::Time(int h, int m, int s){
    seconds= s;
    minutes= m+ seconds/60;
    hours= h+ minutes/60;

    seconds= seconds%60;
    minutes= minutes%60;
}

//Initializing with another object
Time::Time(const Time& obj){
    seconds= obj.seconds;
    minutes= obj.minutes;
    hours= obj.hours;
}

//Destructor
Time::~Time(){}

/*Operator Overloading*/

//Incrementing by a number of seconds
Time &Time::operator+(const int sec){
    seconds= seconds+sec;
    minutes= minutes+ seconds/60;
    hours= hours+ minutes/60;

    seconds= seconds%60;
    minutes= minutes%60;

    return *this;
}

//Incrementing by another object
Time &Time::operator+(const Time& obj){
    seconds= seconds+ obj.seconds;
    minutes= minutes+ obj.minutes+ seconds/60;
    hours= hours+ obj.hours+ minutes/60;

    seconds= seconds%60;
    minutes= minutes%60;

    return *this;
}

//Returning as string
string Time::toString(){
    string s= to_string(seconds);
    string m= to_string(minutes);
    string h= to_string(hours);

    string t= h+':'+m+':'+s;
    return t;
}

//Equality check between two objects
bool Time::operator==(const Time& obj){
    if(seconds!= obj.seconds){
        return 0;
    }
    else if(minutes!= obj.minutes){
        return 0;
    }
    else if(hours!= obj.hours){
        return 0;
    }
    else return 1;
}

int main(){
    //Initialization
    Time t1(2, 40, 30);
    Time t2(3, 83, 364);
    Time t3(t2);

    //Returning as string
    cout<< "t1: " << t1.toString() << endl;
    cout<< "t2: " << t2.toString() << endl;
    cout<< "t3: " << t3.toString() << endl;

    //Incrementing by a number of seconds
    t1+ 165;
    cout<< "t1+ 165 sec= " << t1.toString() << endl;

    //Incrementing by another class object
    t2+t3;
    cout<< "t2+ t3= " << t2.toString() << endl;

    //Equality check between two objects
    cout<< "t1== t3? --> " << (t1==t3) << endl;

    return 0;
}
