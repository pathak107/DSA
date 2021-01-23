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


void solution(int n){
    string num="9";
    int unitDigit=7;
    for(int i=1;i<n;i++){
        unitDigit=(unitDigit+1)%10;
        num.append(to_string(unitDigit));
    }
    cout<<num<<endl;
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
        int n, ele;
        cin>>n;
        // vector<int> v;//for inputing vector
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>ele;
        //     v.push_back(ele);
        // }
        solution(n);

    }

    return 0;
}
