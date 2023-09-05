#include<bits/stdc++.h>
using namespace std;

int getFactorial( int n ) {
    if( n == 1 ) {
        return 1;
    }

    long long ans = n*getFactorial(n-1);

    return ans;
}

int main() {

    int n;
    cout<<"Enter number to get factorial of the number: " << endl;
    cin>>n;

    cout<<"Factorial of the number is :" << getFactorial(n);

    return 0;
}