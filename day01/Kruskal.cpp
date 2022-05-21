#include <cstdio>
#include <algorithm>
#define MAX 100005
#define enter putchar('\n')
using namespace std;
typedef long long ll;
struct edge
{
    int u, v, w;
} a[MAX * 6];
int n, m, t, f[MAX * 3];
ll ans;
bool cmp(edge xx, edge yy)
{
    return xx.w < yy.w;
}
void Init()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    return;
}
int father(int x)
{
    if (x == f[x])
        return x;
    return f[x] = father(f[x]);
}
void Kruskal()
{
    sort(a, a + m, cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++)
    {
        int f1 = father(a[i].u), f2 = father(a[i].v);
        if (f1 != f2)
        {
            ans += (ll)a[i].w;
            f[f1] = f2;
            t++;
        }
        if (t == n - 1)
            break;
    }
    printf("%lld\n", ans);
    return;
}
int main()
{
    Init();
    Kruskal();
    return 0;
}