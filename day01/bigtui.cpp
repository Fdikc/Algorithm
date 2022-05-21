#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, m, u, v, t, cou;
vector<int> edge[20001];
bool book[20001];
void dfs(int k)
{
    if (t == n)
    {
        cou++;
        return;
    }
    for (int i = 0; i < edge[k].size(); i++)
    {
        if (book[edge[k][i]] == false)
        {
            t++;
            book[edge[k][i]] = true;
            dfs(edge[k][i]);
        }
    }
    return;
}
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
void out(int x)
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
int main()
{
    n = read(), m = read();
    for (int i = 0; i < m; i++)
    {
        u = read(), v = read();
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(book, 0, sizeof(book));
        t = 1;
        book[i] = true;
        dfs(i);
    }
    out(cou);
    return 0;
}