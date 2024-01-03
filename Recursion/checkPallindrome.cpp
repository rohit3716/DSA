#include<iostream>
using namespace std;

// bool checkPallindrome(string str,int i, int j) {
//     //base case
//     if(i > j)
//     return true;

//     if(str[i] != str[j])
//         return false;
    
//     else{
//         //Recursive Call
//         return checkPallindrome(str,i+1,j-1);
//     }
// }

bool checkPallindrome(string& str, int i, int n){
    if( i >= n/2) return true;

    if( str[i] != str[n-i-1]) return false;

    return checkPallindrome( str, i+1, n);
}

int main() {
    string name = "bab";
    cout<<endl;

    bool isPallindrome = checkPallindrome(name,0,name.size() );

    if (isPallindrome)
    {
        cout<<"This is a pallindrome"<<endl;
    }
    else {
        cout<<"This is not a pallindrome"<<endl;
    }
    
}