#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m;//物品种数, 背包容积
int v[N], w[N];//物品体积, 物品价值
int f[N][N];//状态, f[i][j]表示选取i种物品, 总重量不超过j的最大价值是多少

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    //三重循环版
    for(int i = 1; i <= n; i ++)//枚举物品种数
        for(int j = 0; j <= m; j ++)//枚举每个i的重量
            for(int k = 0; k * v[i] <= j; k ++)//枚举第i个物品选1~K个的情况
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
    //在k循环中, f[i, j]等于这些项中的最大值:
    //          即f[i, j] = max(f[i-1, j], f[i-1, j - v] + w, f[i-1, j - 2v] + 2w, ...) ①
    //          而f[i, j-v] = max(         f[i-1, j - v],     f[i-1, j - 2v] + w, ...) ②
    //将②式代入①式, 则得, f[i, j] = max(f[i-1, j], f[i, j - v] + w);
    //所以f[i, j]的值与k循环无关, 可优化为二重循环版




    //二重循环版
/*  for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
*/



    cout << f[n][m] << endl;




/*
    //一维数组版
    for(int i = 1; i <= n; i ++)
        for(int j = v[i]; j <= m; j ++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

*/


    return 0;
}