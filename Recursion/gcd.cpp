#include<iostream>
using namespace std;

void gcd(int a, int b){
    int r=b%a;
    if(r==0){
        cout<<"GCD : "<<a;
        return;
    }
    b=a;
    a=r;
    gcd(a,b);
}

int main(){
    gcd(70,60);
    cout<<60%70;
    return 0;
}