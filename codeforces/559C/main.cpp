#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;
const long long MAXLL = LLONG_MAX/100000;
long long fac[200002] = {1};

using namespace std;

void init_fac();
inline long long ways(int, int, int, int);
long long C(int, int);
long long qpow(long long, long long);

int main()
{
    int h, w, n;
    long long f[2002]; //fi: to the ith black cell without crossing any other black cell
    init_fac();
    cout<<C(9, 5)<<endl;
    ios::sync_with_stdio(false);
    cin>>h>>w>>n;
    vector< pair<int, int> > b(n+1);
    for (int i = 0; i < n; ++i) {
        cin>>b[i].first>>b[i].second;
    }
    b[n].first = h;
    b[n].second = w;
    sort(b.begin(), b.end());
    for (int i = 0; i <= n; ++i) {
        f[i] = ways(1, 1, b[i].first, b[i].second);
        for (int j = 0; j < i; ++j) {
            if (b[j].first<=b[i].first && b[j].second<=b[i].second)
                f[i] -= f[j] * ways(b[j].first, b[j].second, b[i].first, b[i].second) % MOD;
            while (f[i] < 0)
                f[i] += MOD;
        }
    }
    cout<<f[n]%MOD<<endl;
    return 0;
}

inline long long ways(int x1, int y1, int x2, int y2)
{
    return C(x2-x1+y2-y1, x2-x1);
}

long long C(int n, int m)
{
    if (m > n)
        return 0;
    return fac[n]*qpow(fac[m]*fac[n-m]%MOD, MOD-2) % MOD;
}

void init_fac()
{
    for (int i = 1; i <= 200001; ++i)
        fac[i] = fac[i-1]*i % MOD;
}

long long qpow(long long a, long long b)
{
    long long tmp = a, ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * tmp % MOD;
        tmp = tmp * tmp % MOD;
        b >>= 1;
    }
    return ans;
}

