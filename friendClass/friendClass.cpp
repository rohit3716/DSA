#include<bits/stdc++.h>
using namespace std;

//forward declaration
class Complex;

class Calculator{
    public:
    int add( int a, int b ){
        return a+b;
    }
    
    int sumReal( Complex, Complex );
    int sumImaginary( Complex, Complex);
};


class Complex{
    int a, b;
    //individually declaring functions as friends
    // friend int Calculator::sumReal(Complex, Complex);
    // friend int Calculator::sumImaginary(Complex, Complex);

    
    friend class Calculator;

    public:
    void setNumber(int n1, int n2){
        a = n1;
        b = n2;
    }

    void printNumber(){
        cout<<"Number is: "<< a <<" + "<< b <<"i"<<endl;
    }
};

int Calculator::sumReal(Complex o1, Complex o2){
    return o1.a+o2.a;
}

int Calculator::sumImaginary(Complex o1, Complex o2){
    return o1.b+o2.b;
}
int main(){

    Complex o1, o2;
    o1.setNumber(3, 4);
    o1.printNumber();
    o2.setNumber(4, 5);
    o2.printNumber();

    Calculator calc;
    int res = calc.sumReal(o1, o2);
    cout<<"Real part sum: "<<res<<endl;

    int resi = calc.sumImaginary(o1, o2);
    cout<<"Imaginary part sum: "<<resi<<endl;
    return 0;
}