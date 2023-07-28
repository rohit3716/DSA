#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

class heap {
   public:
   int arr[100];
   int size = 0;

   heap() {
     arr[0] = -1;
     size = 0;
   }

   void insert( int val ) {
     size = size + 1;
     int index = size;
     arr[index] = val;

     while( index > 1 ) {
        int parent = index/2;

        if( arr[parent] < arr[index] ) {
            swap( arr[parent], arr[index]);
            index = parent;
        }
        else{
            return;
        }
     }
   }

   void deleteFromHeap(){
    if( size == 0) {
        cout<<"Nothiing to delete" << endl;
    }

    // step 1: Put last element into root element
    arr[1] = arr[size];

    // step 2: remove last element
    size--;

    // Step 3: take root node to its correct position 

    int i = 1;
    while( i < size ) {
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;

        if( leftIndex < size && arr[i] < arr[leftIndex]) {
            swap( arr[i], arr[leftIndex]);
        }
        else if( rightIndex < size && arr[i] < arr[rightIndex]) {
            swap( arr[i], arr[rightIndex]);
        }
        else{
            return;
        }
    }
   }

  
   void print( ) {
    for (int i = 1; i <= size; i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
   }
};

 void heapify( int arr[], int n, int i ) {
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;

    if( left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if( right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if( largest != i ) {
        swap( arr[largest], arr[i]);
        heapify( arr, n, largest);
    }
   }

void heapSort( int arr[], int n) {
    int size = n;

    while( size > 1 ) {
        // step 1: swap 
        swap( arr[size], arr[1]);

        //step 2: 
        size--;

        //step-3
        heapify( arr, size, 1);
    }
}

int main() {
    heap h;
    h.insert(21);
    h.insert(22);
    h.insert(23) ;
    h.insert(24);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 50, 52};
    int n = 5;
    for( int i = n/2 ; i > 0; i--) {
        heapify( arr, n, i);
    }

    //heap creation
    cout<<"Printing the array now :  ";
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);

    cout<<"Printing the array now :  ";
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    cout<<"Using Priority Queue" <<endl;

    //MAX HEAP
    priority_queue<int> pq;
    pq.push(43);
    pq.push(45);
    pq.push(41);
    pq.push(76);
    pq.push(47);
    

    cout<<"Element at top" << pq.top() <<endl;

    pq.pop();

    cout<<"Element at top" << pq.top() <<endl;

    cout<<" Size is: " << pq.size() << endl;

    if( (pq.empty())) {
        cout<<"pq is empty" << endl;
    }
    else{
        cout<< " pq is not empty" << endl;
    }


    //  MIN HEAP
    priority_queue<int, vector<int>, greater<int> > minheap;

    minheap.push( 45);
    minheap.push( 46);
    minheap.push( 42);
    minheap.push( 43);
    minheap.push( 48);

    cout<<"Element at top" << minheap.top() <<endl;

    minheap.pop();

    cout<<"Element at top" << minheap.top() <<endl;

    cout<<" Size is: " << minheap.size() << endl;

    if( (minheap.empty())) {
        cout<<"minheap is empty" << endl;
    }
    else{
        cout<< " minheap is not empty" << endl;
    }

    return 0;
}