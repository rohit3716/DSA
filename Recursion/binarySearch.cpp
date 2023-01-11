#include<iostream>
using namespace std;

void print(int* arr,int s,int e) {
    for (int i = s; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

bool binarySearch(int* arr,int s,int e,int key) {
    
    print(arr,s,e);

    //base case
    if(s>e)
    return false;
    int mid = s + (e-s)/2;
    cout<<"Mid element is "<<arr[mid]<<endl;
    //if element got found
    if(arr[mid] == key)
    return true;

    if(arr[mid] < key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
}

int main() {
    int arr[6] = {3,4,5,7,8,44};
    int size = 6;
    int key = 65;
    bool ans = binarySearch(arr,0,5,key);
    if(ans){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }
}