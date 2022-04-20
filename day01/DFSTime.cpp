#include <iostream>
using namespace std;
#define M 50

bool visited[M];
int dis[M]; //开始时间
int fin[M]; //结束时间
int sum = 0;
typedef struct Node
{
    int id;
    struct Node *next;
} Node;
typedef struct Vnode
{
    int vex;
    int m;
    Node *firstarc;
} Vnode, AdjList[M];
typedef struct
{
    AdjList vertices;
    int vexnum;
} ALGraph;

void CreateALGraph(ALGraph &G)
{
    int num;
    Node *p, *q;
    int n;
    scanf("%d", &G.vexnum);
    for (int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].firstarc = NULL;
    }
    for (int i = 0; i < G.vexnum; i++)
    {

        scanf("%d%d", &G.vertices[i].vex, &G.vertices[i].m);
        q = G.vertices[i].firstarc;
        for (int j = 0; j < G.vertices[i].m; j++)
        {
            if (j == 0)
            {
                p = (Node *)malloc(sizeof(Node));
                scanf("%d", &num);
                p->id = num;
                p->next = G.vertices[i].firstarc;
                G.vertices[i].firstarc = p;
                q = p;
            }
            else
            {
                p = (Node *)malloc(sizeof(Node));
                scanf("%d", &num);
                p->id = num;
                p->next = q->next;
                q->next = p;
                q = p;
            }
        }
    }
}
void DFS(ALGraph G, int v)
{
    Node *p;
    visited[v] = true;
    sum += 1;
    dis[v] = sum;
    for (p = G.vertices[v].firstarc; p != NULL; p = p->next)
    {
        if (visited[p->id] != 1)
        {
            DFS(G, p->id);
        }
    }
    sum += 1;
    fin[v] = sum;
}

void DFSTraverse(ALGraph G)
{

    for (int v = 0; v < G.vexnum; v++)
    {
        visited[v] = 0;
    }
    for (int v = 0; v < G.vexnum; v++)
    {
        if (visited[v] == 0)
        {
            DFS(G, v);
        }
    }
}

int main(int argc, char const *argv[])
{
    ALGraph G;
    CreateALGraph(G);
    DFSTraverse(G);
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << i << " " << dis[i] << " " << fin[i] << endl;
    }
}
