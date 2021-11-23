//acwing860
//二分图:
//把一个图的顶点划分为两个不相交子集 ，使得每一条边都分别连接两个集合中的顶点。如果存在这样的划分，则此图为一个二分图
//充要条件: 当且仅当图中不含奇数环
//染色法: 用两种颜色交换染色遍历图, 如果有矛盾则不是二分图
//时间复杂度o(m + n)
#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[N], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!color[j])//如果该点没染过色, 则给他染色
        {
            if(!dfs(j, 3 - c)) return false; //3 - c 意思是, 这一步c是1的话, 下一步c是2, 否则相反
        }
        else if(color[j] == c) return false;//下一个点与当前点颜色相同, 矛盾, 无法构成二分图
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;
    for(int i = 1; i <= n; i ++)//从一号点开始遍历, 0要用于判断该点是否染色
        if(!color[i])
        {
            if(!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }

    if(flag) puts("Yes");
    else puts("No");

    return 0;

}