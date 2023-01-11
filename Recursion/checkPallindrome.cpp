#include<iostream>
using namespace std;

bool checkPallindrome(string str,int i, int j) {
    //base case
    if(i > j)
    return true;

    if(str[i] != str[j])
        return false;
    
    else{
        //Recursive Call
        return checkPallindrome(str,i+1,j-1);
    }
}

int main() {
    string name = "babha";
    cout<<endl;

    bool isPallindrome = checkPallindrome(name,0,name.length()-1 );

    if (isPallindrome)
    {
        cout<<"This is a pallindrome"<<endl;
    }
    else {
        cout<<"This is not a pallindrome"<<endl;
    }
    
}