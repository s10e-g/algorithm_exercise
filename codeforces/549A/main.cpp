#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int x, y, ans = 0;
    char img[50][50];
    bool mark[128];
    cin>>x>>y;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            cin>>img[i][j];

    for (int i = 0; i < x-1; ++i)
        for (int j = 0; j < y-1; ++j) {
            memset(mark, 0, sizeof(mark));
            mark[int(img[i][j])] = true;
            mark[int(img[i+1][j])] = true;
            mark[int(img[i][j+1])] = true;
            mark[int(img[i+1][j+1])] = true;
            if (mark['f'] && mark['a'] && mark['c'] && mark['e'])
                ++ans;
        }

    cout<<ans<<endl;
    return 0;
}

