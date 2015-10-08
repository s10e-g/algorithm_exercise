#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, ans = 0, min = 10000000, b = 0;
    int a[100000];
    map<int, int> l;
    int r[100001] = {}, o[100001] = {};
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if (l.find(a[i]) == l.end())
            l[a[i]] = i+1;
        r[l[a[i]]] = i+1;
        ++o[l[a[i]]];
        b = o[l[a[i]]] > b ? o[l[a[i]]] : b;
    }
    for (int i = 0; i < n; ++i) {
        if (o[l[a[i]]] == b && r[l[a[i]]]-l[a[i]] < min) {
            ans = i;
            min = r[l[a[i]]] - l[a[i]];
        }
    }
    cout<<l[a[ans]]<<' '<<r[l[a[ans]]]<<endl;
    return 0;
}

