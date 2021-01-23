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


void solution(vector<int> &v, vector<pair<int,bool>> &cost){
    int totalCost=0;
    int priceIndex=0;
    sort(v.begin(),v.end());
    for(int i=v.size()-1; i>=0;i--){
        if((cost[v[i]-1].first > cost[priceIndex].first) && cost[priceIndex].second==false){
            totalCost+=cost[priceIndex].first;
            cost[priceIndex].second=true;
            priceIndex++;
        }else{
            totalCost+=cost[v[i]-1].first;
        }
    }

    cout<<totalCost<<endl;
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
        int n,m, ele;
        cin>>n>>m;
        vector<int> v;//for inputing vector
        vector<pair<int,bool>> cost;
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            v.push_back(ele);
        }

        for (int i = 0; i < m; i++)
        {
            cin>>ele;
            cost.push_back(make_pair(ele,false));
        }

        solution(v,cost);
        
    }
    
    return 0;
}