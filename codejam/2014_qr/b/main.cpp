#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    double c, f, x, r, ans;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>c>>f>>x;
        r = 2;
        ans = 0;
        while (x/r > x/(r+f)+c/r) {
            ans += c/r;
            r += f;
        }
        printf("Case #%d: %.7f\n", t, ans+x/r);
    }
    return 0;
}

