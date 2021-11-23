#include<iostream>

using namespace std;

const int N = 10;

int n;
int path[N];//每一位存一个数字
bool st[N];

void dfs(int u)//从第u位开始排
{
    if(u == n)//所有数字都排列好了, 输出这种结果
    {
        for(int i = 0; i < n; i ++) printf("%d ", path[i]);
        puts("");
        return;
    }

    for(int i = 1; i <= n; i ++) 
        if(!st[i])//找到还没有用过的数
        {
            path[u] = i;//把i填到当前位置上
            st[i] = true;//表示这个数用过了
            dfs(u + 1);//处理下一位
            st[i] = false;//结束之后再次初始化st[i]
        }
}

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}