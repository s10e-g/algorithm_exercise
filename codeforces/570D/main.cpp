//#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p[500001];
int l[500001], r[500001], c[500001];

int dfs(int, int, int);
int main()
{
    //ios::sync_with_stdio(false);
    int n, m, ans, v, h;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &v);
        p[v].push_back(i);
    }
    getchar();
    for (int i = 1; i <= m; ++i)
        c[i] = 1 << (getchar()-'a');

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &v, &h);
        //TODO
        if (__builtin_ctz(ans) + __builtin_clz(ans) > 30)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

int dfs(int id, int d, int in)
{
}

