#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int father(int*, int);
int main()
{
    ios::sync_with_stdio(false);
    int T, n, m, q;
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n>>m>>q;
        int f[20001] = {0};
        int c[20001] = {0};
        int ans[5000] = {0};
        set<int> s;
        vector< pair < int, pair<int, int> > > dist(m);
        vector< pair <int, int> > query(q);
        for (int i = 0; i < m; ++i)
            cin>>dist[i].second.first>>dist[i].second.second>>dist[i].first;
        for (int i = 0; i < q; ++i) {
            cin>>query[i].first;
            query[i].second = i;
        }
        sort(dist.begin(), dist.end());
        sort(query.begin(), query.end());
        for (int i = 0, j = 0; i < q; ++i) {
            for (;dist[j].first <= query[i].first && j < m; ++j) {
                if (dist[j].second.first != dist[j].second.second) {
                if (f[dist[j].second.first]) {
                    if (f[dist[j].second.second]) {
                        if (father(f, dist[j].second.first) != father(f, dist[j].second.second)) {
                            c[f[dist[j].second.first]] +=
                                c[f[dist[j].second.second]];
                            c[f[dist[j].second.second]] = 0;
                            s.erase(f[dist[j].second.second]);
                            f[f[dist[j].second.second]] = f[dist[j].second.first];
                        }
                    }
                    else {
                        f[dist[j].second.second] = father(f, dist[j].second.first);
                        c[f[dist[j].second.first]] += 1;
                    }
                }
                else if (f[dist[j].second.second]) {
                        f[dist[j].second.first] = father(f, dist[j].second.second);
                        c[f[dist[j].second.second]] += 1;
                }
                else {
                    f[dist[j].second.first] = dist[j].second.first;
                    f[dist[j].second.second] = dist[j].second.first;
                    c[dist[j].second.first] = 2;
                    s.insert(dist[j].second.first);
                }
            }
            }
            for (set<int>::iterator k = s.begin(); k != s.end(); ++k)
                ans[query[i].second] += c[*k]*(c[*k]-1);
        }
        for (int i = 0; i < q; ++i)
            cout<<ans[i]<<endl;
    }
    return 0;
}

int father(int *f, int a) {
    int oa = a, t;
    if (!f[a])
        return 0;
    while(f[a] != a) {
        a = f[a];
    }
    while(f[oa] != oa) {
        t = oa;
        oa = f[oa];
        f[t] = a;
    }
    return a;
}

