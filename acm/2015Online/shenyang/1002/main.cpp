#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    const long long C = 989897948556;
    long long c = C;
    c <<= 3;
    cout<<c<<endl;
    int T, x, m, f;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>x>>m;
        c = C % m;
        for (int i = 0; i < x; ++i) {
            c *= c;
            c %= m;
        }
        c *= (C % m);
        c %= m;
        cout<<"Case #"<<t<<" "<<c<<endl;
    }
    return 0;
}

