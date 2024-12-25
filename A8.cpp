/*
Create a template class "Stack" which will support the the following functions:  

● Insert an Object at the top of the stack. (Push)  
● Remove Object from the top of the stack (Pop).  
● Resize the stack.  
● Save the stack to a text file.  

The stack will have no size restrictions beyond those resulting from available RAM.  
Demonstrate the operation of the stack with objects of a class that has two  
attributes, a real number and a C-String.  
*/

#include <iostream>
#include <list>
#include <fstream>
#include <cstring>
using namespace std;

template <typename T>
class MyStack{
    private:
    list<T> data;

    public:
    MyStack();
    MyStack(const T&);
    ~MyStack();
    void push(const T&);
    void pop();
    int getSize();
    void save();

    void display();
};

//Default Constructor
template<typename T>
MyStack<T>::MyStack(){}

//Initialization with another object
template<typename T>
MyStack<T>::MyStack(const T& obj){
    data.push_back(obj);
}

//Destructor
template<typename T>
MyStack<T>::~MyStack(){}

//Push
template<typename T>
void MyStack<T>::push(const T& en){
    data.push_front(en);
}

//Pop
template<typename T>
void MyStack<T>::pop(){
    data.pop_front();
}

//Get size
template<typename T>
int MyStack<T>::getSize(){
    return data.size();
}

//Print function
template<typename T>
void MyStack<T>::display(){
    //Iterating through an std::list.
    for(auto const &i: data){
        cout<< i.getString() << ", " << i.getNum() << endl;
    }
    cout<< endl;
}

//Save to file
template<typename T>
void MyStack<T>::save(){
    ofstream fout;
    fout.open("MyStack.txt");
    if(!fout.is_open()){
        cerr<< "Error creating file";
        exit(-1);
    }
    for(auto const&i: data){
        fout<< i.getString() << ", " << i.getNum() << '\n';
    }
    fout.close();
    cout<< "Stack saved successfully at MyStack.txt" << endl;
}

//Demonstration Class
class Test{
    private:
    char* cstring;
    unsigned int i;

    public:
    Test();
    Test(const char*, const unsigned int);
    Test(const Test&);
    ~Test();
    string getString() const;
    unsigned int getNum() const;
};

Test::Test(){}

//Initialization
Test::Test(const char *str, const unsigned int n){
    cstring= new char[strlen(str)+1];
    strcpy(cstring, str);
    i= n;
}

//Copy constructor
Test::Test(const Test& obj){
    cstring= new char[strlen(obj.cstring)+1];
    strcpy(cstring, obj.cstring);
    i= obj.i;
}

//Memory deallocation
Test::~Test(){
    delete[] cstring;
}

string Test::getString() const{
    return string(cstring);
}

unsigned int Test::getNum() const{
    return i;
}

int main(){
    //Demonstration class initialization
    Test t1("Cstring1", 5);
    Test t2("Cstring2", 10);
    Test t3("Cstring3", 15);

    //Adding Test class elements to stack
    MyStack<Test> stack;
    stack.push(t1);
    stack.push(t2);
    stack.push(t3);
    
    cout<< "Printing stack:" << endl;
    stack.display();

    cout<< "Popping stack:" << endl;
    stack.pop();
    stack.display();

    cout<< "Stack size= " << stack.getSize() << endl;

    //Saving to file
    stack.save();

    return 0;
}
