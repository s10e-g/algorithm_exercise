#include <iostream>

#define MAXN 100001

using namespace std;

int main()
{
    int n, a;
    int c[MAXN] = {0}, step[MAXN] = {0};

    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int cc = 0;
        cin>>a;
        for (int j = a, ct = 0; j < MAXN; j <<= 1, ++ct) {
            ++c[j];
            step[j] += ct;
        }
        while (a > 1) {
            if (a & 1) {
                a >>= 1;
                ++cc;
                for (int j = a, ct = cc; j < MAXN; j <<= 1, ++ct) {
                    ++c[j];
                    step[j] += ct;
                }
            }
            else {
                a >>= 1;
                ++cc;
                ++c[a];
                step[a] += cc;
            }
        }
    }

    int min_step = 2147483647;
    for (int i = 1; i < MAXN; ++i) {
        if (c[i] == n)
            if (step[i] < min_step)
                min_step = step[i];
    }
    cout<<min_step<<endl;
    return 0;
}

