#include <bits/stdc++.h>

using namespace std;

long long spow(long long, long long);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a, n;
    cin>>n;
    a = spow(3, 3*n) - spow(7, n);
    if (a < 0)
        a += 1000000007;
    cout<<a<<endl;
    return 0;
}

long long spow(long long a, long long n)
{
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res *= a;
        res %= 1000000007;
    }
    return res;
}

