#include<bits/stdc++.h>
using namespace std;
#define int long long


void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printVector(vector<int> &v){ //passing by reference
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


void solution(){

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    vector<int> v;//for inputing vector

    cin>>t;

    while(t--){
        int n, ele;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            v.push_back(ele);
        }

        solution();
        
    }
    
    return 0;
}