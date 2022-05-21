#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
最短路 1.最短路n(1≤n ≤3000) 个顶点m(1≤m≤7000) 条边的无向图，计算源点s到终点t的最短路。
    输入格式 : 第一行 : 4个整数n,m,s,t，由空格隔开;
            随后m行，每行三个正整数x, y, c，表示边(x, y) 的长度为c。(1≤c≤109)
    输出格式 : 一个整数，表示从s到t最短路的长度。
    数据保证至少存在s到t的路。
3 3 1 3
1 2 1
2 3 1
3 1 1
*/
int main(int argc, char const *argv[])
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    ll e[n + 1][n + 1];
    memset(e, 0x3f, sizeof(e));
    for (int i = 1; i <= m; i++)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        e[x][y] = e[y][x] = c;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (e[i][j] > e[i][k] + e[k][j])
                {
                    e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
                }
            }
        }
    }
    printf("%lld\n", e[s][t]);
    
    return 0;
}


