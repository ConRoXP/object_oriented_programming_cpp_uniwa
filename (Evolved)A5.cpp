/*
I modified A5 to be an actual usable program instead of a demonstration of functions.  
The differences from the exam version are marked in comments.  
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

Entry::Entry(){
    word= "N/A";
    definition= "N/A";
}

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

class Dictionary{
    private:
    vector<Entry> vect;

    public:
    void addWord(const Entry&);
    Entry findWord(const string&);
    void removeWord(const string&);
    int findIndex(const string&);

    void saveDictionary();
    Dictionary readDictionary(int&);
    void display();
    void sort();
};

void Dictionary::addWord(const Entry& en){
    vect.push_back(en);
    cout<< "Entry added" << endl;
}
/*

Difference #1: Instead of an Entry obj, I pass a string which is
the word the user wants to find

*/
Entry Dictionary::findWord(const string& str){
    for(int i=0; i< vect.size(); i++){
        if(vect[i].getWord()== str){
            cout<< "Entry exists" << endl;
            return vect[i];
        }
    }
    Entry e;
    cout<< "Entry does not exist" << endl;
    return e;
}    
/*

Difference #2: The findIndex func must now work with a string instead of an Entry obj

*/
int Dictionary::findIndex(const string& str){
    for(int i=0; i< vect.size(); i++){      
        if(vect[i].getWord()== str){
            return i;
        }
    }
    return -1;
}
/*

Difference #3: Instead of an Entry obj, here too I pass a string

*/
void Dictionary::removeWord(const string& str){
    int itr= findIndex(str);    
    if(itr!= -1){    
        vect.erase(vect.begin()+itr);
        cout<< "Entry removed successfully" << endl;
    }
    else cout<< "Invalid does not exist" << endl;
    
    return;
}

void Dictionary::saveDictionary(){
    ofstream fout;
    fout.open("Dictionary.txt");
    if(!fout.is_open()){
        cerr<< "Failed to create file";
        return;
    }

    for(int i=0; i< vect.size(); i++){
        fout<< vect[i].getWord() << ',' << vect[i].getDef() << '\n';
    }
    fout.close();
    cout<< "Dictionary saved at Dictionary.txt" << endl;
}

void Dictionary::display(){
    for(int i=0; i< vect.size(); i++){
        cout<< vect[i].getWord() << ": " << vect[i].getDef() << endl;
    }
}

Dictionary Dictionary::readDictionary(int &counter){
    ifstream fin;
    fin.open("Dictionary.txt");
    if(!fin.is_open()){    //Here we check if the name is valid - it must be 'Dictionary.txt'
        throw(-1);
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
    }

    Dictionary dictionary;
    for(int i=0; i< temp.size(); i++){
        dictionary.addWord(temp[i]);
        counter++;
    }
    cout<< "File read successfully" << endl;
    fin.close();
    return dictionary;
}

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
    //If x is of type int and user inputs char, the program will break
    char x;
    /*
    If the Dictionary is empty and the user chooses to sort it, we get a Segmentation Fault.
    This counter is the failsafe.
    */
    int counter= 0;
    string word, def;
    Dictionary dict;

    while(1){
        cout<< "\n[1]Add Entry\t[2]Search for Entry\t[3]Remove Entry\n[4]Save to file\t[5]Read from file\t[6]Print Dictionary\n[7]Sort Dictionary\t[8]Exit" << endl;
        cin>> x;

        if(x== '1'){
            cout<< "Enter word" << endl;
            cin>> word;
            cout<< "Enter definition" << endl;
            cin>> def;
            Entry e(word, def);
            dict.addWord(e);
            counter++;  //Counter goes up with every Entry added
        }
        else if(x== '2'){
            cout<< "Enter the entry you are searching" << endl;
            cin>> word;
            dict.findWord(word);
        }
        else if(x== '3'){
            cout<< "Enter entry to delete" << endl;
            cin>> word;
            dict.removeWord(word);
            counter--; //Counter goes down with every Entry removed
        }
        else if(x== '4'){
            dict.saveDictionary();
        }
        else if(x== '5'){
            try{    
                dict= dict.readDictionary(counter);  //Here I use try-catch to check if the file name is valid
            }
            catch(int){
                cerr<< "Error: File name must be 'Dictionary.txt'" << endl;
            }
        }
        else if(x== '6'){
            dict.display();
        }
        else if(x== '7'){
            if(counter> 0){ //If the counter is zero, sorting is not allowed
            dict.sort();
            cout<< "Dictionary sorted" << endl;
            }
            else cout<< "Cannot sort - Dictionary is empty" << endl;
        }
        else if(x== '8'){
            break;
        }
        else cout<< "Invalid input" << endl;
    }
    return 0;
}
