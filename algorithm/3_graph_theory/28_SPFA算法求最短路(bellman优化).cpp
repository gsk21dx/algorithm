//acwing851
//spfa算法是对bellman_ford算法的优化
//每次循环不用再遍历每条边, 而用队列来优化, 只让出边变小的点进队
//时间复杂度 一般o(m), 最坏o(mn)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];//存每个点到起点的最短距离
bool st[N];//判断点是否入队

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())//遍历队中的点的最短路
    {
        int t = q.front();//取出队头
        q.pop();

        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])//遍历每个点的出边, 更新最小值
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);//如果j点不在队列中, j点入队, 更新j的出边的最小值
                    st[j] = true;
                }
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int t = spfa();

    if(t == -1) puts("impossible");
    else printf("%d\n", t);

    return 0;
}