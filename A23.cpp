/*
Create the class "BigInt" which will represent large  
natural numbers (0 included) as collections of digits.  
The class will provide the following functionality:  

● It will be initialized with integers, C++ strings or other objects.  
● It will implement the operation of post-increment and addition with another instance by overloading the corresponding operators.  
● It will overload the ">" operator.  
● It will return the number as a C String.  

The operation of the preceding will be demonstrated via an appropriate main function.  
*/

#include <iostream>
using namespace std;

class BigInt{
    private:
    string num;

    public:
    BigInt(const unsigned long long int);
    BigInt(const string);
    BigInt(const BigInt&);

    BigInt &operator+(const BigInt&);
    BigInt &operator++(int);

    bool operator>(const BigInt&);
    const char* toCstring();

    string getNum() const;
};

//Initialization by integer and Conversion to string
BigInt::BigInt(const unsigned long long int n){
    num= to_string(n);
}

//Initialization by string
BigInt::BigInt(const string n){
    num= n;
}

//Copy constructor
BigInt::BigInt(const BigInt& obj){
    num= obj.num;
}

/*
Converting to a string and back to an int is not the optimal solution and at even larger  
numbers overflow will be unavoidable. This solution is what I could come up with at the time.
*/

//Overloading '+'
BigInt &BigInt::operator+(const BigInt& obj){
    unsigned long long int right= stoull(num);
    unsigned long long int left= stoull(obj.num);

    unsigned long long int sum= left+ right;
    num= to_string(sum);

    return *this;
}

//Overloading '++'
BigInt &BigInt::operator++(int i){
    unsigned long long int obj= stoull(num);
    obj++;
    num= to_string(obj);

    return *this;
}

//Overloading '>'
bool BigInt::operator>(const BigInt& obj){
    unsigned long long int right= stoull(num);
    unsigned long long int left= stoull(obj.num);

    if(left> right) return 1;
    return 0;
}

//Getter
string BigInt::getNum() const{
    return num;
}

//Convert to C String
const char* BigInt::toCstring(){
    return (num.c_str());
}

int main(){
    BigInt b1(1021039029039000002);
    BigInt b2("1795854369587515895");
    BigInt b3(b2);
    cout<< "b1= " << b1.getNum() << endl;
    cout<< "b2= " << b2.getNum() << endl;
    cout<< "b3= " << b3.getNum() << endl;
    
    BigInt b4= b1+b2;
    cout<< "b4= b1+b2= " << b4.getNum() << endl;

    b4++;
    cout<< "b4++ = " << b4.getNum() << endl;

    
    return 0;
}
