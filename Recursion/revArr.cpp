#include<bits/stdc++.h>
using namespace std;

void print( int arr[], int n ){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void revArr( int i, int arr[], int n){
    if( i >= n/2 ){
        return;
    }
    swap( arr[i], arr[n-i-1] );

    revArr(i+1, arr, n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    revArr(0, arr, n);
    print( arr, n);
    
    return 0;
}