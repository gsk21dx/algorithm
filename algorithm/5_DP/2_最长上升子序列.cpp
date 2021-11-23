//acwing895
//线性dp

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];//记录到第i个数最长的子序列的长度
int g[N];//记录转移量

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;//默认只有a[i]一个数
        g[i] = 0;
        for(int j = 1; j < i; j ++)//在前面找小于自己的数
            if(a[j] < a[i])
                if(f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
    }

    int res = 1;
    for(int i = 1; i <= n; i ++)
        if(f[res] < f[i])
            res = i;

    printf("%d\n", f[res]);

    for(int i = 0, len = f[res]; i < len; i ++)//逆序输出, 若要顺序输出要先存下来
    {
        printf("%d ", a[res]);
        res = g[res];
    }

    return 0;
}
