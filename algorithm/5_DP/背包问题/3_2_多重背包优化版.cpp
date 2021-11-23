//acwing 5
//二进制优化
//将原来s[i]个物品分组为, 1, 2, 4, ..., 2^k, c 个, 这些数刚好能够凑出1~s[i]
//然后再当成01背包计算
//时间复杂度从 O(N*V*S) 变为O(N*V*logS)

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 25000, M = 2010;//此方法物品最大1000*log 2000, 所以N开25000

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;

    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)//每次打包K个物品, 一直循环到不够打包
        {
            cnt ++;
            v[cnt] = a * k;//k个物品打包到一起
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0)//s个物品没有恰好用完有剩下的, 在打包一次
        {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;//总数变为cnt个物品, 转化为01背包问题

    for(int i = 1; i <= n; i ++)
        for(int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}