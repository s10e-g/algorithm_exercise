#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T, n, q, max, l, r;
    int a[1001];
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n;
        for (int i = 1; i <= n; ++i)
            cin>>a[i];
        cin>>q;
        for (int i = 0; i < q; ++i) {
            cin>>l>>r;
            max = 0;
            for (int j = l; j <= r; ++j) {
                if (a[j] > max)
                    max = a[j];
            }
            cout<<max<<endl;
        }
    }
    return 0;
}

