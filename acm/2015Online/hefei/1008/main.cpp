#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, s1, s2, w;
    unsigned int d, ans;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>d>>s1>>s2;
        ans = d+1;
        w = 0;
        for (int i = 0; i < 32; ++i) {
            if (ans & (1<<i)) {
                ++w;
            }
        }
        if (w > s2) {
            for (int i = 0; i < 32; ++i) {
                if (ans & (1<<i)) {
                    ans -= 1<<i;
                    --w;
                }
                else {
                    if (w < s2) {
                        ans += 1<<i;
                        ++w;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 32 && w < s1; ++i) {
            if (!(ans & (1<<i))) {
                ans += 1<<i;
                ++w;
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}

