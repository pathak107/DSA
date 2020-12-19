#include<iostream>
#include<stack>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    stack<int> s;
    for(int i=0;i<50;i++){
        s.push(i);
    }

    int size=s.size();
    for(int i=0;i<size;i++){
        cout<<s.top()<<endl;
        s.pop();
    }
}