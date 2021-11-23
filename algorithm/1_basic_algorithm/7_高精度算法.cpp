//对于位数很长的正整数加减,用数组把数字的每一位存下来(低位在前),再从个位开始运算

//加法模板

#include<iostream>
#include<vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if(A.size() < B.size()) return add(B, A);

    vector<int> C;

    int t = 0;//进位变量
    for(int i = 0; i < A.size(); i ++)
    {
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if(t) C.push_back(t);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    vector<int> C = add(A, B);

    for(int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    puts("");

    return 0;
}

//加法











//减法模板

#include<iostream>
#include<vector>

using namespace std;
//A >= B 则返回true;否则返回false
bool cmp(vector<int> &A, vector<int> &B)
{
    if(A.size() != B.size()) return A.size() > B.size();

    for(int i = A.size() - 1; i >= 0; i --) 
        if(A[i] != B[i])
            return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)//A较大, B较小
{
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i ++) {
        t = A[i] - t;//是否被借位
        if(i < B.size()) t -= B[i];//进行减操作, 直至B减完
        C.push_back( (t + 10) % 10);//结果进栈
        if(t < 0) t = 1;//t<0则需要借位
        else t = 0;
    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();//去掉前导零

    return C;

}
int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');//低位在前存进数组
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    vector<int> C;

    if(cmp(A, B)) C = sub(A, B);//小数在后
    else C = sub(B, A), cout << '-';

    for(int i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl;

    return 0;
}

//减法












//乘法模板

#include<iostream>
#include<vector>

using namespace std;

vector<int> mul(vector<int>&A, int b)//A为大数, b为小数
{
    vector<int> C;

    int t = 0;
    for(int i = 0; i < A.size() || t; i ++)//i < A.size()遍历A, 每个数都*b, t存在表示乘完之后剩下的数还要补到之后的位上
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    vector<int> C = mul(A, b);

    if(b == 0) puts("0");
    else
    {
        for(int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
        puts("");
    }

    return 0;
}

//乘法

























//除法模板

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//A / b, 商是C, 余数是r
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0; i --) //从高位开始除
    {
        r = r * 10 + A[i];//模拟手算过程
        C.push_back(r / b);//b为除数, 结果入栈
        r %= b;
    }

    reverse(C.begin(), C.end());//逆序从C.begin()到C.end()之间的元素, 变为逆向存储
    while(C.size() > 1 && C.back() == 0) C.pop_back();//去掉前导零

    return C;
}

int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');//把数字一位位的输入

    int r;//余数
    vector<int> C = div(A, b, r);

    for(int i = C.size() - 1; i >= 0; i --) cout << C[i];//把商一位位输出
    cout << endl << r << endl;//输出余数

    return 0;
}

//除法