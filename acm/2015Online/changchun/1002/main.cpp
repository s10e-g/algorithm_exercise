#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

pair<int, long long> dfs(vector< set<int> >&, int*, bool*, int);
int main()
{
    ios::sync_with_stdio(false);
    int T, p, m, a, b;
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>p>>m;
        long long ans = 0;
        int v[10001] = {0};
        vector< set<int> > pipe(p+1);
        for (int i = 1; i <= p; ++i) {
            cin>>v[i];
        }
        for (int i = 0; i < m; ++i) {
            cin>>a>>b;
            pipe[a].insert(b);
            pipe[b].insert(a);
        }
        bool modify = false;
        do {
            modify = false;
            for (int i = 1; i <= p; ++i) {
                if(pipe[i].size() == 1) {
                    pipe[*pipe[i].begin()].erase(i);
                    pipe[i].clear();
                    modify = true;
                }
            }
        } while(modify);
        bool done[10001] = {0};
        pair<int, long long> r;
        for (int i = 1; i <= p; ++i) {
            r = dfs(pipe, v, done, i);
            if (r.first & 1)
                ans += r.second;
        }
        cout<<ans<<endl;
    }
    return 0;
}

pair<int, long long> dfs(vector< set<int> >& pipe, int* v, bool* d, int a)
{
    pair<int, long long> res, t;
    if (!d[a] && !pipe[a].empty()) {
        res.first = 1;
        res.second = v[a];
        d[a] = true;
        for (set<int>::iterator i = pipe[a].begin(); i != pipe[a].end(); ++i) {
            t = dfs(pipe, v, d, *i);
            res.first += t.first;
            res.second += t.second;
        }
    }
    return res;
}

