/*
● Create a class to describe the entities “Bicycle” and “Electric Bicycle” for a store that sells related products.
● The class will have, in total, 2 to 3 characteristics of the student’s choice.
● Create a LIST of objects that will include both bicycles and electric bicycles.
● Write a function that will calculate the average price of electric bicycles.

● Implement what is necessary so that the command: XXX << YYY;
(where XXX is a snapshot of the ostream class and YYY is a single list of bicycles)
prints once all the brands of bicycles (electric and non-electric) that are sold in the store.

● Write a main program that will demonstrate the operation of the previous ones.
*/

#include <iostream>
#include <list>
using namespace std;

//2 classes aren't really necessary
//so maybe this counts as correct, maybe not?
class Bike{
    private:
    string brand;
    float price;
    bool isElectric;

    public:
    Bike();
    Bike(const string, const float, const bool);
    ~Bike();
    float getPrice() const;
    string getBrand() const;
    bool Electric() const;
};

Bike::Bike(){}

Bike::Bike(const string _brand, const float _price, const bool _isElec){
    brand= _brand;
    price= _price;
    isElectric= _isElec;
}

Bike::~Bike(){}

//Getters
float Bike::getPrice() const{
    return price;
}

string Bike::getBrand() const{
    return brand;
}

bool Bike::Electric() const{
    return isElectric;
}

//Calculating avg price of E-Bikes only
float avg(list<Bike>& ls){
    float sum= 0;
    for(auto const &i: ls){
        if(i.Electric()== 1) sum+= i.getPrice();
    }
    return sum/ ls.size();
}

//Output operator overload
ostream &operator<<(ostream &os, const list<Bike>& obj){
    for(auto const &i: obj){
        os<< i.getBrand() << endl;
    }
    return os;
}

int main(){
    //Demonstration of the above functions
    string brand;
    float price;
    bool isElectrical;
    list<Bike> ls;

    Bike b1("Brand1", 124.5, 1);
    Bike b2("Brand2", 554.9, 1);
    Bike b3("Brand3", 99.9, 0);
    Bike b4("Brand4", 456, 0);
    Bike b5("Brand5", 249.9, 1);

    ls.push_back(b1);
    ls.push_back(b2);
    ls.push_back(b3);
    ls.push_back(b4);
    ls.push_back(b5);

    cout<< "The avg price of E-Bikes is: " << avg(ls) << "€" << endl;
    cout<< "Printing brands of all available bikes..." << endl << ls;

    return 0;
}