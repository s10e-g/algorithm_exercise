#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, min = 20000, a, b;
    bool* kn[4001];
    vector<int> f[4001];
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        kn[i] = new bool[n+1];
        memset(kn[i], 0, sizeof(bool)*(n+1));
    }
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        kn[a][b] = true;
        kn[b][a] = true;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < f[i].size(); ++j)
            for (int k = j+1; k < f[i].size(); ++k)
                if (kn[f[i][j]][f[i][k]])
                    if (f[f[i][j]].size() + f[f[i][k]].size() + f[i].size() < min)
                        min = f[f[i][j]].size() + f[f[i][k]].size() + f[i].size();
    if (min == 20000)
        cout<<-1<<endl;
    else
        cout<<min-6<<endl;
    for (int i = 1; i <= n; ++i)
        delete[] kn[i];
    return 0;
}

