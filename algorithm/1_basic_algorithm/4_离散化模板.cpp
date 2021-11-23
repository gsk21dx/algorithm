#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> alls; //存储所有待离散化的值

//二分求出下标x对应的离散化的值
int find(int x)//找到第一个大于等于x的位置
{
        int l = 0, r = alls.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(alls[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r + 1;//映射到1,2,...n,如果不加1则从零开始映射
}

int main()
{
    int x;

    sort(alls.begin(), alls.end());//将所有值排序
    alls.erase( unique( alls.begin(), alls.end() ), alls.end() );//去掉重复元素
    //unique作用是对alls.begin()到alls.end()去重,返回尾端点,把重复的值放在尾端点之后
    //再用erase清除掉  尾端点到原尾端点的值  即重复的值

    find(x);
}

    

  