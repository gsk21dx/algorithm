//acwing831
//时间复杂度o(m+n)

#include<iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char p[N],s[M];
int ne[N];

int main()
{
    cin >> n >> (p + 1) >> m >> (s + 1);//输入n, p[1], m, s[1]

    //求next的过程, 求p串每个i对应的最大前缀, ne[i] 等价于 p[i]之前与p[i]相同的前缀的位置
    for(int i = 2, j = 0; i <= n; i ++)//j为前缀, i为指针遍历p, i 从2开始, 因为要用到ne[1]时, 只能重新开始遍历, 即ne[1] == 0;
    {
        while(j && p[i] != p[j + 1]) j = ne[j];
        //不匹配, p[j+1] != p[i], 则从ne[j]开始重新匹配, 如果ne[j]不存在, 从j=0开始匹配

        if(p[i] == p[j + 1]) j ++;//匹配

        ne[i] = j;//求出每个值的ne[]
    }

    //kmp匹配过程
    for(int i = 1, j = 0; i <= m; i ++)//i用于遍历s串, j用于遍历p串  
    {
        while(j && s[i] != p[j + 1]) j = ne[j];//如果j存在且 出现不同字符, 则j = ne[j]再去匹配

        if(s[i] == p[j + 1]) j ++;//如果字符匹配, 则继续匹配下一个字符

        if(j == n)
        {
            //匹配成功
            printf("%d ", i - n);//输出s中出现p的起始位置
            j = ne[j];//如果有ne[], 就从ne[]的位置开始继续找, 没有就从0的位置开始找
        }
    }

    return 0;
}

