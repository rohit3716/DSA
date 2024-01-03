//Q. you have coins of $1, $5 and $10, Find minimum number of coins used to get $67? T.C. : O(n);

#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<" Enter the total amount: " << endl;
    int n;
    cin>>n;

    int coins = 0;

    while( n > 0 ){
        if( n > 9 ){
            coins += n/10;
            n %= 10;
        }
        else if( n > 4 ){
            coins += n/5;
            n %= 5;
        }
        else{
            coins += 1;
            n--;
        }
    }
    cout<<"minimum number of coins: " << coins<< endl;
    return 0;
}