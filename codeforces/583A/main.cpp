#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    bool h[51] = {0}, v[51] = {0};
    cin>>n;
    for (int i = 0; i < n*n; ++i) {
        cin>>a>>b;
        if (!h[a] && !v[b]) {
            h[a] = true;
            v[b] = true;
            cout<<i+1<<' ';
        }
    }
    return 0;
}

