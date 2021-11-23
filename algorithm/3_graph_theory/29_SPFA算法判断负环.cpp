// acwing852
// 为什么可以用spfa求负环
// 因为在找最短路的过程中如果有负环, 每次找距当前点最小的边, 就一定会走到负环上
// 再用当前边数与点数的比较来判断是否存在环(边数>=点数则有环, 抽屉原理, 且一定是负环, 因为是找最短路)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];//dist存每个点到起点的最短距离, cnt存的是起点到达该点有几条边
bool st[N];//判断点是否入队

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
    queue<int> q;

    for(int i = 1; i <= n; i ++)//将所有点入队, 因为负环不一定从一号点开始
    {
        st[i] = true;
        q.push(i);
    }

    while(q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])//遍历每个点的出边
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])// 进这个if的*环* 只有*负环* (证明一)
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if(cnt[j] >= n) return true;// 判断是否成环
                //如果没有环, cnt[n]应该小于n(抽屉原理)
                //所以 如果有cnt[j] >= n,则说明有环
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}


int main()
{
    scanf("%d%d", &n, &m);// n个点, m条边

    memset(h, -1, sizeof h);

    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if(spfa()) puts("Yes");
    else puts("No");

    return 0;
}

// 证明一:
// dist[j] > dist[t] + w[i]
// 如果当前点形成环了, 那么一定是负环
// 因为如果成环, 则j是t之前走过的边, 但是dist[t] + w[i]反而小于dist[j]
// 所以这必是一个负环