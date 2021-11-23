//找出一列数中每个数左边第一个比他小的数

//输出:第n个数是原数据中第n个数左边第一个比他小的数,
//没有则输出-1

#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;//作为栈使用

int main()
{
    cin >> n;

    for(int i = 0; i < n; i ++)//处理第i个数
    {
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt --;//当栈内元素stk[tt]比x大,则stk[tt]可以删除

        if(tt) cout << stk[tt] << ' ';//如果栈内有元素,则栈顶元素为答案
        else cout << -1 << ' ';//没有则输出-1

        stk[ ++ tt] = x;//把x放入栈顶
    }//形成一个单调递减的栈

    return 0;
}