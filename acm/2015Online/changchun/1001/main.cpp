#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T, k, m, q, max;
    cin>>T;
    for (int t = 0; t < T; ++t) {
        max = 0;
        int query[100] = {0};
        vector<int> out;
        cin>>k>>m>>q;
        priority_queue< pair<int, int> > h;
        vector< pair<string, int> > come(k);
        vector< pair<int, int> > open(m);
        for (int i = 0; i < k; ++i)
            cin>>come[i].first>>come[i].second;
        for (int i = 0; i < m; ++i)
            cin>>open[i].first>>open[i].second;
        sort(open.begin(), open.end());
        for (int i = 0; i < q; ++i) {
            cin>>query[i];
            if (query[i] > max)
                max = query[i];
        }
        int cur = 0;
        for (int i = 0; i < m; ++i) {
            for (; cur < open[i].first; ++cur)
                h.push(make_pair(come[cur].second, 200000 - cur));
            for (int j = 0; j < open[i].second; ++j) {
                if (h.empty())
                    break;
                out.push_back(h.top().second);
                h.pop();
                --max;
                if (!max)
                    goto out;
            }
        }
        for (; cur < k; ++cur)
            h.push(make_pair(come[cur].second, 200000 - cur));
        while (max && !h.empty()) {
            out.push_back(h.top().second);
            h.pop();
            --max;
        }
out:
        for (int i = 0; i < q-1; ++i)
            cout<<come[200000 - out[query[i]-1]].first<<' ';
        cout<<come[200000 - out[query[q-1]-1]].first<<endl;
    }
    return 0;
}

