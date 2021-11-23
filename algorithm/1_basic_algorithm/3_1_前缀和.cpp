//前缀和:求第l个数到第r个数的和
//可用公式s[r] - s[l - 1]来求
//数组a[]用于存储数据, 数组s[i]表示前i个数之和

#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main()
{
    scanf("%d%d", &n, &m);//n个数据,m次询问
    for(int i = 1; i <= n; i --) scanf("%d", &a[i]);

    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];

    while(m --) {

        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - r]);
    }

    return 0;
}