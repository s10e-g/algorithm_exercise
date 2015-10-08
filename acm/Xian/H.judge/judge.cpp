#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, m, ans, t;
    bool use[100010] = {0};
    while (cin>>n>>m) {
        ans = 0;
        memset(use, 0, sizeof(use));
        for (int i = 0; i <= n; ++i) {
            cin>>t;
            if (use[t]) {
                cout<<"USAGE_ERROR: "<<n<<" "<<t<<endl;
                break;
            }
            use[t] = true;
            ans += i^t;
        }
        if (m != ans)
            cout<<"NUM_ERROR: "<<n<<endl;
    }
    return 0;
}

