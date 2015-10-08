#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    int *a = new int[2001];
    cin>>n>>m;
    if (n > m) {
        cout<<"YES"<<endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i] %= m;
        a[i+n] = a[i];
        if (!a[i]) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for (int aa = 0; aa < n; ++aa,++a) {
        bool f[1001][1001] = {0};
        for (int i = 1; i <= n; ++i) {
            f[i][a[i]] = true;
            for (int j = 0; j < m; ++j) {
                if (f[i-1][j]) {
                    f[i][(a[i]+j)%m] = true;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (f[i][0]) {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

