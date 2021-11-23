//acwing题库843
#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];//row[]只有第二种搜索方法用到
//   行      列    正对角线   反对角线

void dfs(int u)//第一种搜索方法, 按行枚举(优化做法)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return;
    }

    for(int i = 0; i < n; i ++) 
        if(!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
}

void dfs_(int x, int y, int s)//第二种搜索方法, x, y为坐标, s为当前皇后个数
{
    if(y == n) y = 0, x ++;//如果y==n, 说明这一行已经枚举完, 则x++

    if(x == n)//如果行数也枚举完了, 就判断皇后有没有放完
    {
        if(s == n)//如果皇后都放了. 则输出这种结果
        {
            for(int i = 0; i < n; i ++) puts(g[i]);//每次输出一行
            puts("");
        }
        return;
    }

    //每个格子都有放和不放两种可能, 都枚举一遍

    //不放皇后, 直接下一个
    dfs_(x, y + 1, s);

    //放皇后
    if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs_(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}