/*
Write a template class MyVector that implements the following functions of a vector:  

● Insert an element at the end of the Vector.  
● Delete an element from the Vector. The element to be deleted is specified.  
● Retrieve a copy of the element at a position in the Vector. The position is specified using the "[]" operator.  

Write a program which demonstrates the operation of the MyVector class  
with objects of a class containing two attributes: a C-String and a float.  
The vector class of the STL library shall not be used.  
Error handling will be done with exceptions.  
*/

#include <iostream>
using namespace std;

template<typename T>
class MyVector{
    private:
    T* vect;
    int length;

    public:
    MyVector();
    ~MyVector();

    void pushBack(const T&);
    T operator[](const int&) const;
    void remove(const int&);

    void display();
};

//Default Constructor
template<typename T>
MyVector<T>::MyVector(){
    length= 0;
    vect= new T[length];
}

//Destructor
template<typename T>
MyVector<T>::~MyVector(){
    delete[] vect;
}

//Insertion at the end of the vector
template<typename T>
void MyVector<T>::pushBack(const T& obj){
    int newLength= length+1;
    T* temp= new T[newLength];
    for(int i=0; i< length; i++){
        temp[i]= vect[i];
    }
    temp[length]= obj;
    delete[] vect;

    vect= new T[newLength];
    for(int i=0; i< newLength; i++){
        vect[i]= temp[i];
    }
    length= newLength;
    delete[] temp;
}

/*
Retrieving element at the position specified by the '[]' operator
'[]' overload
*/
template<typename T>
T MyVector<T>::operator[](const int& index) const{
    if(index> length) throw string("Out of bounds");
    return vect[index];
}

//Removing specified element
template<typename T>
void MyVector<T>::remove(const int& index){
    if(index> length) throw string("Out of bounds");

    int newLength= length-1;
    T* temp= new T[length];
    for(int i=0; i< length; i++){
        temp[i]= vect[i];
    }
    delete[] vect;

    //We allocate a smaller array by length-1
    vect= new T[newLength];
    for(int i=0; i< newLength; i++){
        //For each element we check if it is the one that we want to remove
        if(i== index){
            for(int j=i; j< newLength; j++){
                /*
                If it is, we continue copying the rest of the elements
                after skipping the one that we wanted to remove
                */
                vect[j]= temp[j+1];
            }
        }
        //If it isn't, we copy the elements to the new array as usual until we find that element
        else vect[i]= temp[i];
    }
    length= newLength;
    delete[] temp;
}

//Display Function - This is where the overloaded '[]' is demonstrated
template<typename T>
void MyVector<T>::display(){
    for(int i=0; i< length; i++){
        cout<< vect[i].getCstr() << ", " << vect[i].getFloat() << endl;
    }
}

//The Class we are asked to demonstrate MyVector with
class Test{
    private:
    const char* cstr;
    float fl;

    public:
    Test();
    Test(const string, const float);
    ~Test();

    string getCstr() const;
    float getFloat() const;
};

Test::Test(){}

//Constructor
Test::Test(const string str, const float f){
    cstr= str.c_str();
    fl= f;
}

Test::~Test(){}

/*Getters*/
string Test::getCstr() const{
    return string(cstr);
}

float Test::getFloat() const{
    return fl;
}

int main(){
    //Initializing the demonstration class
    Test t0;
    Test t1("C String 1", 1.5);
    Test t2("C String 2", 2.5);
    Test t3("C String 3", 3.5);

    //Adding the class elements to our vector
    MyVector<Test> vector;
    vector.pushBack(t1);
    vector.pushBack(t2);
    vector.pushBack(t3);
    vector.display();

    //Removing an element demonstration
    cout<< "Removing t1 & t3" << endl;
    try{
    vector.remove(0);
    vector.remove(2);
    }
    catch(string err){
        cerr<< err << endl;
        exit(-1);
    }

    //Overloaded '[]' operator demonstration
    vector.display();

    return 0;
}
