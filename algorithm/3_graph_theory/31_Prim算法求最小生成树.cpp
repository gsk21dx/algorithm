// Acwing858
// 每次把一个点加入集合, 然后找其他每个点到集合的最小边, 循环n次, 即可把所有点加入集合
// 此时的点和最小边所组成的即为这个图的最小生成树
// 点到集合的距离:
// 遍历一个点所有连向的边, 其中连向集合的最短边即为该点到集合的距离, 如果一条到集合的边都没有, 则距离为正无穷(0x3f3f3f3f)
// 类似dijkstra算法
// 时间复杂度o(n^2), 堆优化版为o(mlogn)
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];// g[i][j] = 点i到点j的距离
int dist[N];// 点到集合的距离
bool st[N];// 点是否在集合内

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for(int i = 0; i < n; i ++)// 循环n次, 把每个点都加到集合里
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)// 遍历所有点, 找到不在集合中距离集合最小的点
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if(i && dist[t] == INF) return INF;// 图不连通, 不存在最小生成树

        if(i) res += dist[t];// 只要不是第一条边, 就把这条边的距离加到答案里面去
        //先累加, 再更新
        for(int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);// 更新这个点所连的边的最短路

        st[t] = true;
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);// 两点之间多条边只用存最小边
    }

    int t = prim();

    if(t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}