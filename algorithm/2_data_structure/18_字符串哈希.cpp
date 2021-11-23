//题目acwing841

// 把字符串看成p进制的数, 然后mod Q
// 数字范围为[0, Q -1], 但是原数字映射成0会有很多冲突, 所以不能一般不能映射成0
// p一般取131或13331, Q取 2^64, 不容易冲突
// 用unsigned long long 来存储数据, 这样溢出就相当于取模

#include<iostream>

using namespace std;

typedef unsigned long long ull;

const int N = 100010, P = 131;

int n, m;
char str[N];
ull h[N], p[N];//h[i]表示前i个字母的hash值, ull不需要对2^64取模, 溢出 == 取模

ull get(int l, int r)//求第l个字母到第r个字母的hash值
{
    return h[r] - h[l - 1] * p[r - l + 1];
    // 区间和公式的理解: ABCDE 与 ABC 的前三个字符值是一样，只差两位，
    // 乘上 P^2 把 ABC 变为 ABC00，再用 ABCDE - ABC00 得到 DE 的哈希值。

}

int main()
{
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        p[i] = p[i - 1] * P; //p[i] 的值为 p^i

        h[i] = h[i - 1] * P + str[i];
        // h[i] 为前i个数的哈希值
    }

    while(m -- )
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if(get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}