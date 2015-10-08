#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, n, k, ans;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>n;
        vector<int> num(n);
        for (int i = 1; i < n; ++i) {
            cin>>k;
            ++num[k-1];
            cin>>k;
            ++num[k-1];
        }
        ans = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == 2)
                ++ans;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}

