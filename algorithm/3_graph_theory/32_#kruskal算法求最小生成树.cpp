//acwing859
//稀疏图
//从小到大枚举每条边, 如果边不在集合中, 则把他加入集合
//用并查集维护
//时间复杂度(mlogm)
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge 
{
    int a, b, w;

    bool operator < (const Edge &W)const//运算符重载
    {
        return w < W.w;
    }

}edges[N];

int find(int x)//并查集
{
    if(p[x] != x) p[x] = find(x);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; i ++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);

    for(int i = 1; i <= n; i ++) p[i] = i;//并查集初始化

    int res = 0;//最小生成树里所有树边权重之和
    int cnt = 0;//当前加入多少条边
    for(int i = 0; i < m; i ++) 
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if(a != b)
        {
            p[a] = b;
            res += 2;
            cnt ++;
        }
    }

    if(cnt < n - 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}