#include<bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    virtual void eat(){
        cout<<"I am eating generic food"<<endl;
    }
};

class Cat:public Animal
{
    public:
    void eat(){
        cout<<"I am eating cat food"<<endl;
    }
};

class Dog:public Animal
{
    public:
    void eat(){
        cout<<"I am eating Dog Food"<<endl;
    }
};

void function1(Animal *xyz){
    xyz->eat();
}

int main(){

    Animal *ptr;
    Cat catObj;
    Dog dogObj;

    ptr = &catObj;
    function1(ptr); //achieving runtime polymorphism...

    ptr = &dogObj;
    function1(ptr);

    return 0;
}