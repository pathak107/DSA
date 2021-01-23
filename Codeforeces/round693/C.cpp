#include <bits/stdc++.h>
using namespace std;


/* note that score(i) = score(i+a[i]) + a[i] 
So if we traverse from the end and maintain an array score and then we can find the maximum element */
void longJumps(vector<int> &a, int n){
    vector<int> score(n);
    for(int i=n-1;i>=0;i--){
        if(i+a[i]<n){
            score[i]=score[i+a[i]] + a[i];
        }else{
            score[i]= a[i];
        }
        
    }

    int maxm=INT_MIN;
    for(int i=0;i<score.size();i++){
        maxm=max(maxm,score[i]);
    }

    cout<<maxm<<endl;
}

int main()
{

    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> a;
        for (int j = 0; j < n; j++)
        {
            cin>>x;
            a.push_back(x);
        }

        longJumps(a, n);
        
    }
    return 0;
}