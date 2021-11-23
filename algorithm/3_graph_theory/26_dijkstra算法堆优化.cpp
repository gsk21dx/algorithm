//acwing题库850  
//堆优化的dijkstra算法
//时间复杂度o(mlogn)

#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;//最短距离, 节点编号

const int N = 200010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//邻接表存图
int dist[N];//存每个点到起点的最短距离
bool st[N];//当前点是否已确认最短路

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;//创建一个小根堆
    heap.push({0, 1});//初始化第一个点

    while(heap.size())//队列不空
    {
        auto t = heap.top();//取出堆顶元素
        heap.pop();

        int ver = t.second;//ver为节点编号

        if (st[ver]) continue;//如果这个点有最短路了, 直接找下一个点去
        st[ver] = true;//如果没有, 标记一下, 然后开始找

        for (int i = h[ver]; i != -1; i = ne[i])//遍历这个点的所有出点编号
        {
            int j = e[i];//取出 出点 的编号
            if (dist[j] > dist[ver] + w[i])//比较 *起点直接到j点距离* 和 *起点到ver再到j点的距离* 大小, 然后更新取小值
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});//更新之后, 入队
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = dijkstra();

    cout << t << endl;

    return 0;
}