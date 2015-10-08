#include <iostream>

using namespace std;

int main()
{
    int n, m, ans;
    int r[100][100];
    char c;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            cin>>c;
            r[i][j] = (c=='B')? -1: 1;
        }
    for (int i = n-1; i >= 0; --i)
        for (int j = m-1; j >= 0; --j) {
            if (r[i][j]) {
                ++ans;
                for (int k = 0; k <= i; ++k)
                    for (int l = 0; l <= j; ++l)
                        r[k][l] -= r[i][j];
            }
        }

    cout<<ans<<endl;
    return 0;
}

