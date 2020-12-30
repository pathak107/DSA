#include <iostream>
#include <set>

using namespace std;

void diversify(int x[], int n)
{
    set<int, greater<int>> u;
    int i = 0;
    while (i < n)
    {
        //find index till the elements are same
        int j = i;
        while (x[j] == x[i] && j < n)
        {
            j++;
        }

        //update odd elements
        if (j != i + 1)
        {
            for (int k = i; k < j; k += 2)
            {
                x[k] += 1;
            }
        }

        i = j;
    }
    
    for(int it=0;it<n;it++){
        u.insert(x[it]);
    }
    cout<<u.size()<<endl;

}

int main()
{
    int t, n, x[100];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> x[j];
        }

        diversify(x, n);
    }
    return 0;
}