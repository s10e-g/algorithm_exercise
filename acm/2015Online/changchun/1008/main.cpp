#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T, n, q, x, root;
    int a[1000];
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n;
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        cin>>q;
        for (int i = 0; i < q; ++i) {
            cin>>x;
            int j = 0;
            while (a[j] != x) {
                if (a[j] > x) {
                    cout<<'E';
                    ++j;
                }
                else {
                    cout<<'W';
                    root = a[j];
                    do {
                        ++j;
                    } while (a[j] < root);
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

