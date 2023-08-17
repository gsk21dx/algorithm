//acwing848有向图的拓扑序列
//拓扑序：对于每条边a->b, 在序列中a都在b前面。满足这样的条件的顶点序列称为一个拓扑序。
//即 该图 为 有向无环图(拓扑图)

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//d[]存储每个点的入度

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort()// 判断是否有拓扑序列, 如果有, 队列q中存储的就是其中一种拓扑序列
{
    int hh = 0, tt = -1;

    for(int i = 1; i <= n;  i ++)// 入度为零的点作为起点, 入队
        if(!d[i])
            q[++ tt] = i;

    while(hh <= tt)
{
        int t = q[hh ++];

        for(int i = h[t]; i != -1; i = ne[i])// 当前点被拿走之后, 剩下的点中入度为零的点又可以作为起点, 入队
        {
            int j = e[i];
            d[j] --;
            if(d[j] == 0) q[++ tt] = j;
        }
    }

    return tt == n - 1;//判断是否图中每一个点都满足拓扑序, 如果满足, 队列中应该有所有的点
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for(int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;//b这个点的入度加一
    }

    if(topsort() )
    {
        for(int i = 0; i < n; i ++) printf("%d ", q[i]);//对模拟队列的理解：出对入队只是下标发生的，而存入的数据没有删去
        puts("");
    }
    else puts("-1");

    return 0;
}
