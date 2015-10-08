/*
ID: shadowm6
PROG: rockers
LANG: C
*/

#include <stdio.h>

int main()
{
    FILE* fin = fopen("rockers.in", "r");
    FILE* fout = fopen("rockers.out", "w");
    
    int n, t, m, temp_t, temp_m, i, j, temp_ans, ans = 0;
    fscanf(fin, "%d%d%d", &n, &t, &m);
    int length[20];
    for(i = 0; i < n; ++i)
        fscanf(fin, "%d", &length[i]);

    for(i = 0; i < 1<<n; ++i){
        temp_t = t;
        temp_m = m - 1;
        temp_ans = 0;
        for(j = 0; j < n; ++j){
            if(i & 1<<j && temp_m >= 0){
                if(length[j] > t){
                    temp_m = -1;
                    break;
                }
                if(length[j] > temp_t){
                    temp_t = t - length[j];
                    --temp_m;
                }
                else
                    temp_t -= length[j];
            }
        }

        if(temp_m < 0)
            continue;

        for(j = 0; j < n; ++j)
            temp_ans += i>>j & 1;
        if(temp_ans > ans)
            ans = temp_ans;
    }

    fprintf(fout, "%d\n", ans);

    return 0;
}

