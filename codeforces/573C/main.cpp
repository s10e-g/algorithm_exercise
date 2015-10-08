#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, a, b;
    vector<int> *p;
    cin>>n;
    p = new vector<int>[n+1];
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (p[i].size() >= 3) {
        }
    }
out:
    delete[] p;
    return 0;
}

