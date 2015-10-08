#include <iostream>

long long fac[100002] = {1};

using namespace std;

void init_fac(int);
long long C(long long, long long, int);
long long qpow(long long, long long, int);
long long lucas(long long, long long, int);

int main()
{
    ios::sync_with_stdio(false);
    int T, p[11];
    long long n, m, k, ans, M;
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n>>m>>k;
        M = 1;
        ans = 0;
        for (int i = 0; i < k; ++i) {
            cin>>p[i];
            M *= p[i];
        }
        for (int i = 0; i < k; ++i) {
            fac[0] = 1;
            init_fac(p[i]);
            long long l = lucas(n, m, p[i]);
            long long q = qpow(M/p[i], p[i]-2, p[i]);
            l *= q;
            for (int j = 0; j < k; ++j) {
                l %= M;
                if (j != i)
                    l *= p[j];
            }
            l %= M;
            //ans += lucas(n, m, p[i]) * (M/p[i]) * qpow(M/p[i], p[i]-2, p[i]);
            ans += l;
            ans %= M;
        }
        cout<<ans<<endl;
    }
    return 0;
}

long long C(long long n, long long m, int MOD)
{
    if (m > n)
        return 0;
    return fac[n]*qpow(fac[m]*fac[n-m]%MOD, MOD-2, MOD) % MOD;
}

void init_fac(int MOD)
{
    for (int i = 1; i <= 100001; ++i)
        fac[i] = fac[i-1]*i % MOD;
}

long long qpow(long long a, long long b, int MOD)
{
    a %= MOD;
    long long tmp = a, ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * tmp % MOD;
        tmp = tmp * tmp % MOD;
        b >>= 1;
    }
    return ans;
}

long long lucas(long long n, long long m, int p)
{
    if (m == 0)
        return 1;
    return C(n%p, m%p, p) * lucas(n/p, m/p, p);
}

