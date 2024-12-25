/*
Create a class "grades list".  
Each object of the class contains grades of a course for an academic semester.  
The class will support the following functions:  

● Adding a student to the list of students attending the course.  
● Inserting a grade for a student in the previous list.  
● Exporting all grades to a csv file.  

Demonstrate the functionality of the class through an appropriate main.  
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class gradesList{
    private:
    string AM, subject;  //AM= student registration number
    float grade;

    public:
    gradesList();
    gradesList(const string, const string, const float);
    gradesList(const string);
    gradesList(const gradesList&);
    ~gradesList();

    void setGrade(const string, const float);
    void display();

    string getAM() const;
    string getSubject() const;
    float getGrade() const;
};

/*Constructors*/

//Default Constructor
gradesList::gradesList(){
    AM= "N/A";
    subject= "N/A";
    grade= 0;
}

//Initialization with full details
gradesList::gradesList(const string am, const string subj, const float gr){
    AM= am;
    subject= subj;
    grade= gr;
}

//Initialization without full details
gradesList::gradesList(const string am){
    AM= am;
    subject= "N/A";
    grade= 0;
}

//Copy Constructor
gradesList::gradesList(const gradesList& obj){
    AM= obj.AM;
    subject= obj.subject;
    grade= obj.grade;
}

//Destructor
gradesList::~gradesList(){}

//Adding subject and grade to a student that was initialized without full details
void gradesList::setGrade(const string subj, const float gr){
    subject= subj;
    grade= gr;
}

//Print Function
void gradesList::display(){
    cout<< AM << ", " << subject << ", " << grade << endl;
}

/*Getters*/
string gradesList::getAM() const{
    return AM;
}

string gradesList::getSubject() const{
    return subject;
}

float gradesList::getGrade() const{
    return grade;
}

//Export to file
void saveFile(vector<gradesList>& vect){
    ofstream fout;
    fout.open("GradesList.csv");
    if(!fout.is_open()){
        cerr<< "Error creating file";
        exit(-1);
    }

    for(int i=0; i< vect.size(); i++){
        fout<< vect[i].getAM() << ',';
        fout<< vect[i].getSubject() << ',';
        fout<< vect[i].getGrade() << '\n';
    }
    
    cout<< "Grades list saved at GradesList.csv" << endl;
    fout.close();
}

int main(){
    //Constructors Demonstration
    gradesList s0;

    gradesList s1("ice1", "OOP", 10);
    s1.display();
    gradesList s2("ice2", "Physics", 4.9);
    s2.display();
    gradesList s3("ice3", "Math", 6.5);
    s3.display();

    gradesList sX(s3);

    //Initializing student without full details and updating them
    gradesList s4("ice4");
    s4.display();
    s4.setGrade("Algorithms", 7.3);
    s4.display();

    //Exporting to file
    vector<gradesList> gl;
    gl.push_back(s1);
    gl.push_back(s2);
    gl.push_back(s3);
    gl.push_back(s4);
    saveFile(gl);

    return 0;
}
