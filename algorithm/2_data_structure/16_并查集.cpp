//将两个集合合并
//询问两个元素是否在同一个集合当中
#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N]; //p[x]存放x点的父节点

int find(int x)//递归查找根节点 + 路径压缩优化
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i ++) p[i] = i;//刚开始每个节点都是根节点, 所以每个点的父节点都==他自己的下标(根节点定义)

    while(m --)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);

        if(op[0] == 'M') p[find(a)] = find(b);//把两棵树合并
        else//查询操作
        {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}