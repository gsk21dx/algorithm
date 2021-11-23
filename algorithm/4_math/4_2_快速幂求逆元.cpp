#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int qmi(int a, int k, int p)
{
    int res = 1;
    while(k)
    {
        if(k & 1) res = (ll) res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n --)
    {
        int a, p;
        scanf("%d%d", &a, &p);

        int res = qmi(a, p - 2, p);
        if(a % p) printf("%d\n", res);
        else puts("impossible");
    }

    return 0;
}