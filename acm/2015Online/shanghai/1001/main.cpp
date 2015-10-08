#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define  MAXN  100008
struct edge
{
    int from;
    int to;
    int next;
}Edge[MAXN];
int head[MAXN],tot;
int value[MAXN];
int subValue[MAXN];
int usedfather[MAXN];
int N;
void addEdge(int from,int to)
{
    Edge[tot].from  = from;
    Edge[tot].to = to;
    Edge[tot].next = head[from];
    head[from] = tot;
    tot++;
}

int gcd(int a,int b)
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}

void dfs(int cur)
{
    if (head[cur]==-1)
        return;
    for (int i=head[cur];i!=-1;i=Edge[i].next)
    {
        int v = Edge[i].to;
        for (int j=0;j<N;++j)
        {
            if (usedfather[j]&&value[j]==1)
                subValue[j]++;
            else if (usedfather[j]&&value[v]==1)
                subValue[j]++;
            else if (usedfather[j]&&gcd(value[j],value[v])==1)
                subValue[j]++;
        }
        usedfather[v] = 1;
        dfs(v);
        usedfather[v] = 0;
    }
}
void solve()
{
    memset(subValue,0,sizeof(subValue));
    memset(usedfather,0,sizeof(usedfather));
    usedfather[0] = 1;
    dfs(0);
    for (int i=0;i<N;++i)
        if (value[i]==1)
            subValue[i]++;
}

int main()
{
    int ncase = 1;
    while(~scanf("%d",&N))
    {
        memset(head,-1,sizeof(head));
        memset(&(Edge->next),-1,sizeof(Edge));
        tot = 0;
        int u,v;
        for (int i=0;i<N-1;++i)
        {
            scanf("%d %d",&u,&v);
            addEdge(u-1,v-1);
        }
        for (int i=0;i<N;++i)
            scanf("%d",&value[i]);
        solve();
        printf("Case #%d:",ncase);
        for (int i=0;i<N;++i)
            printf(" %d",subValue[i]);
        printf("\n");
        ncase++;
    }
    return 0;
}
