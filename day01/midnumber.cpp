#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &m, &n);
        printf("%d %d\n", m, (n + 1) / 2); //数据集编号 动态中位数个数
        //用优先队列实现堆
        priority_queue<int> down;                          //大根堆 /\

        priority_queue<int, vector<int>, greater<int>> up; //小根堆\/

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            //如果下面为空 或者x比下面堆顶小 插入下面
            if (down.empty() || x <= down.top())
                down.push(x);
            //否则 插入上面
            else
                up.push(x);
            //如果下面太多 cnt[下]-cnt[上]>=2 把下面堆顶挪上去
            if (down.size() > up.size() + 1)
                up.push(down.top()), down.pop();
            //如果上面太多 cnt[上]-cnt[下]>0  把上面堆底挪下来
            if (up.size() > down.size())
                down.push(up.top()), up.pop();
            //始终维护cnt[下]-cnt[上]=1 || 0
            if (i % 2) //第奇数个
            {
                printf("%d ", down.top()); //打印下面堆顶
                if (++cnt % 10 == 0)
                    puts(""); //每10个换行
            }
        }
        if (cnt % 10)
            puts("");
    }
    return 0;
}