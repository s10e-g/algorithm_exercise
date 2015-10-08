#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    array<int, 7> p;
    array<pair<int, int>, 7> v;
    map<array<int, 7>, int> s;
    queue< pair<array<int, 7>, int> > q;

    //bfs
    for (int i = 3; i < 8; ++i) {
    }

    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n;
        p.fill(0);
        for (int i = 0; i < n; ++i) {
            cin>>v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            p[i] = v[i].second;
        }
        if (n < 2) {
            cout<<0<<endl;
        }
        else if (n == 2) {
            if (p[0] < p[1])
                cout<<0<<endl;
            else
                cout<<-1<<endl;
        }
        else {
            if (s.find(p) != s.end())
                cout<<s[p]<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}

