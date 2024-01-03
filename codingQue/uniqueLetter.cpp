//Input: abbcccdddd     output:abcd;

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abbcccdddd";

    string unique = "";
    int i = 0;
    int j = 1;
    while (i < s.size())
    {
        unique += s[i];
        i = i+j;
        j++;
    }
    
    cout<< "Unique characters: " << unique<< endl;
    
}