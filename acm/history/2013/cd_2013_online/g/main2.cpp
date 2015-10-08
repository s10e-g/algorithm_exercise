#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define inf 1000000000
#define maxn 12
#define maxm 10000
int n,m;

int t,len,lem,limit,ans,s;
int a[maxn],b[maxn];
int f[maxn][maxn][maxm];
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf("%d",&t);
    a[1]=1;
    FOR(i,2,9) a[i]=a[i-1]*2;
    FOR(i,0,1024*9)f[0][0][i]=1;
    FOR(i,1,9)
        FOR(j,0,9)
        FOR(k,0,1024*9)
        {
            FOR(j1,0,9)
                if (k-j*a[i]>=0)f[i][j][k]+=f[i-1][j1][k-j*a[i]];
        }

    //cout<<f[2][1][3]<<endl;
    //cout<<f[1][0][3]<<endl;
    //cout<<f[1][1][1]<<endl;
    FOR(ti,1,t)
    {
        scanf("%d%d",&m,&n);
        lem=0;limit=0;
        while(m){
            limit+=(m%10)*a[++lem];
            m/=10;
        }

        //cout<<limit<<endl;
        len=0;
        //n--;
        while (n){
            b[++len]=n%10;
            //cout<<"b"<<b[len]<<endl;
            n/=10;
        }
        ans=0;s=0;//cout<<"len="<<len<<endl;
        FORD(i,len,1)
        {
            FOR(j,0,b[i]-1)
            {

                if (limit>=s)ans+=f[i][j][limit];
                //cout<<i<<" "<<j<<" "<<limit-s<<" "<<f[i][j][limit]<<endl;
                s+=a[i];//cout<<s<<endl;

            }
        }
        if (s<=limit) ++ans;
        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}
