#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
time_t begin, end;
double duration;

void InsertSort(int A[],int n){

    int j;
    for (int i =2; i <=n; i++)
    {
        if (A[i]<A[i-1])
        {
            A[0]=A[i];
            for (j = i-1; A[0] <A[j] ; --j)
            {
                A[j+1]=A[j];
            }
            A[j+1]=A[0];
        }
        
    }
    
}

void show(int A[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
}
int main(int argc, char const *argv[])
{
    time_t begin, end;
    double duration;
    int i, j, t, n;
    int a[100001];
    scanf(" %d", &n);
    getchar();
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    begin = clock();
    //
    InsertSort(a,n);
    end = clock();
    duration = double(end - begin) / CLOCKS_PER_SEC;
    cout << "runtime: " << duration << endl;
    show(a, n);
    return 0;
}
