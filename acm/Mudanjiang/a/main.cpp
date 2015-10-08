#include <iostream>
using namespace std;


int main()
{
    int T, n, ans;
    int h[51];
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            cin>>h[i];
        }
        for (int i = 1; i < n-1; ++i) {
            if (h[i] > h[i-1] && h[i] > h[i+1])
                ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}

