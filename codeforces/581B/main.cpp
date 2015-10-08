#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int h[100000], max[100001];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>h[i];
    }
    max[n] = h[n-1]-1;
    for (int i = n-1; i >= 0; --i) {
        if (h[i] > max[i+1])
            max[i] = h[i];
        else
            max[i] = max[i+1];
    }
    for (int i = 0; i < n; ++i) {
        if (max[i+1] >= h[i])
            cout<<max[i+1]-h[i]+1<<' ';
        else
            cout<<0<<' ';
    }
    cout<<endl;
    return 0;
}

