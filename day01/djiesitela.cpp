#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int u[7005], v[7005], w[7005];
long long dis[3005];
const long long inf = 0x7f;
int read()
{
    int f = 1, res = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res * f;
}
void out(long long x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        out(x / 10);
    putchar(x % 10 + '0');
    return;
}
int main(void)
{
    int n, m, t, s;
    n = read(), m = read(), s = read(), t = read();
    for (int i = 0; i < m; i++)
        u[i] = read(), v[i] = read(), w[i] = read();
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        bool f = false;
        for (int j = 0; j < m; j++)
        {
            if (dis[v[j]] > dis[u[j]] + w[j])
            {
                dis[v[j]] = dis[u[j]] + w[j];
                f = true;
            }
            if (dis[u[j]] > dis[v[j]] + w[j])
            {
                dis[u[j]] = dis[v[j]] + w[j];
                f = true;
            }
        }
        if (!f)
            break;
    }
    out(dis[t]);
    return 0;
}