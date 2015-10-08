#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, q, m, b, d, a;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cout<<"Case #"<<t<<":"<<endl;
        cin>>q>>m;
        d = 33-__builtin_clz(q-1);
        vector<long long> f(1<<d, 1);
        for (int i = 0; i < q; ++i) {
            cin>>b;
            if (b == 1) {
                a = (1<<(d-1))+i;
                cin>>f[a];
                a >>= 1;
                while (a) {
                    f[a] = f[a*2]*f[a*2+1] % m;
                    a >>= 1;
                }
                cout<<f[1]<<endl;
            }
            else {
                cin>>b;
                a = (1<<(d-1))+b-1;
                f[a] = 1;
                a >>= 1;
                while (a) {
                    f[a] = f[a*2]*f[a*2+1] % m;
                    a >>= 1;
                }
                cout<<f[1]<<endl;
            }
        }
    }
    return 0;
}

