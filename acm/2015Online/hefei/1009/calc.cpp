#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, x;
    int sum = 0, ss = 0;
    while(cin>>x) {
        ++n;
        sum += x;
        ss += x*x;
    }
    cout<<n*ss-sum*sum<<endl;
    return 0;
}

