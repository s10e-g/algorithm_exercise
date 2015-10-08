#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *trans = "                                                0123456789       2223334445556667 77888999                                       ";
    int *dict, n, i, l, no_duplicates = 1;
    char num_str[7];

    dict = malloc(sizeof(int[10000000]));
    memset(dict, 0, sizeof(int[10000000]));
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        l = 0;
        while(l < 7)
        {
            num_str[l] = trans[getchar()];
            if(num_str[l] != ' ')
                l++;
        }
        dict[atoi(num_str)]++;
    }

    for(i = 0; i < 10000000; i++)
        if(dict[i] > 1)
        {
            printf("%03d-%04d %d\n", i/10000, i%10000, dict[i]);
            no_duplicates = 0;
        }

    if(no_duplicates)
        printf("No duplicates.");

    return 0;
}

