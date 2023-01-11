#include<iostream>
using namespace std;

int sumArr(int *arr,int size) {
    if(size == 0)
    return 0;

    if(size == 1){
        return arr[0];
    }

    int remainingPart = sumArr(arr+1,size-1);
    int sum = arr[0] + remainingPart;

    return sum;
    
}

int main() {
    int arr[6] = {2,4,3,8,6,9};
    int ans = sumArr(arr,6);
    cout<<"Sum of given array is:- "<<ans<<endl;
}