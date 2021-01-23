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


void solution(string b, int n){
    string a,d;
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            a.append("1");
            if(b[0]=='0'){
                d.append("1");
            }else{
                d.append("2");
            }
            
        }
        else{
            if(b[i]=='0' && d[i-1]!='1'){
                a.append("1");
                d.append("1");
            }else if(b[i]=='0' && d[i-1]=='1'){
                a.append("0");
                d.append("0");
            }

            if(b[i]=='1' && d[i-1]!='2'){
                a.append("1");
                d.append("2");
            }else if(b[i]=='1' && (d[i-1]=='2' || d[i-1]=='0')){
                a.append("0");
                d.append("1");
            }
        }
    }

    cout<<a<<endl;
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(10);
    // cout << fixed;

    int t;
    

    cin>>t;

    while(t--){
        int n, ele;
        cin>>n;
        string b;
        cin>>b;
        solution(b,n);
    }
    
    return 0;
}