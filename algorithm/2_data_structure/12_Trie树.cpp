//高效的存储和查找字符串集合的数据结构

#include<iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;//下标idx为0的点,既是根节点, 又是空节点, idx为当前最长的结点
char str[N];

void insert(char str[])//p, idx为树层数, u为字母映射, son[p][u]存的是下一个字母的层数, 层数不一定是按顺序的
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';//子结点编号

        if(!son[p][u]) son[p][u] = ++ idx;//开一条新的路, 如果没开新路,idx的值也不会增

        p = son[p][u];//如果没开新路,p与之前有过的结点走相同的路; 如果开了新路, p会有一个新的值(原最大值+1, 即idx);  
    }

    cnt[p] ++;//以p结点结尾的字符串数+1
}
//插入函数中, p代表树的层数, 在开新路时, p不会从0开始, 而是从 ++ idx开始


int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;//没有这条路, 即这个字符串还没出现过
        p = son[p][u];//该字符最终停在哪个结点
    }

    return cnt[p];//返回这个结点p出现的次数
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n --)
    {
        char op[2];
        scanf("%s%s", op, str);
        if(op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}