#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int front, rear, capacity;
    int *arr;
    Queue( int c ) {
        capacity = c;
        front = rear = 0;
        arr = new int[capacity];
    }
    ~Queue() {
        delete[] arr;
    }

    void enQueue( int data){
        //check if Queue is full or not
        if( capacity == rear ) {
            cout<<"Queue is Full"<<endl;
            return;
        }

        //insert element at the rear
        else{
            arr[rear] = data;
            rear++;
        }
        return;
    }

    //function to delete an element from the front of the Queue
    void deQueue() {
        //if queue is empty
        if( rear  == front ) {
            cout<< "Queue is empty" << endl;
            return;
        }
        //shift all the elements from index 2 till rear to the left by one
        else{
            for (int i = 0; i < rear-1; i++)
            {
                arr[i] = arr[i+1];
            }
            //decrement rear
            rear--; 
        }
        return;
    }

    //print queue elements
    void queueDisplay() {
        int i;
        if( front == rear ) {
            cout<<"Queue is empty" << endl;
            return;
        }

        //traverse front to rear and print all elements
        for( i = front; i < rear; i++) {
            cout<< arr[i] << " ";
        }
        cout<<endl;
        return;
    }

    void queueFront(){
        if( front == rear ) {
            cout<< "Queue is empty"<< endl;
            return;
        }
        cout<< " Front element : " << arr[front];
        return;
    }
};


int main(){
    Queue q(4);
    
    // q.enQueue();
    q.enQueue(45);
    q.enQueue(46);
    q.enQueue(47);
    q.enQueue(48);

    q.queueDisplay();
    q.deQueue();
    q.queueDisplay();
    q.queueFront();

    return 0;    
}