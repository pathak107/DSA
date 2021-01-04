#include <iostream>
using namespace std;

void divideAmongTwo(int x[], int n)
{
    int numOf2s = 0;
    int numOf1s = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            numOf1s += 1;
        }
        else
        {
            numOf2s += 1;
        }
    }

    if (numOf1s % 2 == 0 && numOf2s % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        if(numOf1s==2*numOf2s){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
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

        divideAmongTwo(x, n);
    }
    return 0;
}