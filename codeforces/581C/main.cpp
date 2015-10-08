#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    int a, sum = 0;
    vector<int> b;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        if (a%10)
            b.push_back(a%10);
        sum += a/10;
    }
    sort(b.begin(), b.end(), greater<int>());
    for (auto i = b.begin(); i != b.end(); ++i) {
        if (k >= 10-*i) {
            k -= 10-*i;
            ++sum;
        }
        else {
            break;
        }
    }
    cout<<min(sum+k/10, n*10)<<endl;
    return 0;
}

