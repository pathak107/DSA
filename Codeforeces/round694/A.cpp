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

/*  Note ceil(a+b) < ceil(a)+ ceil(b) 
using this property we can easily maximize the result by having individual sums
i.e max= ceil(a1/x) + ceil(a2/x) + .....
Whereas to get minimum we'll get when we add sum of all then take ceil
i.e ceil((a1+a2+a3+a4+.....)/x)   */

void solution(vector<int> v, int x, int n){
    int totalSum=0;
    int minBeaut=0;
    int maxBeaut=0;
    for(int i=0;i<n;i++){
        maxBeaut+= ceil(v[i]/(double)x);
        totalSum+=v[i];
    }

    minBeaut=ceil(totalSum/(double)x);

    cout<<minBeaut<<" "<<maxBeaut<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t;

    cin>>t;
    int n, ele, x;
    while(t--){
        vector<int> v;//for inputing vector
        cin>>n>>x;
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            v.push_back(ele);
        }

        solution(v,x,n);
        
    }
    return 0;
}