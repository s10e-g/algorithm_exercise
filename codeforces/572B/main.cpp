#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, s, p, q;
    char d;
    vector< pair<int, int> > buy, sell, buy_agg, sell_agg;
    cin>>n>>s;
    for (int i = 0; i < n; ++i) {
        cin>>d>>p>>q;
        if (d == 'B')
            buy.push_back(make_pair(p, q));
        else
            sell.push_back(make_pair(p, q));
    }
    sort(buy.begin(), buy.end());
    sort(sell.begin(), sell.end());
    for (auto i = buy.begin(); i != buy.end(); ++i) {
        if (buy_agg.empty()) {
            buy_agg.push_back(*i);
            continue;
        }
        if (buy_agg.rbegin()->first == i->first)
            buy_agg.rbegin()->second += i->second;
        else
            buy_agg.push_back(*i);
    }
    for (auto i = sell.begin(); i != sell.end(); ++i) {
        if (sell_agg.empty()) {
            sell_agg.push_back(*i);
            continue;
        }
        if (sell_agg.rbegin()->first == i->first)
            sell_agg.rbegin()->second += i->second;
        else
            sell_agg.push_back(*i);
    }
    for (int i = s-1; i >= 0; --i) {
        if (i >= sell_agg.size())
            continue;
        cout<<"S "<<sell_agg[i].first<<' '<<sell_agg[i].second<<endl;
    }
    for (auto i = buy_agg.rbegin(); i != buy_agg.rend() && s; ++i, --s)
        cout<<"B "<<i->first<<' '<<i->second<<endl;
    return 0;
}

