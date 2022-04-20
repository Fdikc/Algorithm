#include <bits/stdc++.h>
using namespace std;
/*
图的基本概念——连通分支数
*/

int n, m;
vector<vector<int>> G;
vector<bool> color;
void dfs(int k)
{
    if (color[k] == true)
        return;
    color[k] = true;
    for (int i : G[k])
        dfs(i);

    // for (int i = 0; i < G[k].size(); i++)
    // {
    //     dfs(G[k][i]);
    // }
}

void CreateGraph(){
    G.clear();
    G.resize(n);
    color.clear();
    color.resize(n,false);
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    CreateGraph();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == false)
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}
