
#include <stdio.h>

int ReversedCount(int A[],int n){
    int Sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (A[i]>A[j])
            {
                Sum += 1;
            }
        }
    }
    return Sum;
}
int main(int argc, char const *argv[])
{
    int n;
    int a[100001];
    scanf(" %d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    int cnt=ReversedCount(a,n);
    printf("%d",cnt);

    return 0;
}

