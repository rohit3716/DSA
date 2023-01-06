#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<endl;
    }
    
}

int main() {
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>arr[i];
    }
    printArray(arr,n);
    
}