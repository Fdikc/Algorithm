#include <iostream>
using namespace std;


int B[100001];
long s=0;
void Merge(int A[],int low,int mid,int high){
    int i,j,k;
    for (k = low; k <= high; k++)
    {
        B[k] = A[k];
    }
    for ( i = low,j=mid+1,k=low; i <= mid && j<=high; k++)
    {
        if (B[i]<=B[j])
        {
            A[k]=B[i++];
        }
        else{
            A[k]=B[j++];
            s+=(mid-i+1);
        }
        
    }
    while (i<=mid)
    {
        A[k++]=B[i++];
    }
    while (j<=high)
    {
        A[k++]=B[j++];
    }
    
}

void MerfeSort(int A[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        MerfeSort(A,low,mid);
        MerfeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
    return;
}
void PrintFun(int A[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",A[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int A[100001];
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    MerfeSort(A,0,n-1);
    // PrintFun(A,n);
    //printf("%d",s);
    cout << s << endl;
    return 0;
}
