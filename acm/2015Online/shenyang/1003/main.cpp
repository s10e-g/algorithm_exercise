#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

void dfs(int, deque<int>*, bool*, int);
int dfs2(int, deque<int>*, deque<int>*, bool*, int);
int main()
{
    ios::sync_with_stdio(false);
    int T, n, m, a, b;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        deque<int> te[20001], ge[20001];
        vector< pair<int, int> > tree;
        cin>>n>>m;
        for (int i = 1; i < n; ++i) {
            cin>>a>>b;
            te[a].push_back(b);
            te[b].push_back(a);
            tree.push_back(make_pair(a, b));
        }
        for (int i = n-1; i < m; ++i) {
            cin>>a>>b;
            ge[a].push_back(b);
            ge[b].push_back(a);
        }
        int ans = 300000, res;
        for (int i = 0; i < n-1; ++i) {
            bool l[20001] = {0};
            a = tree[i].first;
            b = tree[i].second;
            l[a] = true;
            dfs(a, te, l, b);
            res = dfs2(a, te, ge, l, b);
            if (res < ans)
                ans = res;
        }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
    return 0;
}

void dfs(int a, deque<int>* te, bool* l, int b)
{
    for (deque<int>::iterator i = te[a].begin(); i != te[a].end(); ++i) {
        if (*i != b && !l[*i]) {
            l[*i] = true;
            dfs(*i, te, l, b);
        }
    }
}

int dfs2(int a, deque<int>* te, deque<int>* ge, bool* l, int b)
{
    int res = 0;
    for (deque<int>::iterator i = ge[a].begin(); i != ge[a].end(); ++i) {
        if (!l[*i])
            ++res;
    }
    for (deque<int>::iterator i = te[a].begin(); i != te[a].end(); ++i) {
        if (*i != b) {
            res += dfs2(*i, te, ge, l, a);
        }
    }
    return res;
}

