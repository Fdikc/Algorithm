#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// int max1(int &a,int &b){
//  return a>b?a:b;
// }
//数字三角形
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n+1][n+1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cin>>a[i][j];
            a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
        }
    }
    int c=*max_element(a[n],a[n]+n);
    cout<<c;
    return 0;
}
