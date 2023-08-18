//acwing849 Dijkstra求最短路I
//Dijkstra算法:从起点开始, 依次求出每个点到起点的最短路径,
//每求出一个点的最短路, 就用这个点更新其他点的最短路
/*伪代码
int dist[n],st[n];
dist[1] = 0, st[1] = 1;
for(i:1 ~ n)
{
    t <- 没有确定最短路径的节点中距离源点最近的点;
    st[t] = 1;
    更新 dist;
}
*/
//时间复杂度o(n^2)

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];//g[i][j]存i到j的边长,稠密图一般使用邻接矩阵
int dist[N];//存每个点到起点的最短距离
bool st[N];//当前点是否已确认最短路

int dijkstra()
{
    
    memset(dist, 0x3f, sizeof dist);//所有节点距离起点的距离初始化为无穷大
    
    dist[1] = 0;//起点距离自己的距离为零
    
    //迭代n次，每次可以确定一个点到起点的最短路
    for(int i = 0; i < n; i ++)//从第一个点开始遍历
    {
        //找最短路
        int t = -1; //t存储当前访问的点
        for(int j = 1; j <= n; j ++)//遍历所有点, 用当前点最短路t 在所有点中找到一个路径最小的(找下一个点)
            if(!st[j] && (t == -1 || dist[t] > dist[j]) )//如果j点没找到最短路或当前这条路更短, 就用当前的这条路更新这个点
                t = j;

        st[t] = true;//当前点i找过了,当前点已确认为最短路

        //更新每个点的最短路
        for(int j = 1; j <= n; j ++)//每找到一个点, 要更新所有点的最短路(更新走过的点)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);//初始化图 因为是求最短路径
                                //所以每个点初始为无限大

    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);//a和b之间可能有多条边, 取最小的边
    }

    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}
