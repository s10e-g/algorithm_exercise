#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, ans = 1;
    cin>>n>>t;
    if (n == 1 && t == 10) {
        cout<<-1<<endl;
        return 0;
    }
    else {
        if (n >= 4) {
            n -= 4;
            cout<<2520;
            while (n--)
                cout<<0;
        }
        else {
            for (int i = 1; i < n; ++i) {
                ans *= 10;
            }
            while (ans % t) {
                ++ans;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

