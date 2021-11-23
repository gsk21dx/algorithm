//存在数列a1, a2, a3, ... , an;
//构造差分数组b1, b2, b3, ... , bn
//使得a数组是b数组的前缀和
//构造方法b1 = a1, b2 = a2 - a1, b3 = a3 - a2, ... 
//所以对于操作: 把a数组的l到r区间全部加上c  就等价于  对bl加上c, b(r+1)减去c
//因为bl加上c之后, al~an作为前缀和肯定会加上bl, 也就相当于其中的每个数加了c
//br - c          a(r+1)~an               减去br,                      减了c
//所以综合之后就等价于a数组的 l 到 r 区间全部加上c
//而差分数组的构造方法也等价于bi = 在i到i的区间加上a[i]
//acwing797差分

#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r  + 1] -= c;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++) insert(i, i, a[i]); //构造差分数组

    while(m --)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for(int i = 1; i <= n; i ++) b[i] += b[i - 1];//把b数组转化为自己的前缀和

    for(int i = 1; i <= n; i ++) cout << b[i] << ' ';

    return 0;
}