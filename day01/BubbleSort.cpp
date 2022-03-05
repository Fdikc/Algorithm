#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
int main(void)
{
    time_t begin, end;
    double duration;
   
    int i, j, t, n;
    int a[100001];
    scanf("%d", &n);
    getchar();
    
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);     
    begin = clock();
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - 1 - i; j++) 
        {
            if (a[j] > a[j + 1])
            { //相邻两个数比较
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    end = clock();
    duration = double(end - begin) / CLOCKS_PER_SEC;
    cout << "runtime: " << duration << endl;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
