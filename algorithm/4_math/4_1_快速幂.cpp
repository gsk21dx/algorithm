//acwing875
//求a^k%p, 先预处理出a^(2^0)%p , a^(2^1)%p, a^(2^2)%p, ... , a^(2^logk) % p
//然后把 k 换成这些数中(2^0, 2^1, 2^2, ... , 2^logk) 某些数的和
//方法:把k转化为2进制, 如二进制下的101 == 十进制下 2^2 + 2^0
//时间复杂度O(logk)

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

//a^b%p
int qmi(int a, int k, int p)
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;//如果k的末尾是1, 就要乘上a^(2^i), 即 看k的二进制中那些位是1
        
        a = (ll)a * a % p;//a不断变化, 第一轮为a^(2^0), 第二轮为a^(2^1), 以此类推, 即每次平方
        k >>= 1;//每次去掉二进制k的最后一位
    }
    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);

        printf("%d\n", qmi(a, k, p));
    }

    return 0;
}
