#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5e2 + 10;
int e[maxn][maxn], n, m, k;
int inf = 0x3f3f3f3f;
int ff()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (e[i][j] > e[i][k] + e[k][j]) //每次进行松弛后它的最短路径就已经从“估计值”变成“确定值”。
                {
                    e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
                    if (e[i][i] < 0) //从一个点出发最后再回到这个顶点如果小于 0 则返回 ture
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    e[i][j] = 0;
                }
                else
                {
                    e[i][j] = inf;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b >> c;
            if (e[a][b] > c)
            {
                e[a][b] = e[b][a] = c;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            cin >> a >> b >> c;
            e[a][b] = -c; //单独记录负权边
        }
        if (!ff())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
