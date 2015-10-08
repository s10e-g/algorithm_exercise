#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int a[35],b[35];
inline void change(int p)
{
    int r=p,y=0,j;
    memset(b, 0, sizeof(b));
    while(r>0)
    {
        ++y;
        b[y]=r&1;
        r>>=1;
    }
    for (j=1;j<=33;++j)
        a[j]+=b[j];
}

inline int pd()
{
    int i;
    for (i=1;i<=33;++i)
        return a[i]&1;
    return 0;
}

main()
{
    int n,t,i;
    while(scanf("%d",&n))
    {
        memset(a, 0, sizeof(a));
        for(i=0;i<n;++i)
        {
            scanf("%d",&t);
            change(t);
        }
        if (pd()) printf("Win\n");
        else printf("Lose\n");
    }
}
