//acwing题库847图中点的层次
/*目录
    1.stl+bfs
    2.模拟队列+bfs
*/
//1.STL+bfs
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N =1e5+10;

int h[N],ne[N],e[N],idx;//邻接表数据结构
int d[N];
int st[N];//标记点是否走到过；
int n,m;

void add(int a,int b) //邻接表存储图 
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
 } 

int bfs(){
    memset(d,-1,sizeof d);//初始化距离 

    queue<int> q;
    d[1] = 0;//从1号节点开始，距离为0； 
    q.push(1);//1号节点进入队列 
    while (q.size()) //队列非空 一直搜索 
    {
        int t =q.front(); //对头出列，找该能到的点 
        q.pop();

        for (int i = h[t];i != -1; i = ne[i])//遍历所有t节点能到的点，i为节点索引 
        {
            int j = e[i];//通过索引i到t能到的节点编号 
            if (d[j] == -1)//如果没有遍历过 
            {
                d[j] = d[t] + 1;//距离为t号节点的距离+1 
                q.push(j);//节点入队 

            }
        }
    }
    return d[n];


} 
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);//初始化，所有节点没有后继，后继都是-1

    for(int i=0;i<m;i++)//读入所有边
    {
        int a,b;
        scanf("%d%d", &a, &b);
        add(a,b);
     } 
    cout<<bfs()<<endl;
    return 0;
}
//2.队列模拟栈
int bfs()
{
    int hh=0,tt=0;

    q[0]=1; //0号节点是编号为1的节点

    memset(d,-1,sizeof d);

    d[1]=0; //存储每个节点离起点的距离

    //当我们的队列不为空时
    while(hh<=tt)
    {
        //取出队列头部节点
        int t=q[hh++];

        //遍历t节点的每一个邻边
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            //如果j没有被扩展过
            if(d[j]==-1)
            {
                d[j]=d[t]+1; //d[j]存储j节点离起点的距离，并标记为访问过
                q[++tt] = j; //把j结点 压入队列
            }
        }
    }

    return d[n];
}
