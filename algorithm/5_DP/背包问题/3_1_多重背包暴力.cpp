#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i ++) //三重循环暴力
        for(int j = 0; j <= m; j ++)
            for(int k = 0; k <= s[i] && k * v[i] <= j; k ++)////枚举第i个物品选1~K个的情况
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);

    cout << f[n][m] << endl;
    
    return 0;
}