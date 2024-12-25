/*
Using the Entities: "Person", "Student", "Professor",  
write an example which will demonstrate:  

● Constructors and Destroyers  
● Inheritance  
● Virtual methods  
● Abstract classes  
● The creation and management of collections of objects of different types  

The instance does not need to read data from standard input.  
*/

//A typical inheritance demonstration

#include <iostream>
using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:
    Person();
    Person(string, int);
    Person(const Person&);
    virtual ~Person();

    virtual void display()= 0; //Virtual Class
};

Person::Person(){
    name= "N/A";
    age= 0;
}

Person::Person(string str, int i){
    name= str;
    age= i;
}

Person::Person(const Person& obj){
    name= obj.name;
    age= obj.age;
}

Person::~Person(){
    cout<< "Destructor called for Person " << name << endl;
}

//Student inherits Person
class Student: public Person{
    private:
    int AM;
    float MO;

    public:
    Student();
    Student(string, int, int, float);
    Student(const Student&);
    virtual ~Student();

    virtual void display();
};

Student::Student(): Person(){
    name= "N/A";
    age= 0;
    AM= 0;
    MO= 0;
}

Student::Student(string _name, int _age, int am, float mo): Person(_name, _age){
    name= _name;
    age= _age;
    AM= am;
    MO= mo;
}

Student::Student(const Student& obj): Person(obj){
    name= obj.name;
    age= obj.age;
    AM= obj.AM;
    MO= obj.MO;
}

Student::~Student(){
    cout<< "Destructor called for Student " << name << endl;
}

void Student::display(){
    cout<< name << ", " << age << ", " << AM << ", " << MO << endl;
}

//Proffessor inherits Person
class Prof: public Person{
    private:
    float AM;
    string subject;

    public:
    Prof();
    Prof(string, int, int, string);
    Prof(const Prof&);
    virtual ~Prof();

    virtual void display();
};

Prof::Prof(): Person(){
    name= "N/A";
    age= 0;
    AM= 0;
    subject= "N/A";
}

Prof::Prof(string _name, int _age, int am, string subj): Person(_name, _age){
    name= _name;
    age= _age;
    AM= am;
    subject= subj;
}

Prof::Prof(const Prof& obj): Person(obj){
    name= obj.name;
    age= obj.age;
    AM= obj.AM;
    subject= obj.subject;
}

Prof::~Prof(){
    cout<< "Destructor called for Professor " << name << endl;
}

void Prof::display(){
    cout<< name << ", " << age << ", " << AM << ", " << subject << endl;
}

int main(){

    Student s0;
    Prof p0;

    Student s("Sam", 22, 423, 6.5);
    Prof pr("Jeff", 32, 425, "Physics");

    /*
    Via the use of virtual methods, we can create arrays that contain
    multiple elements of different data types.
    */
    const int length= 4;
    Person* p[length];

    p[0]= new Student("John", 18, 112, 7.8);
    p[1]= new Prof("Jim", 45, 321, "OOP");
    p[2]= new Student(s);
    p[3]= new Prof(pr);

    for(int i=0; i< length; i++){
        p[i]->display();
    }

    for(int i=0; i< length; i++){
        delete p[i];
    }

    return 0;
}
