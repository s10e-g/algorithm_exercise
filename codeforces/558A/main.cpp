#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, x, ln = 0, rn = 0, ansl, ansr;
    int t[200001] = {};
    int l[101], r[101];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        cin>>t[x+100000];
    }
    for (int i = 100000; i >= 0; --i) {
        if (t[i]) {
            l[ln+1] = l[ln] + t[i];
            ++ln;
        }
    }
    for (int i = 100000; i <= 200000; ++i) {
        if (t[i]) {
            r[rn+1] = r[rn] + t[i];
            ++rn;
        }
    }
    ansl = ln>rn?(l[rn+1]+r[rn]):(l[ln]+r[ln]);
    ansr = rn>ln?(l[ln]+r[ln+1]):(l[rn]+r[rn]);
    cout<<max(ansl, ansr)<<endl;
    return 0;
}

