//题目acwing840

#include<iostream>
#include<cstring>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;//h[]为槽, e[]为槽上的链表

void insert(int x)
{
    int k = (x % N + N) % N;//0~n-1 中对应的值, 为了避免x为负数, 要 模N加N再模N

    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;//把x插入到k这条链后面(链表插入)
}

bool find(int x)
{
    int k = (x % N + N) % N;//先计算索引值

    for(int i = h[k]; i != -1; i = ne[i])//然后在索引值这条链上找有没有这个数
        if(e[i] == x)
            return true;

    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof(h));

    while(n --)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if(*op == 'I') insert(x);
        else
        {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}