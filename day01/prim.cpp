#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*

5 10
1 2 3
1 3 7
1 4 9
1 5 5
2 3 6
2 4 8
2 5 4
3 4 9
3 5 7
4 5 2

15
*/
const int MAXN = 300005;
const int INF = 1e9;

struct Edge
{
    int v, dis;
    Edge(int _v, int _dis)
    {
        v = _v, dis = _dis;
    }
};

vector<Edge> G[MAXN];
int d[MAXN];
bool vis[MAXN];

long long prim(int n)
{
    fill(d, d + MAXN, INF);
    memset(vis, false, sizeof(vis));
    d[1] = 0;
    long long weightSum = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, minDis = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] < minDis)
            {
                u = j; // u
                minDis = d[j];
            }
        }
        if (u == -1)
        {
            return -1;
        }
        vis[u] = true;
        weightSum += d[u];
        for (int j = 0; j < G[u].size(); j++)
        {
            int v = G[u][j].v;
            int dis = G[u][j].dis;
            if (!vis[v] && dis < d[v])
            {
                d[v] = dis;
            }
        }
    }
    return weightSum;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    long long weightSum = prim(n);
    printf("%lld", weightSum);
    return 0;
}