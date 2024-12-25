/*
Create the class Student which will have the following characteristics:  
● AM: (int)    //AM= student registration number
● Name: (char *)
● Semester: (int)
● Is Active? (bool)

Write a function that creates and returns a collection of objects 
of the Students class with data read from a csv file.  
The name of the file is given as an argument to the function.  

Write a function that prints the AM and Name of each active student found  
in the data read from the file.  

Write a main function which will demonstrate the operation of the above.
The Student class will have no public attributes and will have only  
the methods necessary to implement the above requests.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

class Student{
    private:
    int AM;
    char* name;
    int semester;
    bool active;

    public:
    Student();
    Student(const int, const char*, const int, const bool);
    Student(const Student&);
    ~Student();

    int getAM() const;
    string getName() const;
    int getSemester() const;
    bool getActive() const;
};

//Default constructor
Student::Student(){
    AM= 0;
    name= new char[0];
    semester= 0;
    active= 0;
}

//Initialization with data
Student::Student(const int am, const char* n, const int sem, const bool ac){
    AM= am;
    name= new char[strlen(n)+1];
    strcpy(name, n);
    semester= sem;
    active= ac;
}

//Copy Constructor
Student::Student(const Student& obj){
    AM= obj.AM;
    name= new char[strlen(obj.name)+1];
    strcpy(name, obj.name);
    semester= obj.semester;
    active= obj.active;
}

//Destructor
Student::~Student(){
    delete[] name;
}

/*Getters*/
int Student::getAM() const{
    return AM;
}

string Student::getName() const{
    return string(name);
}

int Student::getSemester() const{
    return semester;
}

bool Student::getActive() const{
    return active;
}

//Read from file
vector<Student> readStudents(const string filename){
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open()){
        cerr<< "Error opening file";
        exit(-1);
    }

    /*
    We want to add the students to a Vector of type 'Student'  
    and return it
    */
    vector<Student> vect;
    int am, sem;
    char* n;
    bool act;

    vector<string> row;
    string line, word;

    while(getline(fin, line)){
        row.clear();
        stringstream ss(line);

        while(getline(ss, word, ',')){
            row.push_back(word);
        }

        /*
        Here we convert the file's data line by line, from type 'string'
        to the data types the Student class needs
        */
        
        //AM
        am= stoi(row[0]);
        //Name
        n= new char[row[1].size()+1];
        strcpy(n, row[1].c_str());
        //Semester
        sem= stoi(row[2]);
        //Active
        act= stoi(row[3]);

        /*
        We push back each student (line) as an element
        in the 'Student' type vector.
        */
        Student s(am, n, sem, act);
        vect.push_back(s);
        delete[] n;
    }
    fin.close();
    cout<< "File read successfully" << endl;
    return vect;
}

//Printing active students
void printActive(vector<Student>& vect){
    for(int i=0; i< vect.size(); i++){
        if(vect[i].getActive()){
            cout<< vect[i].getAM() << ", " << vect[i].getName() << ", " << vect[i].getSemester() << endl;
        }
    }
}

int main(){
    vector<Student> students;
    students= readStudents("Students.csv");
    printActive(students);

    return 0;
}
