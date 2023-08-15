//题目acwing840
/*目录
    1.拉链法
    2.开放寻址法
    3.stl(unordered_map)
*/
//1.拉链法（不常用）
#include<iostream>
#include<cstring>

using namespace std;

const int N = 100003;//取大于1e5的第一个质数

int h[N], e[N], ne[N], idx;//邻接表：h[]为槽, e[]为槽上的链表

void insert(int x)
{
    int k = (x % N + N) % N;//0~n-1 中对应的值, 为了避免x为负数, 要 模N加N再模N.
                            //c++中如果是负数,那他取模也是负的,加N再%N就一定是一个正数

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

    memset(h, -1, sizeof(h));//先将槽清空，用-1表示

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
//2.开放寻址法
#include <cstring>
#include <iostream>

using namespace std;

//开放寻址法一般开 数据范围的 2~3倍, 这样大概率就没有冲突了
const int N = 2e5 + 3;        //大于数据范围的第一个质数
const int null = 0x3f3f3f3f;  //规定空指针为 null 0x3f3f3f3f

int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) {
            t = 0;
        }
    }
    return t;  //如果这个位置是空的, 则返回的是他应该存储的位置
}

int n;

int main() {
    cin >> n;

    memset(h, 0x3f, sizeof h);  //规定空指针为 0x3f3f3f3f

    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            h[find(x)] = x;
        } else {
            if (h[find(x)] == null) {
                puts("No");
            } else {
                puts("Yes");
            }
        }
    }
    return 0;
}
//3.直接用unordered_map会方便的很多
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n;
int main()
{
    unordered_map<int,int> mp;
    cin >> n;
    while(n --)
    {
        string op;
        int x;
        cin >> op >> x;
        if(op == "I")
        {
            mp[x]++;
        }
        else
        {
            if(mp[x] > 0) puts("Yes");
            else puts("No");
        } 
    }
    return 0;
}



