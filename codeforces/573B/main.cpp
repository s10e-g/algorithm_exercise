#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, ans = 0;
    int h[100002] = {0};
    int l[100002] = {0}, r[100002] = {0};
    cin>>n;
    for (int i = 1; i <= n; ++i)
        cin>>h[i];
    for (int i = 1; i <= n; ++i)
        l[i] = min(l[i-1]+1, h[i]);
    for (int i = n; i > 0; --i)
        r[i] = min(r[i+1]+1, h[i]);
    for (int i = 1; i <= n; ++i)
        ans = max(ans, min(l[i], r[i]));
    cout<<ans<<endl;
    return 0;
}

