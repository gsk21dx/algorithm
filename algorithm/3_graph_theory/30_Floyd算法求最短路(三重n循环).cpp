//acwing854
//三重循环， k在最外层，f（k，i，j）将k作为中间点，比较 i到j 和 i到k到j 的距离，取最小值
//可以存在负权边，但不能存在负权回路
//时间复杂度为O(n^3)
//基于动态规划的算法,状态转移方程：dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];//稠密图用邻接表存

void floyd()
{
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &Q);

    for(int i = 1; i <= n; i ++)//初始化
        for(int j = 1; j <= n; j ++)
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;

    while(m --)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        d[a][b] = min(d[a][b], w);
        //注意保存最小的边
    }

    floyd();

    while(Q --)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        if(d[a][b] > INF / 2) puts("impossible");
        //因为存在负权边 所以INF这个值可能会因为负值被更新 但值依然远大于INF/2
        else printf("%d\n",dist[x][y]);
        else printf("%d\n", d[a][b]);
    }

    return 0;
}
