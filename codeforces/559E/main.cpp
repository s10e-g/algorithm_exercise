#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

int n;
map< pair<int, int>, int> d;

/*
 * dfs(vv, ii)
 * max length of light segment start at position v and spotlight i
 */
int dfs(int, int, vector< pair<int, int> >&);

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    vector< pair<int, int> > l(n);
    for (int i = 0; i < n; ++i) {
        cin>>l[i].first>>l[i].second;
    }
    sort(l.begin(), l.end());
    cout<<dfs(-100000007, 0, l)<<endl;
    return 0;
}

int dfs(int vv, int ii, vector< pair<int, int> >& l)
{
    int t, end, max_t = 0, max_j;
    if (ii >= n)
        return 0;
    if (d.find(make_pair(vv, ii)) != d.end())
        return d[make_pair(vv, ii)];

    //i-th spotlight turn south
    for (int i = ii; i < n; ++i) {
        max_j = i;
        t = min(l[i].second, l[i].first-vv);
        end = l[i].first;
        //j-th spotlight turn north
        for (int j = ii; j < n && l[j].first <= end; ++j)
            if (i != j) {
                if (j > max_j)
                    max_j = j;
                if (l[j].first + l[j].second > end) {
                    t += l[j].first + l[j].second - end;
                    end = l[j].first + l[j].second;
                }
            }
        t += dfs(end, max_j+1, l);
        if (t > max_t)
            max_t = t;
    }

    //ii-th spotlight turn north
    max_j = ii;
    t = l[ii].second;
    end = l[ii].first + l[ii].second;
    //i-th spotlight turn north
    for (int i = ii + 1; i < n && l[i].first <= end; ++i) {
        max_j = i;
        if (l[i].first + l[i].second > end) {
            t += l[i].first + l[i].second - end;
            end = l[i].first + l[i].second;
        }
    }
    t += dfs(end, max_j+1, l);

    return d[make_pair(vv, ii)] = max(max_t, t);
}

