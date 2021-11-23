//题目Acwing154滑动窗口
#include<iostream>

using namespace std;

const int N = 100010;

int n;//数组长度
int k;//窗口长度
int a[N], q[N];//a[N]存放数据 队列q[N]存数组下标

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    //求最小值, 形成单调递增队列
    //因为一个元素(a)一定比后面的元素(b)先出窗口, 所以如果 a > b的话, 那么在b入窗口之后, 绝不可能取到a
    //所以维护一个严格单调递增的队列即可
    for(int i = 0; i < n; i ++)//i为当前枚举的右端点
    {
        //判断队头是否已经滑出窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh ++;//hh为队头, tt为队尾, i - k + 1 为窗口左下标, i为右下标
        //如果q[]不为空, 如果队头下标 > q[hh],则q[hh]已经出队

        while(hh <= tt && a[q[tt]] >= a[i]) tt --;//如果队尾元素比新进队的元素大, 则队尾元素出队
    //因为一个元素(a)一定比后面的元素(b)先出窗口, 所以如果 a > b的话, 那么在b入窗口之后, 绝不可能取到a
        
        q[ ++ tt] = i;//新的队尾

        if(i >= k - 1) printf("%d ", a[q[hh]]);//窗口已完全进入队列
        
    }
    puts("");

    hh = 0, tt = -1;
    //求最大值, 形成单调递减队列
    //同上, 大小值相反即可
    for(int i = 0; i < n; i ++)
    {
        //判断队头是否已经滑出窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh ++;

        while(hh <= tt && a[q[tt]] <= a[i]) tt --;

        q[ ++ tt] = i;

        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    puts("");

    return 0;
}

//队列尾进头出