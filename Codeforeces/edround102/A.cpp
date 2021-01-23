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


void solution(vector<int> v,int d){
    sort(v.begin(),v.end());
    int maxm=v[v.size()-1];
    if(v[0]+v[1]<=d){
        cout<<"YES"<<endl;
    }
    else if(maxm<=d){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
        int n, ele,d;
        cin>>n>>d;
        vector<int> v;//for inputing vector
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            v.push_back(ele);
        }

        solution(v,d);
        
    }
    
    return 0;
}