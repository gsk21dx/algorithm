//acwing861二分图的最大匹配
//抢女朋友算法
//时间复杂度o(mn), 实际上远小于
#include<iostream>
#include<cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))//如果这个妹子还没有男朋友或者可以为她现有的男朋友找到下家, 则当前男生可以以这个妹子为女友
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while(m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for(int i = 1; i <= n1; i ++)
    {
        memset(st, false, sizeof st);
        if(find(i)) res ++;
    }

    printf("%d\n", res);

    return 0;
}