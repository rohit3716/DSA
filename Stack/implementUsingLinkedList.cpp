#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack {
    public:
    Node* head;
    int size;

    Stack( int size ) {
        this ->size = size;
        this ->head = NULL;
    }

        void push( int data) {
            int cnt = 0;
            Node* temp = head;
            while (temp != NULL)
            {
                temp = temp ->next;
                cnt++;
            }

            if (cnt < size)
            {
                    //insert at head
                Node* newNode = new Node(data);
                if( head == NULL ) {
                    head = newNode;
                    return;
                }

                else {
                    newNode -> next = head;
                    head = newNode;
                }
            }
            else {
                cout<<" Stack Overflow" <<endl;
            }   
        }


        void peek() {
            if( head == NULL )
            cout << "Stack is empty"<< endl;
            else
            cout<< head -> data <<endl;
        }

        void pop() {
            if( head == NULL )
            {
                cout << "Stack Underflow" <<endl;
            }
            else {
                Node* temp = head;
                cout<< "Poped element is: " << temp ->data << endl;
                head = head -> next;
                delete temp;
            }
        }

        void isEmpty() {
            if( head == NULL ){
            cout<< "Stack is empty " << head -> data <<endl;
            }
            else{ 
            cout<< "Stack is empty " <<endl;
            }
        }
};
int main() {
    Stack s(5);
    s.push(10);
    s.push(12);
    s.push(78);
    s.push(19);
    s.push(75);
    s.peek();
    s.isEmpty();



    
}