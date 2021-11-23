//acwing802区间和
//假定有一个无限长的数轴,数轴上每个坐标的数都是0
//现在我们首先进行n次操作,每次操作将某一位置x上的数加c
//接下来进行m次询问,每个询问包含两个整数l和r,你需要求出在区间[l,r]之间的所有数的和
//输入格式
//第一行包含两个整数n和m
//接下来n行,每行包含两个整数x和c
//在接下来m行,每行包含两个整数l和r
//-10^9 <= x <= 10^9
//1 <= n,m <= 10^5
//-10^9 <= l <= r <= 10^9
//-10000 <= c <= 10000

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;//add操作:下标, 操作数   query操作:左端点, 右端点

const int N = 300010;//需要n + n*(l + r的个数) = 3 * n空间

int n,m;
int a[N], s[N];//a离散化之后存值, s前缀和
//离散化之前数轴无限长, 但操作有限次, 所以操作离散化之后把值存在a里

vector<int> alls;//离散化
vector<PII> add, query;//添加操作, 查询操作

int find(int x)//找到大于等于x这个下标在alls里的下标
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)//读插入操作
    {
        int x, c;
        cin >> x >> c;
        add.push_back( { x, c});//存储操作

        alls.push_back(x);//存要用到的下标
    }

    for(int i = 0; i < m; i ++)//读查询操作
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

//离散化模板

    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto item : add)//添加操作
    {
        int x = find(item.first);//找到等于item.first这个下标离散化之后的下标
        a[x] += item.second;//在离散化之后的下标上加值
    }

    //预处理前缀和
    for(int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i];

    //处理询问
    for(auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}