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
        //if numOf1s is odd then it cannot be divided into 2 sets
        //if numOf2s is odd then it can be divided into 2 sets only if numOf1s > 0
        //ex 2 2 2 1 1 1 1  then (2,,1,2) (2,1,1,1)
        //ex 2 2 2 1 odd no. of 1 NO
        //ex 2 2 2 1 1 then (2,2) (2,1,1)
        //basically when numOf1s is even and numOf2s is odd then 2 2 2 1 1 1 1 => 2 | 2 2 1 1 1 1 (makes 2 also even no it can be divided into 2 sets)
        //for the remaining 2 if you add into 1 set and take 1 out of it to add into anther 
        // 2 (2,1,1) (2,1,1) => (2,2) (2,1,1,1)
        // (x) (x) => (x -1 +2) (x +1) => (x+1) (x+1) still equal
        if(numOf1s%2==0 && numOf1s>0){
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