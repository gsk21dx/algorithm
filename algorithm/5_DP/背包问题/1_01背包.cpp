//acwing 2 01背包

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m;//物品个数 背包容量
int v[N];//物品体积
int w[N];//物品价值
int f[N][N];//状态, f[i][j]表示选取i件物品, 总重量不超过j的最大价值是多少

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];


    //枚举物品个数i和装的重量j
    //当枚举到i时, 有两种选择, A:i不放进背包, 即f[i][j] = f[i- 1][j]; B:i放进背包, 此时要判断是否放得下
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            //B情况中, 如果此时枚举的j可放入第i个物品, 则判断不放i和放i的价值谁更大
            /*f[i - 1][j - v[i]] + w[i] 中 f[i - 1][j - v[i]]表示给第i个物品腾出空间之后对应的状态,
             然后再加上w[i]之后与f[i][j]比较*/
        }

    cout << f[n][m] << endl;



    //一维优化版
/*  for(int i = 1; i <= n; i ++)
        for(int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
*/
    return 0;
}

//在一维优化版中, 一维数组只存各个重量下的最优解, 每个for(i : 个数)会更新数组,
//即 第一遍更新为i = 1情况下各个重量的最优解, 第二遍更新为i = 2情况下的最优解, 以此类推
//因为在二维版中f[i - 1][j - v[i]] + w[i] 中用到了 f[i - 1][j - v[i]] , 这个状态在之前就被覆盖, 一维数组并没有保留下来
//所以把j循环改为从大到小, 当循环到f[i][j]时, f[i - 1][j - v[i]]还没有被覆盖, 