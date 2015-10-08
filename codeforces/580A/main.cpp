#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, max = 1, l;
    int a[100001];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    l = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i-1]) {
            ++l;
            if (l > max)
                max = l;
        }
        else {
            l = 1;
        }
    }
    cout<<max<<endl;
    return 0;
}

