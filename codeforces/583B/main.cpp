#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0, p = 0, n;
    int a[1000];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    while (p < n) {
        for (int i = 0; i < n; ++i) {
            if (a[i] <= p) {
                a[i] = 99999;
                ++p;
            }
        }
        if (p >= n) {
            break;
        }
        ++ans;
        for (int i = n-1; i >= 0; --i) {
            if (a[i] <= p) {
                a[i] = 99999;
                ++p;
            }
        }
        if (p >= n) {
            break;
        }
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}

