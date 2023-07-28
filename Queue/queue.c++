#include<iostream>
#include<queue>
using namespace std;

int main() {
    // create a queue 
    queue<int> q;
    q.push(11);
    q.push(15);
    q.push(14);

    cout<< "size of queue is :" << q.size() <<endl;

    q.pop();

    cout<< "size of queue is :" << q.size() <<endl;



    return 0;
}