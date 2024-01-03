//Printing pattern using single loop 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int k = 1;
    for (int j = 1; j <= n*(n+1)/2; j++)
    {
        cout<<1<<" ";
        if (j % ((k*(k+1))/2) == 0 )
        {
            cout<<endl;
            k++;
        }
        
    }
    
    
    return 0;
}