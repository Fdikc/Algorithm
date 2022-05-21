#include<bits/stdc++.h>
using namespace std;
/*
4 6
0 1 0 0 0 0
0 0 0 1 0 0
0 0 1 0 0 1
1 1 0 0 0 0
*/
struct node
{
    int x;
    int y;
    //int step;
    string d;
};
queue<node> q;
int n, m;
int startx=1, starty=1;
char a[100][100];
int visited[100][100]={0};
int dis[100][100]={0};

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char dir[4]={'D','L','R','U'};
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
    }
    // int endx=n, endy=m;
    //bfs
    node start, temp,cur;
    start.x=startx;
    start.y=starty;
    //start.step=0;
    start.d="";
    q.push(start);//入队

    visited[start.x][start.y] = 1;
    int flag=0;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==n&&cur.y==m)
        {
            cout << cur.d;
            flag=1;
            //cout<<cur.step<<endl;
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            temp.x=cur.x+dx[k];
            temp.y=cur.y+dy[k];
            temp.d=cur.d+dir[k];
            // temp.step=cur.step+1;
            if(temp.x<1||temp.x>n||temp.y<1||temp.y>m) continue;
            if(a[temp.x][temp.y]=='1'||visited[temp.x][temp.y])continue;
            q.push(temp);
            visited[temp.x][temp.y] = 1;
        }
    }
    if(flag==0)
    {
        cout<<-1;
    }
    return 0;
}
