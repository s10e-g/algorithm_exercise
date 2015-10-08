#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T, n, ii;
    long long *t = new long long[1000001];
    long long ti, tj, a, b;
    cin>>T;
    for (int tt = 1; tt <= T; ++tt) {
        cin>>n>>a>>b;
        for (int i = 0; i < n; ++i)
            cin>>t[i];
        if (a >= 0) {
            ti = 0;
            for (int i = 0; i < n; ++i) {
                if (t[i]*t[i] > ti) {
                    ti = t[i]*t[i];
                    ii = i;
                }
            }
        }
        else {
            ti = (long long)1000000 * 2000000;
            for (int i = 0; i < n; ++i) {
                if (t[i]*t[i] < ti) {
                    ti = t[i]*t[i];
                    ii = i;
                }
            }
        }
        if (b >= 0) {
            tj = -2000000;
            for (int i = 0; i < n; ++i) {
                if (t[i] > tj && i != ii)
                    tj = t[i];
            }
        }
        else {
            tj = 2000000;
            for (int i = 0; i < n; ++i) {
                if (t[i] < tj && i != ii)
                    tj = t[i];
            }
        }
        cout<<"Case #"<<tt<<": "<<a*ti+b*tj<<endl;
    }
    delete[] t;
    return 0;
}

