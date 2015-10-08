#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, max, temp_max;
    int a[100001], ans[100001];
    bool used[100001];
    ios::sync_with_stdio(false);
    while (cin>>n) {
        for (int i = 0; i <= n; ++i) {
            //cin>>a[i];
            a[i] = i;
        }
        max = (1<<(32 - __builtin_clz(n))) - 1;

        memset(used, 0, sizeof(used));
        for (int i = n; i >= 0; --i) {
            temp_max = max;
            while ((temp_max^i) > n || used[temp_max^i]) {
                temp_max >>= 1;
            }
            ans[temp_max^i] = i;
            used[temp_max^i] = true;
        }

        cout<<n*(n+1)<<endl;
        for (int i = 0; i < n; ++i) {
            cout<<ans[a[i]]<<' ';
        }
        cout<<ans[a[n]]<<endl;
    }
    return 0;
}

