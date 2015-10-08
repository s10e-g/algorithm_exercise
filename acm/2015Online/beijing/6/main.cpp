#include <bits/stdc++.h>

using namespace std;

int wf[100001][17];
int hf[100001][17];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, x, y, wi, hi, wa, ha;
    while (cin>>n>>m) {
        memset(wf, 0, sizeof(int[100001][17]));
        memset(hf, 0, sizeof(int[100001][17]));
        wf[1][0] = 1;
        hf[1][0] = 1;
        k = 0;
        for (int i = 2; i <= n; ++i)
            cin>>wf[i][0];
        for (int i = 2; i <= n; ++i)
            cin>>hf[i][0];
        for (int i = 1; i < 17; ++i)
            for (int j = 1; j <= n; ++j) {
                wf[j][i] = wf[wf[j][i-1]][i-1];
                hf[j][i] = hf[hf[j][i-1]][i-1];
            }
        for (int i = 0; i < m; ++i) {
            cin>>x>>y;
            wi = (x+k)%n+1;
            hi = (y+k)%n+1;

            wa = 1;
            ha = 1;
            while (wi != hi) {
                if (wi > hi) {
                    for (int i = 16; i >= 0; --i)
                        if (wf[wi][i] > hi) {
                            wi = wf[wi][i];
                            wa += 1<<i;
                            break;
                        }
                    wi = wf[wi][0];
                    ++wa;
                }
                else {
                    for (int i = 16; i >= 0; --i)
                        if (hf[hi][i] > wi) {
                            hi = hf[hi][i];
                            ha += 1<<i;
                            break;
                        }
                    hi = hf[hi][0];
                    ++ha;
                }
            }
            k = wi;
            cout<<k<<' '<<wa<<' '<<ha<<endl;
        }
    }
    return 0;
}

