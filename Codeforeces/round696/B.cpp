#include <bits/stdc++.h>
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

bool check(int num, int d)
{
    int divIndex = 0;
    vector<int> divs;
    divs.push_back(1);
    for (int i = 2; i <= num; i++)
    {
        if (divs.size() == 4)
        {
            return true;
        }
        if (num % i == 0)
        {
            if (i - divs[divIndex] >= d)
            {
                divs.push_back(i);
                divIndex++;
            }
            else
            {
                return false;
            }
        }
    }

    if (divs.size() == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solution(int d)
{
    int start = 6;
    while (!check(start, d))
    {
        start++;
    }
    cout << start << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;

    cin >> t;

    while (t--)
    {
        int d;
        cin >> d;

        solution(d);
    }

    return 0;
}