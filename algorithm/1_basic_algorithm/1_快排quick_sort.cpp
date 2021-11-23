#include<iostream>

using namespace std;

const int N = 100010;

int q[N];

void quick_sort(int q[], int l, int r)
{
    if( l >= r) return;

    int x = q[l + r >> 1]/*x的大小为分界点*/, i = l - 1, j = r + 1;//确定初始边界点
    while(i < j) {//分界点左边都是比x小的数,右边都是大的数
        do i ++ ; while( q[i] < x);
        do j -- ; while( q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);//分界点取左边界,则递归右边界点,输入q, l, i会出现边界问题
    quick_sort(q, j + 1, r);
}
//快排
//先随便找一个分界点q[l + r >> 1],然后分别递归重复这样处理两边,最后再比较排序(swap)