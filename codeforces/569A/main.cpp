#include <iostream>

using namespace std;

int main()
{
    int t, s, q, ans = 0;
    ios::sync_with_stdio(false);
    cin>>t>>s>>q;
    while (s < t) {
        //s += s/(1-(q-1.)/q)*(q-1)/q;
        s *= q;
        ++ans;
    }
    if (!ans)
        ++ans;
    cout<<ans<<endl;
    return 0;
}

