#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n, q, i, j, k;
    vector<int> str(27);
    char c;
    map< pair<int, int>, vector<int> > s;
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for (int i = 1; i <= n; ++i) {
        cin>>c;
        ++str[c-'a'];
        s[make_pair(i, i)] = str;
        str.assign(27, 0);
    }

    for (int Q = 0; Q < q; ++Q) {
        cin>>i>>j>>k;
    }
    return 0;
}

