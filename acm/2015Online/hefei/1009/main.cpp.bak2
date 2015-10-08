#include <bits/stdc++.h>

using namespace std;

int v[31][31];
pair<int, int> f[31][31][31][31];   //sum, ss

inline int calc(pair<int, int>, int);
pair<int, int> search(int, int, int, int);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>n>>m;
        memset(f, -1, sizeof(f));
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin>>v[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i][j][i][j] = make_pair(v[i][j], v[i][j]*v[i][j]);
                f[i][j][i+1][j] = make_pair(
                        v[i][j]+v[i+1][j],
                        v[i][j]*v[i][j]+v[i+1][j]*v[i+1][j]
                        );
                f[i][j][i][j+1] = make_pair(
                        v[i][j]+v[i][j+1],
                        v[i][j]*v[i][j]+v[i][j+1]*v[i][j+1]
                        );
            }
        }
        cout<<"Case #"<<t<<": "<<calc(search(0, 0, n-1, m-1), m+n-1)<<endl;
    }
    return 0;
}

pair<int, int> search(int x1, int y1, int x2, int y2)
{
    if (f[x1][y1][x2][y2].first >= 0)
        return f[x1][y1][x2][y2];
    f[x1][y1][x2][y2].first = 0;
    f[x1][y1][x2][y2].second = 30000;
    pair<int, int> res;
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (i == x1 && j == y1)
                continue;
            res.first = search(x1, y1, i, j).first+search(i, j, x2, y2).first-v[i][j];
            res.second = search(x1, y1, i, j).second+search(i, j, x2, y2).second-v[i][j]*v[i][j];
            if (calc(res, x2-x1+y2-y1+1) < calc(f[x1][y1][x2][y2], x2-x1+y2-y1+1))
                f[x1][y1][x2][y2] = res;
        }
    }
    return f[x1][y1][x2][y2];
}

inline int calc(pair<int, int> a, int n)
{
    return a.second*n-a.first*a.first;
}

