#include <bits/stdc++.h>

using namespace std;

int n, m;
bool a[100001] = {0};
vector<int> f[100001];

int dfs(int, int, int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin>>x>>y;
        f[x].push_back(y);
        f[y].push_back(x);
    }
    if (a[1])
        cout<<dfs(1, m-1, 0)<<endl;
    else
        cout<<dfs(1, m, 0)<<endl;
    return 0;
}

int dfs(int x, int mm, int b)
{
    int res = 0;
    if (mm < 0)
        return 0;
    if (f[x].size() == 1 && x != 1)
        return 1;
    for (auto i = f[x].begin(); i != f[x].end(); ++i) {
        if (*i != b) {
            if (a[*i])
                res += dfs(*i, mm-1, x);
            else
                res += dfs(*i, m, x);
        }
    }
    return res;
}

