/*
Create a template class "Queue" which will support the the following functions:  

● Insert Object at the end of the queue (Enqueue).  
● Delete the first item in the queue (Dequeue).  
● Return the size of the queue.  
● Check for equality with another queue  
(If the containing objects are "equal" one to one).  

Demonstrate the operation of a queue with objects of one class  
having only two attributes: an integer and a C-String.
*/

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Queue{
    private:
    vector<T> datum;

    public:
    void enqueue(T);
    void dequeue();
    int returnSize();

    bool compare(Queue<T>&);
    void display();
};

//Enqueue
template<typename T>
void Queue<T>::enqueue(T dt){
    datum.push_back(dt);
}

//Dequeue
template<typename T>
void Queue<T>::dequeue(){
    datum.erase(datum.begin());
}

//Return size
template<typename T>
int Queue<T>::returnSize(){
    return datum.size();
}

//Comparison
template<typename T>
bool Queue<T>::compare(Queue<T>& right){
    if(datum== right.datum) return 1;
    return 0;
}

//Print function
template<typename T>
void Queue<T>::display(){
    for(int i=0; i< datum.size(); i++){
        cout<< datum[i] << " ";
    }
    cout<< endl;
}

/*
This is one of the first programs I wrote and testing with a different class,  
as the exercise asks for, felt convoluted at the time.  
As I got more experienced, I performed such a task in exercises A15 and A8.
*/

int main(){
    //Testing with int
    Queue<int> q1;
    q1.enqueue(123);
    q1.enqueue(456);
    q1.enqueue(789);
    cout<< "q1: " << endl;
    q1.display();

    q1.dequeue();
    cout<< "Deleting first item of q1:" << endl;
    q1.display();

    //Testing with C string
    Queue<const char*> q2;
    q2.enqueue("C_String 1");
    q2.enqueue("C_String 2");
    q2.enqueue("C_String 3");
    cout<< "q2: " << endl;
    q2.display();

    q2.dequeue();
    cout<< "Deleting first item of q2:" << endl;
    q2.display();

    /*Comparing two queues*/

    //Demonstrating if equal
    cout<< "q1==q1 ? --> " << q1.compare(q1) << endl;

    //Demonstrating if not equal
    Queue<int> q1b;
    q1b.enqueue(123);
    q1b.enqueue(456);
    cout<< "q1== q1b ? --> " << q1.compare(q1b) << endl;

    return 0;
}
