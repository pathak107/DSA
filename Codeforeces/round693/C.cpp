#include <iostream>
#include <vector>
using namespace std;

void longJumps(vector<int> a, int n){
    int maxScore=INT16_MIN;
    vector<int> finalIndexes;
    for(int i=0;i<n; i++){
        if(i+a[i]>=n){
            maxScore=max(maxScore, a[i]);
        }else{
            finalIndexes.push_back(i);
        }
    }

    for(int i:finalIndexes){
        int score=0;
        for(int j=i; j<n;j+=a[j]){
            score+=a[j];
        }
        maxScore=max(maxScore,score);
    }
    cout<<maxScore<<endl;
}

int main()
{

    int t, n, x;
    vector<int> a;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin>>x;
            a.insert(a.begin()+j,x);
        }

        longJumps(a, n);
    }
    return 0;
}