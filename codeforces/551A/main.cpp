#include <iostream>

using namespace std;

int main()
{
    int n, a[2000], r[2002] = {0};
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        ++r[a[i]];
    }
    for (int i = 1999; i >= 0; --i)
        r[i] += r[i+1];
    for (int i = 0; i < n-1; ++i) {
        cout<<r[a[i]+1]+1<<' ';
    }
    cout<<r[a[n-1]+1]+1;
    return 0;
}

