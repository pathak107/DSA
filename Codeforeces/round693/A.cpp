#include<iostream>
using namespace std;

void canCutIntoPeices(int w,int h,int n){
    int width=w, height=h;
    int count=1;
    while(count<n){
        if(width%2==0){
            width=width/2;
            count=2*count;
        }else if(height%2==0){
            height=height/2;
            count=count*2;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}


int main(){

    int t, w, h, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> w>>h>>n;

        canCutIntoPeices(w,h,n);
    }
    return 0;
}