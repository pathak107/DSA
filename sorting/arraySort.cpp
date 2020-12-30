#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void sortedMerge(int arr[], int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    if (i < n1)
    {
        while (i < n1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }

    if (j < n2)
    {
        while (j < n2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
}

void mergeSort(int arr[], int l, int r, int n)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid, n);
    mergeSort(arr, mid + 1, r, n);
    sortedMerge(arr, arr, mid, arr+mid, n - mid);
}

int main()
{
    int arr[]={10,8,7,6,5,4,3,2};
    int n= sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n,n);
    cout << endl;
    print(arr, n);
    return 0;
}