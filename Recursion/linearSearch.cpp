#include<iostream>
using namespace std;

void print(int* arr,int n) {
    cout<<"Size of an array is "<<n<<endl;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}

bool linearSearch(int arr[],int size,int k) {
    
    print(arr,size);
    //base case
    if( size == 0 ) {
        return false;
    }
    if(arr[0] == k ) {
        return true;
    }

   bool remainingPart =  linearSearch( arr+1, size-1, k);

   return remainingPart;
}

int main() {
    int arr[5] = {3,5,6,7,8};
    int key = 7;
    int size = 5;
    bool ans = linearSearch(arr,size,key);
    if(ans){
    cout<<"Present"<<endl;
    }
    else{
    cout<<"Absent"<<endl;
    }
}