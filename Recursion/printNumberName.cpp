#include<bits/stdc++.h>
using namespace std;

void printNumber( string str[], int n) {

    if( n == 0 ) {
        return;
    }

    
    printNumber( str, (n/10));

    int number = n%10;
    cout<<str[number] << " ";
}


int main(){

    int n = 589;
    // cout<<" Enter the input here: " << endl;
    // cin>>n;

    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    printNumber(str, n);

    return 0;
}