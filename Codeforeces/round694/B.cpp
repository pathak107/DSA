#include <bits/stdc++.h>
using namespace std;
#define lint long long

void printArray(lint arr[], lint n)
{
    for (lint i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVector(vector<lint> &v)
{ //passing by reference
    for (lint i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

/*Let's maintain the list of pairs {ai,cnti} — it indicates a range of cnti elements equal to ai.
 Then we can easily implement the operation performed by the robot: if we consider pair {a,cnt},
  we either append the array with a pair {a/x,cnt⋅x}, or terminate the process.
   The answer to the problem equals to sum of values ai⋅cnti. */

/*Each number ai will be copied to the end of the array at most O(logA) times, 
since each time ai is divided by x. Since there are n elements in the array initially,
 the total complexity of this solution is O(nlogA).*/

void solution(vector<lint> &v, lint x, lint n)
{
    vector<pair<lint,lint>> p;

    for(lint i=0;i<v.size();i++){
        p.push_back(make_pair(v[i],1));
    }

    for(lint i=0;i<p.size();i++){
        if(p[i].first % x ==0){
            p.push_back(make_pair((lint)(p[i].first/x), x* p[i].second));
        }
        else{
            break;
        }
    }
    

    lint sum = 0;
    for(pair<lint,lint> x: p){
        sum+=x.first *x.second;
    }
    

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout.precision(10);
    // cout << fixed;

    lint t;

    cin >> t;
    lint n, ele, x;
    while (t--)
    {
        vector<lint> v; //for inputing vector
        cin >> n >> x;
        for (lint i = 0; i < n; i++)
        {
            cin >> ele;
            v.push_back(ele);
        }

        solution(v, x, n);
    }

    return 0;
}


