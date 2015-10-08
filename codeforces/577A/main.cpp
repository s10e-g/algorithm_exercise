#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, x, ans = 0;
    cin>>n>>x;
    for (int i = 1; i <= n; ++i)
        if (x % i == 0 && x / i <= n)
            ++ans;
    cout<<ans<<endl;
    return 0;
}

