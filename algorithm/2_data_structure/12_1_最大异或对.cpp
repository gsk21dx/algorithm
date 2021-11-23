#include<iostream>
#include<algorithm>


using namespace std;

const int N = 3000010;

int n, ans;
int a[N];
int son[N][2], idx;

void insert(int n)
{
    int p = 0;
    for(int i = 30; i >= 0; i --)
    {
        int &s = son[p][(n >> i) & 1];//s 等价于 son[p][(n >> i) & 1]
        
        if(!s) s = ++ idx;//开新路
        
        p = s;
    }
}

int query(int n)
{
    int p = 0;
    int res = 0;
    for(int i = 30; i >= 0; i --)
    {
        int u = (n >> i) & 1;
        
        if(son[p][!u]) res += 1 << i, p = son[p][!u];//不同的位异或后结果肯定是1, 所以对res的贡献为 1 << i
        else res += 0 << i, p = son[p][u];
    }
    
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i], insert(a[i]);
    
    for(int i = 0; i < n; i ++)
        ans = max(ans, query(a[i]));
    
    
    cout << ans << endl;
    
    return 0;
    
}