//时间复杂度O(n)
//n为要求的最大质数
//需要存下从2到要求数的所有质数
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)//找出1到n所有的质数 时间复杂度O(n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n / i; j ++)//用已有的质数来筛
        {
            //筛掉primes[j] * i, 如果是i是质数, 筛完
            //如果不是质数, 则一定会被后面的质数筛掉, 所以筛到能整除i的质数即可break
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break; // primes[j]一定是i的最小质因子
        }
    }
}

void get_prime(int n)//埃氏筛法, 只筛掉质数的倍数, 时间复杂度约为O(n*log(log n))
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])
        {
            primes[cnt ++] = n;
            for(int j = i + 1; j <= n; j += i) st[j] = true;
        }
    }
} 

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}