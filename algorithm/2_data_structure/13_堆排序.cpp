//题目acwing838

#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N];//存储堆
int hsize;//堆中元素个数

void down(int u)//传入的是根节点下标
{
    int t = u;

    if(u * 2 <= hsize && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= hsize && h[u * 2 + 1] < h[t]) t = u * 2 + 1;//使t为三个数中的最小值

    if(u != t)//u != t时, 则根节点不是最小值, 需要交换使得根节点为最小值
    {
        swap(h[u], h[t]);
        down(t);//继续排序下层交换后的堆
    }
}

void up(int u)
{
    while(u / 2 && h[u / 2] > h[u])//如果这个结点比上面的结点小,则这个结点向上走
    {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    hsize = n;

    for(int i = n / 2; i; i --) down(i);//从倒数第二层开始给堆排序

    while(m --)
    {
        printf("%d ", h[1]);

        h[1] = h[hsize];//删除最小的根节点 
        hsize --;
        down(1);

    }

    return 0;
}

//结点x的左儿子 == 2x
//结点x的右儿子 == 2x + 1
//down函数,结点向下走(大数向下走)
//up函数, 结点向上走 (小数向上走)

//要删除堆顶元素, 应将其和堆底元素互换, 再删除交换之后的堆底元素, 再重新排序