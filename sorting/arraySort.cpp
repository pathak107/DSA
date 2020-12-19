#include<iostream>
using namespace std;

void print(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void sortedMerge(int arr[],int l,int mid,int r,int n)
{
    int n1=mid-l;
    int n2=r-mid+1;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[i];
    }
    for(int i=mid,k=0;i<=r;i++,k++){
        arr2[k]=arr[i];
    }

    print(arr1,n1);
    cout<<endl;
    print(arr2,n2);

    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;
        }else{
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    if(i<n1){
        while(i<n1){
            arr[k]=arr1[i];
            i++;
            k++;
        }
    }

    if(j<n2){
        while(j<n2){
            arr[k]=arr1[j];
            j++;
        }
    }
}


void mergeSort(int arr[],int l,int r,int n){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid,n);
        mergeSort(arr,mid+1,r,n);
        sortedMerge(arr,l,mid,r,n);
    }
}
int main(){
    int arr[]={7,8,9,5,14,34,45};
    int n=sizeof(arr)/sizeof(int);
    // mergeSort(arr,0,n-1,n);
    sortedMerge(arr,0,(n/2),n-1,n);
    cout<<endl;
    print(arr,n);
    return 0;
}