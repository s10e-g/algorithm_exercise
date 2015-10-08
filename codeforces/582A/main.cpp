#include <bits/stdc++.h>

using namespace std;

int gcd(int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, nn, g, st;
    cin>>n;
    nn = n*n;
    vector<int> a(nn);
    vector<int> ans;
    for (int i = 0; i < nn; ++i) {
        cin>>a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    ans.push_back(a.front());
    st = nn-1;
    while (a[st] == 1)
        --st;

    for (int i = 1; i < nn && ans.size() < n; ++i) {
        if (a[i] > 0) {
            for (auto j = ans.begin(); j != ans.end(); ++j) {
                g = gcd(a[i], *j);
                if (g > 1) {
                    if (g == 2) {
                        a[st] = 0;
                        --st;
                        a[st] = 0;
                        --st;
                    }
                    else {
                        for (int k = i+1, s = 2; k < nn && s > 0; ++k) {
                            if (a[k] == g) {
                                a[k] = 0;
                                --s;
                            }
                        }
                    }
                }
            }
            ans.push_back(a[i]);
            a[i] = 0;
        }
    }

    for (auto i = ans.begin(); i != ans.end(); ++i) {
        cout<<*i<<' ';
    }
    return 0;
}

int gcd(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), min(a, b));
}

