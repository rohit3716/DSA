#include<iostream>
using namespace std;
#include<stack>

int main(){
    string str = "aba";

    stack<char> d;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        d.push(ch);
    }

    string ans = "";

    while(!d.empty()) {
        char ch = d.top();
        ans.push_back(ch);
        d.pop();
    }

    cout<< "answer is : " << ans << endl;

    return 0; 
}