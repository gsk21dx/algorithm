//最长连续不重复子序列
//时间复杂度o(n)
#include<iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    int res = 0;
    for(int i = 0, j = 0; i < n; i ++) //初始状态i,j都指向第一个数, i,j之间的数代表子序列, j在前, i在后
    {
        s[a[i]] ++;//第i个数为a[i], 则s[a[i]] + 1
        while(s[a[i]] > 1)//如果s[a[i]] > 1,即这个数在子序列中出现了不止一次,则移动j,直至没有数重复
        {
            s[a[j]] --;//j每次移动子序列中都要减少一个数
            j ++;
        }

        res = max(res, i - j + 1);//比较每个子序列的长度,找出最长的即为答案
    }

    cout << res << endl;

    return 0;
}