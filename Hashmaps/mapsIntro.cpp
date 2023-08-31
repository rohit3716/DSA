#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    //creation
    map<string, int> m;

    //insertion
    //1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    //2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    //3
    m["mera"] = 2;

    //What will happen if we put again same key into unordered map
    m["mera"] = 1; //It will update the value, it will do not create a new one pair for this.

    //search
    cout<< m["mera"] << endl;
    cout<< m.at("babbar") <<endl;

    cout<<m["unknownKey"] <<endl; //this line will first search in the list if it is present it will give output
                                    // as the value of that key, when not present then it will make a key of that name and assign value to 0;

    cout<<m.at("unknownKey")<<endl;  

    //size

    cout<< m.size() <<endl;

    //to check presence
    cout<< m.count("love") <<endl;

    //erase
    m.erase("love");
    cout<< m.size() <<endl;

    //Iteration in map
    //1
    // for( auto i:m){
    //     cout<<i.first<< " " << i.second << endl;
    // }

    //2
    //using iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while( it != m.end() ) {
         cout<< it->first << " " << it->second <<endl;
         it++;
    }

    //unordered map doesn't print values in the same order as you have inserted into it

    return 0;

}