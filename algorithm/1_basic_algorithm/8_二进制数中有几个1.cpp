//第一行给出一个数n
//接下来n行每行给出一个十进制整数,输出这个数在二进制下有几个1

#include<iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;

        int res = 0;
        while(x) x -= lowbit(x), res ++;

        cout << res << ' ';
    }

    cout << endl;

    return 0;
}