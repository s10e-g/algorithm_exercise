#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100010];
int b[100010];
int flag[100010];
int ff[100010];
int two(int x);
int main()
{
    int n;
    int i,j,k;
    while(cin>>n)
    {
        int znum = two(n);
        int ans = 0;
        int js = 0;
        int twopow;
        memset(flag,0,sizeof(flag));
        memset(ff,0,sizeof(ff));
        for(i=0;i<=n;i++)
        {
            //cin>>a[i];
            a[i] = i;
        }
        while(js!=n+1)
        {
            if((n+1)%2!=0)
            {
                twopow = pow(2,znum)-1;
                for(i=0;i<=n;i++)
                {
                    if((twopow^a[i])<=n)
                    {
                        if(flag[twopow^a[i]]==0&&a[i]!=0&&ff[i]==0)
                        {
                            b[i]=twopow^a[i];
                            flag[twopow^a[i]]=1;
                            ff[i]=1;
                            js++;
                        }
                    }
                    else if(a[i]==0&&flag[a[i]]==0&&ff[i]==0)
                    {
                        js++;
                        ff[i]=1;
                        b[i]=a[i];
                        flag[a[i]]=1;
                    }
                }
            }
            else
            {
                twopow = pow(2,znum)-1;
                for(i=0;i<=n;i++)
                {
                    if((twopow^a[i])<=n)
                    {
                        if(flag[twopow^a[i]]==0&&ff[i]==0)
                        {
                            b[i]=twopow^a[i];
                            flag[twopow^a[i]]=1;
                            ff[i]=1;
                            js++;
                        }
                    }
                }
            }
            znum--;
        }
        for(i=0;i<=n;i++)
            ans += a[i]^b[i];
        cout<<n<<' '<<ans<<endl;
        for(i=0;i<=n-1;i++)
            cout<<b[i]<<" ";
        cout<<b[n]<<endl;
    }
    return 0;
}
int two(int x)
{
    int num=0;
    while(x>>1!=0)
    {
        x=x>>1;
        num++;
    }
    num++;
    return num;
}
