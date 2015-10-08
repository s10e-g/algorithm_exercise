#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int h, n, i, ans;
    long long tl, tr;
    vector < pair<long long, long long> > b;

    ios::sync_with_stdio(false);
    cin>>h>>n;

    long long l = 1ll << (h-1);
    long long r = (1ll<<h) - 1;

    while (n--) {
        cin>>i>>tl>>tr>>ans;
        tl <<= h-i;
        tr = ((tr+1) << (h-i))-1;
        if (ans) {
            l = max(l, tl);
            r = min(r, tr);
        }
        else {
            b.push_back(make_pair(tl, tr));
        }
    }

    if (l > r) {
        cout<<"Game cheated!"<<endl;
        return 0;
    }

    sort(b.begin(), b.end());
    for (auto j = b.begin(); j != b.end(); ++j) {
        if (j->first <= l && l <= j->second)
            l = j->second + 1;
    }
    for (auto j = b.rbegin(); j != b.rend(); ++j) {
        if (j->second >= r && r >= j->first)
            r = j->first - 1;
    }

    if (l > r) {
        cout<<"Game cheated!"<<endl;
        return 0;
    }
    if (l == r) {
        cout<<l<<endl;
        return 0;
    }

    cout<<"Data not sufficient!"<<endl;
    return 0;
}

