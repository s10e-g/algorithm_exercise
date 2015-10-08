/*
他们都说这个题用dij或者spfa我就尝试了一下floyd结果.....
有时间我一定会写写这个题的spfa的 
Executing...
   Test 1: TEST OK [0.011 secs, 5740 KB]
   Test 2: TEST OK [0.000 secs, 5740 KB]
   Test 3: TEST OK [0.011 secs, 5740 KB]
   Test 4: TEST OK [0.011 secs, 5740 KB]
   Test 5: TEST OK [0.011 secs, 5740 KB]
   Test 6: TEST OK [0.032 secs, 5740 KB]
   Test 7: TEST OK [0.151 secs, 5740 KB]
   Test 8: TEST OK [0.389 secs, 5740 KB]
   Test 9: TEST OK [0.896 secs, 5740 KB]
   Test 10: TEST OK [0.886 secs, 5740 KB]
 
 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,p,c,g[801][801],pasture[801],ans=9999999;
void init()
{
    memset(pasture,0,sizeof(pasture));
    memset(g,1,sizeof(g));
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        pasture[a]++;
    }
    for(int i=1;i<=c;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=c;
        g[b][a]=c;
    }      
}
void work()
{
    for(int k=1;k<=p;k++)
        for(int i=1;i<=p;i++)
            for(int j=1;j<=p;j++)
            {                             
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
}
void out()
{
    for(int i=1;i<=p;i++)
    {
        int z=0;
        for(int j=1;j<=p;j++)
        {
            if(i==j) continue;                     
            z+=g[i][j]*pasture[j];
        }
        if(z<ans)
            ans=z;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);    
    init();
    work();
    out();    
    return 0; 
}
