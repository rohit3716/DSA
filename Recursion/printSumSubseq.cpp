#include<bits/stdc++.h>
using namespace std;

void printSubSeq( int idx, vector<int>& ds, int s, int sum, int arr[], int n) {
    if( idx == n)
    {
        if( s == sum ){
        for( auto i:ds) {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
     }
    }

    ds.push_back( arr[idx]);
    s += arr[idx];

    //pick 
    printSubSeq( idx+1, ds, s, sum, arr, n);

    s -= arr[idx];
    ds.pop_back();

    //not pick
    printSubSeq( idx+1, ds, s, sum, arr, n);

}

int main() {

    int arr[4] = { 2, 4, 5, 3};
    int n = 4;
    int sum = 9;
    vector<int> ds;

    printSubSeq(0, ds, 0, sum, arr, n);

    return 0;
}