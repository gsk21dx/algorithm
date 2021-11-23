//acwing853
//遍历所有的边, 用边来更新后面的边
//遍历k次代表从起点开始到n点, 最多经过k条边的最短距离
//时间复杂度o(nm)
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];//dist存每个点距起点的最短距离, backup存循环中上一次的数据

struct Edge
{
    int a, b, w;
}edges[M];

int bellma_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < k; i ++)//迭代k次, 代表最多经过k条边
    {
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j ++)//用上一次迭代的结果更新其他边
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if(dist[n] > 0x3f3f3f3f / 2) return -1;//由于有负权边更新, 导致dist[n]无穷大时值不一定为0x3f3f3f3f, 所以用另一个大数比较
    return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < m; i ++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int t = bellma_ford();

    if(t == -1) puts("impossible");
    else printf("%d\n", t);

    return 0;  
}