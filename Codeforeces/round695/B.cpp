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

int coutIntimidation(vector<int> &a,int n){
    int iValue=0;
    for(int j=1;j<n-1;j++){
        if( (a[j]>a[j+1] && a[j]>a[j-1]) ||  ((a[j]<a[j+1] && a[j]<a[j-1]))  ) {
            iValue++;
        }
    }
    return iValue;
}

bool checkHillVall(vector<int> &a,int n, int j){
    if( (a[j]>a[j+1] && a[j]>a[j-1]) ||  ((a[j]<a[j+1] && a[j]<a[j-1]))  ) {
        return true;
    }else{
        return false;
    }
}


void solution(vector<int> &a, int n){
    int minVal=INT_MAX;
    int temp;

    for(int j=1;j<n-1;j++){
        if( (a[j]>a[j+1] && a[j]>a[j-1]) ||  ((a[j]<a[j+1] && a[j]<a[j-1]))  ) {
            temp=a[j];
            a[j]=a[j-1];
            if(checkHillVall(a,n,j+1)){
                a[j]=a[j+1];
                if(checkHillVall(a,n,j+1)){
                    a[j]=temp;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
            // a[j]=a[j+1];
            // minVal=min(minVal,coutIntimidation(a,n));
            // a[j]=temp;
        }
    }

    minVal=min(minVal,coutIntimidation(a,n));
    cout<<minVal<<endl;
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
        vector<int> v;//for inputing vector
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            v.push_back(ele);
        }

        solution(v,n);
        
    }
    
    return 0;
}