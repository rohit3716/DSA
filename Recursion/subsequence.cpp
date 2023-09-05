#include<bits/stdc++.h>
using namespace std;

void printSubsequence( int arr[], int n, vector<int> &ds, int idx){
    if( idx == n ) {
        for( auto it:ds) {
            cout<< it<<" ";
        }
        if( ds.size() == 0 ) {
            cout<<"{}";
        }
        cout<<endl;
        return;
    }

    //take or pick the particular index to the subsequence

    ds.push_back(arr[idx]);
    printSubsequence( arr, n, ds, idx+1);
    ds.pop_back();

    //not take this element will not going to be add in our subsequence
    printSubsequence( arr, n, ds, idx+1);

}

int main() {

    int arr[3] = {1, 3, 2 };

    int n = 3;
    vector<int> ds;
    printSubsequence( arr, n, ds, 0);

    return 0;
}