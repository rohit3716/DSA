#include<bits/stdc++.h>
using namespace std;

void sortArray( int *arr, int n) {
    int min_idx;
    for( int i = 0; i < n; i++) {
        min_idx = i;
        for (int j = i+1; j < n-1; j++)
        {
            if( arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if( min_idx != i) {
            swap( arr[i], arr[min_idx]);
        }
    }
}

// //using recursion
// int sortArray( int arr[], int n) {

//     if( n == 0 || n == 1){
//         return ;
//     }

//     int min_idx;
//     for (int i = 0; i < n; i++)
//     {
//         if( )
//     }
    
    

// }

int main() {

    int arr[5] = {5,4,2,7,8};

    sortArray(arr,5);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}