//acwing282
//区间dp

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 310;

int n;
int s[N];
int f[N][N];//所有将第i堆石子到第j堆石子合并成一堆石子的合并方式的代价最小值

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &s[i]), s[i] += s[i - 1];//预处理前缀和

    for(int len = 2; len <= n; len ++)//len为区间大小, 区间为1时, 无需合并, 从2开始枚举
        for(int i = 1; i + len - 1 <= n; i ++)//i为区间起始点
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8;
            for(int k = l; k < r; k ++)//枚举分界点.
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                //循环找出哪个作为分界点代价最小
        }

    printf("%d\n", f[1][n]);

    return 0;
}