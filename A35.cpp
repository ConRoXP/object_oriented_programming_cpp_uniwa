/*
Create a “UString” class which represents strings that
consist exclusively of uppercase Latin characters ([A..Z]).
The class will provide the following functionality:

● Write a function that will accept two positive integers N and K,
and will create and return a collection of N different UString objects
each of which will consist of up to K characters.
● Write a function that will print the strings of the
previous collection to an ostream channel.

The usage of vectors is not allowed.
*/

#include <iostream>
using namespace std;

class UString{
    private:
    int N, K; //N: row, K: column
    char** arr;

    public:
    UString();
    UString(const int, const int);
    ~UString();
    char** getPtr() const;
    int getN() const;
    int getK() const;
};

UString::UString(){}

//2D array allocation
UString::UString(const int n, const int k){
    N= n;
    K= k;
    arr= new char*[N];
    for(int i=0; i< N; i++){
        arr[i]= new char[K];
    }
}

UString::~UString(){
    for(int i=0; i< N; i++){
        delete arr[i];
    }
    delete arr;
}

char** UString::getPtr() const{
    return arr;
}

//return row
int UString::getN() const{
    return N;
}

//return column
int UString::getK() const{
    return K;
}

//output operator overload
ostream &operator<<(ostream &os, const UString& obj){
    int n= obj.getN();
    int k= obj.getK();

    for(int r=0; r< n; r++){
        for(int c=0; c< k; c++){
            //array.getPtr()[i][j] returns a pointer to array[i][j]
            os<< (obj.getPtr()[r][c]);
        }
        cout<< endl;
    }
    return os;
}

UString create(const int n, const int k){
        UString obj(n, k);
        //In each [n][k] position we input a random char
        for(int row= 0; row< n; row++){
            for(int column=0; column< k; column++){
                (obj.getPtr()[row][column])= ('A'+ rand()%26);
            }
        }
    return obj;
}

int main(){
    //3 rows, 8 columns
    UString ptr= create(3, 8);
    cout<< ptr;

    return 0;
}
