#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T, n, m, x, y;
    deque< pair<int, int> > p;
    deque<int> sci;
    bool* m[4096];
    for (int i = 0; i < 4096; ++i) {
        m[i] = new bool[4096];
        memset(m[i], 0, sizeof(bool[4096]));
    }
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>n>>m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin>>x>>y;
            }
    }
    return 0;
}

