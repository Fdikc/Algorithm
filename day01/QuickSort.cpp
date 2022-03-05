#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
time_t begin, end;
double duration;

void show(int A[],int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",A[i]);
    }
}

int Paritition1(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) //¿ìÅÅÄ¸º¯Êý
{
    if (low < high)
    {
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}
int main()
{
    time_t begin, end;
    double duration;
    int i, j, t, n;
    int a[100001];
    scanf(" %d", &n);
    getchar();
    for (i = 1; i <=n; i++){
        scanf("%d", &a[i]);
    }
    begin = clock();
    QuickSort(a,1,n);
    end = clock();
    duration = double(end - begin) / CLOCKS_PER_SEC;
    cout << "runtime: " << duration << endl;
    show(a,n);
    return 0;
}