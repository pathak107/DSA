#include <iostream>
#include <set>

using namespace std;


void findDiffArea(int x[], int n)
{
    set<float, greater<float>> areaSet;
    float area;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        { //j>i
            area = (x[j] - x[i]) / 2.0;
            if (areaSet.find(area) == areaSet.end())
            {
                areaSet.insert(area);
            }
        }
    }
    cout<<areaSet.size()<<endl;
}

int main()
{
    int t, n, x[50];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> x[j];
        }

        findDiffArea(x, n);
    }
    return 0;
}