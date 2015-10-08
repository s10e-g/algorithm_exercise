#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d, dd;
    long long fac, maxf;
    cin>>n>>d;
    vector< pair<int, int> > f(n);
    for (int i = 0; i < n; ++i) {
        cin>>f[i].first>>f[i].second;
    }
    sort(f.begin(), f.end());
    fac = f.front().second;
    maxf = fac;
    dd = 0;
    for (int i = 0, j = 0; j < n;) {
        if (dd < d) {
            if (fac > maxf)
                maxf = fac;
            ++j;
            fac += f[j].second;
            dd = f[j].first - f[i].first;
        }
        else {
            fac -= f[i].second;
            ++i;
            dd = f[j].first - f[i].first;
        }
    }
    cout<<maxf<<endl;
    return 0;
}

