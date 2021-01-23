#include<bits/stdc++.h>
using namespace std;
#define int long long


// void printArray(int arr[], int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void printVector(vector<int> &v){ //passing by reference
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int LCM(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void mulString(string &str,int x){
    string origStr=str;
    for(int i=0;i<x;i++){
        str.append(origStr);
    }
}

void solution(string &s, string &t){
    int lcmOfSize=LCM(s.size(),t.size());
    int x= lcmOfSize/s.size();
    int y= lcmOfSize/t.size();

    mulString(s,x-1);
    mulString(t,y-1);
    if(s==t){
        cout<<s<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    

    cin>>t;

    while(t--){
        string s,t;
        cin>>s;
        cin>>t;
        solution(s,t);
        
    }
    
    return 0;
}