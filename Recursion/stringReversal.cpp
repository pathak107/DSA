#include<iostream>
#include<string>
using namespace std;
string swap(char str1, string str2){
    string str3;
    return str3= str1+str2;
}

string Rev(string str, int n){
    if(n==1){
        string s(1,str[0]);
        return s;
    } 
    else{
        return swap(str[n-1],Rev(str,n-1));
    }
}

int main(){
    string str="123456789";
    str= Rev(str,str.length());
    cout<<str;
    return 0;
}