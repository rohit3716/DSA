#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this ->data = data;
        this ->next = NULL;
    }

    //destructor
    ~Node() {
        int value = this ->data;
        //memory free
        if (this ->next != NULL)
        {
            delete next;
            this ->next = NULL;
        }
        cout<<"Memory is free for the value "<< value <<endl;
    }
};

void insertAtHead(Node* &head,int d) {
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail,int d) {
    //new node create 
    Node* temp = new Node(d);
    tail ->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail,Node* &head, int position, int d) {

    //Insert at Start
    if(position == 1) {
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp ->next;
        cnt++;
    }

    //inserting at last position
    if(temp ->next == NULL) {
        insertAtTail(tail,d);
        return;
    }

    //creating a node for d;
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next;
    temp ->next = nodeToInsert;
    
}

void print(Node* &head) {
    Node* temp = head;
    while ( temp != NULL)
    {
        cout<<temp->data <<" ";
        temp = temp ->next;
    }
    cout<<endl; 
}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout<<"Cycle is present at " << temp ->data <<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

Node* floydDetectLoop( Node* head) {

    if( head == NULL)
    return NULL;

    Node* slow = head;
    Node* fast = head;

    while ( slow != NULL && fast != NULL)
    {
        fast = fast ->next;
        if(fast != NULL) {
            fast = fast ->next;
        }
        slow = slow ->next;

        if(slow == fast) {
            cout<<" Present at "<<slow->data<<endl;
            return slow;
        }
    }
    
    return NULL;
}

Node* getStartingNode(Node* head) {
    if( head == NULL )
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    while (slow != intersection)
    {
        slow = slow ->next;
        intersection = intersection ->next;
    }

    return slow;
    
}

void removeLoop(Node* head) {
    if(head == NULL)
    return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while (temp ->next != startOfLoop)
    {
        temp = temp ->next;
    }

    temp -> next = NULL; 
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 12);
    insertAtTail(tail, 20);
    insertAtPosition(tail, head, 2, 24);
    
    tail ->next = head ->next;

    // print(head);
    cout<<"Head :- "<< head ->data << endl;
    cout<<"Tail :- "<<tail ->data << endl;

    if( floydDetectLoop(head) != NULL) {
        cout<<"Cycle is present  "<<endl;
    }
    else {
        cout<<"Cycle is not present "<<endl;
    }

    Node* loop = getStartingNode(head);
    cout << "loop starts at " << loop ->data <<endl;

    removeLoop(head);
    print(head);
}