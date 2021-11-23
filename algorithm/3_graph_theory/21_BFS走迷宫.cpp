#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100;

typedef pair<int, int> PII;

int n, m;
int g[N][N];//存迷宫
int d[N][N];//存每一个点到起点的距离
PII q[N * N];//模拟一个队列
PII Prev[N][N];//Prev[x][y]记录到达(x, y)的上一个点,即记录路径 

int bfs()
{
    int hh = 0, tt = 0;//队头队尾
    q[0] = {0, 0};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    //往每个方向走x, y坐标分别改变的量

    while(hh <= tt)
    {
        auto t = q[hh ++];//取出队头

        for(int i = 0; i < 4; i ++)//遍历往四个方向走的情况
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            //x, y在范围内, 且g[x][y]为可以走的, 且这个点没有走过
            {
                d[x][y] = d[t.first][t.second] + 1;
                Prev[x][y] = t;//记录路径, (x, y)是从t点走来的
                q[++ tt] = {x, y};//x,y入队 
            }
        }
    }

    int x = n - 1, y = m - 1;//从终点开始输出路径
    while(x || y)
    {
        cout << x << ' ' << y << endl;
        auto t = Prev[x][y];
        x = t.first, y = t.second;
    }

    return d[n - 1][m - 1];//返回到终点的距离
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> g[i][j];

    cout << bfs() << endl;
    
    return 0;
}