//题目acwing 839

//堆的几种操作如何实现
//1. 插入一个数             heap[++ hsize] = x; up(hsize);
//2. 求集合当中的最小值     heap[1];
//3. 删除最小值             heap[1] = heap[hsize]; hsize --; down(1);
//4. 删除任意一个元素       heap[k] = heap[hsize]; hsize --; down(k); up(k);
//5. 修改任意一个元素       heap[k] = x;

#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010;

int h[N];//h[N]存储堆
int ph[N];//ph[k]从下标映射到堆, 存储第k个插入的数的下标
int hp[N];//hp[i]从堆映射到下标, 存储堆中的i点是第几个插入的点
int hsize;//hsize当前堆的元素个数

//在堆中下标为k的数, ph[k] == j, 表示第k个插入的数是j, hp[j] = k, 表示下标为j的点是第k个插入的数

//要交换两个数时要做的操作
void heap_swap(int a, int b)//a, b为要交换的两个数的堆中下标
{
    swap(ph[hp[a]], ph[hp[b]]);//交换 "是第几个插入的数"
    swap(hp[a], hp[b]);//交换 "在堆中的位置"
    swap(h[a], h[b]);//交换 值
}

void down(int u)//传入的是根节点
{
    int t = u;

    if(u * 2 <= hsize && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= hsize && h[u * 2 + 1] < h[t]) t = u * 2 + 1;//使t为三个数中的最小值

    if(u != t)//u != t时, 则根节点不是最小值, 需要交换使得根节点为最小值
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while(u / 2 && h[u / 2] > h[u])//如果这个结点比上面的结点小,则这个结点向上走
    {
        heap_swap(u / 2, u);
        u /= 2;
    }
}
// void up(int u)
// {
//     while (u / 2 && h[u] < h[u / 2])
//     {
//         heap_swap(u, u / 2);
//         u >>= 1;
//     }
// }
int main()
{
    int n;
    int m = 0;//第几个插入的数
    scanf("%d", &n);
    while(n --)
    {
        char op[10];
        int k, x;

        scanf("%s", op);
        if(!strcmp(op, "I"))
        {
            scanf("%d", &x);
            hsize ++;
            m ++;
            ph[m] = hsize;//记录 是第几个插入的数
            hp[hsize] = m;//记录 在堆中的位置
            h[hsize] = x;//记录 值
            up(hsize);//排一遍序
        }
        else if(!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if(!strcmp(op, "DM"))
        {
            heap_swap(1, hsize);
            hsize --;
            down(1);//排序
        }
        else if(!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, hsize);
            hsize --;
            down(k), up(k);//down和up操作只会做一种, 所以可以直接写出无需判断
        }
        else//修改第k个插入的数
        {
            scanf("%d%d", &k, &x);
            k = ph[k];//把 "第k个插入的数的堆中坐标" 赋给 k
            h[k] = x;//修改堆中元素的值
            down(k), up(k);//重新排序
        }
    }

    return 0;
}
/*
#include<bits/stdc++.h>
#define N 500010
#define NN 5010
#define NNN 510
#define INF 0x3f3f3f3f
#define pi 3.1415926535897932384626433
typedef long long ll;
const int mod=1e9+7;

using namespace std;

int a[N],cnt=0;

int main()
{
    int n;
    multiset<int> s;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string t;
        int x,y;
        cin>>t;
        if (t=="I")
        {
            cin>>x;
            s.insert(x);
            a[++cnt]=x;
        }
        if (t=="PM") cout<<*s.begin()<<endl;
        if (t=="DM") s.erase(s.find(*s.begin()));
        if (t=="D")
        {
            cin>>x;
            if (s.find(a[x])!=s.end()) s.erase(s.find(a[x]));
        }
        if (t=="C")
        {
            cin>>x>>y;
            if (s.find(a[x])!=s.end()) s.erase(s.find(a[x]));
            a[x]=y;
            s.insert(y);
        }
    }
    return 0;
}

作者：ex_jason
链接：https://www.acwing.com/solution/content/6100/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
