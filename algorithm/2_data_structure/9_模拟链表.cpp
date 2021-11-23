#include<iostream>

using namespace std;

const int N = 100010;

int main()
{
    //单链表
    {
        int head, e[N], ne[N], idx = 0;
        //head 为第一个元素的下标, e[head]为第一个元素, head为-1时, 链表为空
        //e[k] 第k个 插入 的数是多少
        //next[k] 第k个 插入 的数后面的数的下标

        //初始化
        idx = 0;
        head = -1;

        //插入
        {
            int a;
            int k;

            //a 插入到第k个插入的点后面, 若要插入到head结点后, 把ne[k]改为head即可
            e[idx] = a;
            ne[idx] = ne[k];
            ne[k] = idx;
            idx ++;
        }

        //删除
        {
            int k;//删除第k个插入的点

            ne[k] = ne[ne[k]];
        }

    }
    //单链表

    
    
    //双链表
    {
        int e[N], l[N], r[N], idx = 0;
        //e[k]表示第k个插入的数是多少
        //l[k]第k个插入的数的左边的数的下标
        //r[k]第k个插入的数的右边的数的下标

        //初始化
        //idx = 0作为左边界, idx = 1作为右边界, 所以idx从2开始, 所以k + 1才是第k个插入的数的下标
        //初始化即左边界的右边为有边界, 右边界的左边为左边界 
        r[0] = 1;
        l[1] = 0;
        idx = 2;

        //插入
        //在k右端插入, k = l[k]为在k左端插入, k = 0 为最左端插入, k = l[1]为最右端插入
        {
            int x;//插入点的值
            int k;//在k右端插入

            //先建点, 点的左右先指向要插入的两个点, 再把右边点的左边指向新点, 左边点的右边指向新点
            e[idx] = x;
            l[idx] = k;
            r[idx] = r[k];
            l[r[k]] = idx;
            r[k] = idx;
            idx ++;
        }


        //删除
        //要删除点的左边点的右边指向右边点, 右边点的左边指向左边点
        {
            int k;//要删除点的位置

            int a = l[k], b = r[k];
            r[a] = b;
            l[b] = a;
        }
    }
    //双链表


}