#include<iostream>
using namespace std;

bool isSorted(int *arr, int size) {
    if((size == 0) || (size == 1) ) {  
    return true;
    }

    if(arr[0] > arr[1])
    return false;
    else{
        bool remainingPart = isSorted(arr+1,size-1);
        return remainingPart;
    }
}

int main() {
    int arr[6] = {2,3,5,7,9,10};
    int ans = isSorted(arr,6);
    if(ans)
    cout<<"Array is sorted"<<endl;
    else
    cout<<"Array is not sorted "<<endl;
}