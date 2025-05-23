/*
Create a class "MyString" which will represent strings.  
The class must meet the following specifications:  

● It will be initialized with an empty string, a C String, or another object.  
● It will overload the "==", "!=", ">" and "<" operators to perform the corresponding checks.  
● It will overload the "+=" operator to add a character to the end of the string.  
● It will return the string as a C String.  
● It will return the length of the string.  

Demonstrate the operation of the class via an appropriate main function.  
For the implementation of the above you will not use the STL string class.  
*/


/*
This the first challenging exercise I coded. The previous ones (A1 & A2) were an  
introduction to some features C++ has over C.  

As you can see, this code does indeed do what it is asked to do,  
however it also turns the memory into a proper mess.  

I was at the beginning of my C++ journey and I had not learnt `std::vector` yet but, coming straight from C,   
I was comfortable with pointers and dynamic memory allocation. And that's exactly what I used.
In fact, allocating an array of size 0 will be a repeat offense in other exercises too but at least I make sure to free it.  
At the time I thought it was fine and I didn't have any other ways in mind.
*/

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    private:
    char* str;
    int length;

    public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();

    bool operator==(const MyString&);
    bool operator!=(const MyString&);
    bool operator>(const MyString&);
    bool operator<(const MyString&);

    MyString &operator+=(const char);
    
    char* returnCstring() const;
    int getLength() const;
};

//Initialization with empty string
MyString::MyString(){
    length= 0;
    str= new char[length];
}

//Initialization with a C string
MyString::MyString(const char* c){
    length= strlen(c);
    str= new char[length+1];
    strcpy(str, c);
}

//Initialization with another object
MyString::MyString(const MyString& obj){
    length= obj.length;
    str= new char[length+1];
    strcpy(str, obj.str);
}

//Destructor
MyString::~MyString(){
    delete[] str;
}

/*Operator overloading*/

bool MyString::operator==(const MyString& obj){
    if(length!= obj.length) return 0;
    if(strcmp(str, obj.str)== 0) return 1;
    return 0;
}

bool MyString::operator!=(const MyString& obj){
    if(length!= obj.length) return 1;
    if(strcmp(str, obj.str)!= 0) return 1;
    return 0;
}

bool MyString::operator>(const MyString& obj){
    if(length<= obj.length) return 0;
    if(strcmp(str, obj.str)> 0) return 1;
    return 0;
}

bool MyString::operator<(const MyString& obj){
    if(length>= obj.length) return 0;
    if(strcmp(str, obj.str)< 0) return 1;
    return 0;
}

MyString &MyString::operator+=(const char c){
    char *temp= new char[length+2];
    strcpy(temp, str);
    temp[length]= c;
    temp[length+1]= '\0';
    delete[] str;

    str= new char[length+2];
    strcpy(str, temp);

    length= strlen(str);
    delete[] temp;

    return *this;
}

char* MyString::returnCstring() const{
    return str;
}

int MyString::getLength() const{
    return length;
}

int main(){
    //Initialization
    MyString s0;
    MyString s1("String1");
    MyString s2("String2");
    MyString s3("String3");
    MyString s4(s3);

    //Returning C string
    cout<< s1.returnCstring() << endl;
    cout<< s2.returnCstring() << endl;
    cout<< s3.returnCstring() << endl;
    cout<< s4.returnCstring() << endl;
    cout<< endl;

    //Overloaded operators
    cout<< "s1==s2 ? -> " << (s1==s2) << endl;
    cout<< "s1>s2 ? -> " << (s1>s2) << endl;
    cout<< "s1<s2 ? -> " << (s1<s2) << endl;
    cout<< "s1!=s1 ? -> " << (s1!=s1) << endl;
    cout<< endl;
    
    s1+= 'B';
    cout<< s1.returnCstring() << endl;

    return 0;
}
