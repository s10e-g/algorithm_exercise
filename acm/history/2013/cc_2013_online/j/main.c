#include <stdio.h>
#include <stdlib.h>

struct SOCIETY{
    int a, b, c;
};

inline int comp(const void *a, const void *b)
{
    return (*(struct SOCIETY*)a).a - (*(struct SOCIETY*)b).a;
}

int main()
{
    int n, p, f, max, i, lcm;
    struct SOCIETY s[20000];
    while(!feof(stdin)){
        p = 0x7FFFFFFF;
        max = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i){
            scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
            if(s[i].a < p)
                p = s[i].a;
            if(s[i].b > max)
                max = s[i].b;
        }
        qsort(s, n, sizeof(struct SOCIETY), comp);
        m = 1;
        while(p <= max){
            f = 0;
            for(i = 0; i < n; ++i){
                if(s[i].a > p)
                    break;
                if(s[i].a > s[i].b)
                    continue;
                if(s[i].a == p)
                    ++f;
                if(s[i].a + s[i].c <= p+1)
                    s[i].a += s[i].c;
            }
            if(f & 1){
                printf("%d %d\n", p, f);
                break;
            }
            ++p;
        }
        if(p > max)
            printf("DC Qiang is unhappy.\n");
    }
    return 0;
}

