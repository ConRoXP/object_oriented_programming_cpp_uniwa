/*
Create a class that will represent the entity “Dictionary Entry”.  
Each entry will contain only the term and its meaning.  
Create a class that will represent the entity “Dictionary” which will  
contain a collection of Entries and will have the following capabilities:  

● It will add an entry to the dictionary.  
● It will delete an entry from the dictionary.  
● It will return an entry from the dictionary (search based on the term).  
● It will save the dictionary to a text file with the text formatting selected  
by the student being examined.  
● It will read the dictionary from a text file (with the previous formatting)  
● It will return a sorted “list” of the terms contained in the dictionary  
(in a structure selected by the student being examined).  

Demonstrate the operation of the above through an appropriate main function.  
*/

/*
Out of all the programs I wrote in my preparation for the final exam,  
I'd say this is my favorite. Partially due to its size and complexity  
but mostly because of how I dealt with the issue in lines 169 to 181.
It may seem obvious to someone with experience, but for me at the time it wasn't as much.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Entry{
    private:
    string word;
    string definition;

    public:
    Entry();
    Entry(const string, const string);
    ~Entry();
    string getWord() const;
    string getDef() const;
};

//Default constructor
Entry::Entry(){
    word= "N/A";
    definition= "N/A";
}

//Initialization with word & definition
Entry::Entry(const string wrd, const string def){
    word= wrd;
    definition= def;
}

Entry::~Entry(){}

string Entry::getWord() const{
    return word;
}

string Entry::getDef() const{
    return definition;
}

//Dictionary is a vector
class Dictionary{
    private:
    vector<Entry> vect;

    public:
    void addWord(const Entry&);
    Entry findWord(const string&);
    void removeWord(const Entry&);
    int findIndex(const Entry&);

    void saveDictionary();
    Dictionary readDictionary();
    void display();
    void sort();
};

//Add an entry to the dictionary
void Dictionary::addWord(const Entry& en){
    vect.push_back(en);
}

//Search for an entry
Entry Dictionary::findWord(const string& str){
    for(int i=0; i< vect.size(); i++){
        if(vect[i].getWord()== str){
            return vect[i];
        }
    }
    Entry e;
    cout<< "Entry not found" << endl;
    return e;
}

//Return position of an entry in the Dictionary vector
int Dictionary::findIndex(const Entry& en){
    for(int i=0; i< vect.size(); i++){
        if(vect[i].getWord()== en.getWord()){
            return i;
        }
    }
    return -1;
}

//Remove an entry
void Dictionary::removeWord(const Entry& en){
    int itr= findIndex(en);
    if(itr!= -1){
        vect.erase(vect.begin()+itr);
    }
    else return;
}

//Save dictionary to file
void Dictionary::saveDictionary(){
    ofstream fout;
    fout.open("Dictionary.txt");
    if(!fout.is_open()){
        cerr<< "Failed to create file";
        exit(-1);
    }

    for(int i=0; i< vect.size(); i++){
        fout<< vect[i].getWord() << ',' << vect[i].getDef() << '\n';
    }
    fout.close();
    cout<< "Dictionary saved at Dictionary.txt" << endl;
}

//Print dictionary
void Dictionary::display(){
    for(int i=0; i< vect.size(); i++){
        cout<< vect[i].getWord() << ", " << vect[i].getDef() << endl;
    }
}

//Read dictionary from file
Dictionary Dictionary::readDictionary(){
    ifstream fin;
    fin.open("Dictionary.txt");
    if(!fin.is_open()){
        cerr<< "Error opening file";
        exit(-1);
    }

    vector<Entry> temp;
    string wrd, def;

    vector<string> row;
    string line, word;

    while(getline(fin, line)){
        row.clear();
        stringstream ss(line);

        while(getline(ss, word, ',')){
            row.push_back(word);
        }

        wrd= row[0];
        def= row[1];
        Entry en(wrd, def);
        temp.push_back(en);
        /*
        We save the entries we read from the file in
        a temporary vector of type Entry
        */
    }

    /*
    However we need to return as data type Dictionary and not Entry.
    The class Dictionary is a vector of Entries...
    */
    Dictionary dictionary;
    for(int i=0; i< temp.size(); i++){
        dictionary.addWord(temp[i]);  //...and as such we push back each Entry into a vector of type Dictionary...
    }
    cout<< "File read successfully" << endl;
    fin.close();
    return dictionary;    //...and return it :D
}

//Sorting Dictionary
void Dictionary::sort(){
    for(int i=0; i< vect.size()-1; i++){
        for(int j=0; j< vect.size()-i-1; j++){
            if(vect[j].getWord() > vect[j+1].getWord()){
                swap(vect[j], vect[j+1]);
            }
        }
    }
}

int main(){
    //Initializing Entries
    Entry e1("Word1", "Def1");
    Entry e2("Word2", "Def2");
    Entry e3("Word3", "Def3");

    //Adding Entries to Dictionary
    Dictionary dict;
    dict.addWord(e1);
    dict.addWord(e2);
    dict.addWord(e3);
    dict.display();
    cout<< endl;

    //Removing an Entry
    cout<< "Removing e1:" << endl;
    dict.removeWord(e1);
    dict.display();
    dict.addWord(e1); //and adding it back
    cout<< endl;

    //Searching for an Entry
    dict.findWord("Word2");

    //Saving Dictionary to a file
    dict.saveDictionary();
    cout<< endl;

    //Reading the Dictionary from a file
    Dictionary dict2;
    dict2= dict2.readDictionary();
    cout<< "Printing dict2" << endl;
    dict2.display();
    cout<< endl;

    //Sorting a Dictionary
    cout<< "dict:" << endl;
    dict.display();
    cout<< endl;
    cout<< "Sorting and printing dict" << endl;
    dict.sort();
    dict.display();

    return 0;
}
