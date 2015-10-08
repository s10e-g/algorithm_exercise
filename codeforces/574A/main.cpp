#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, l, a, ll;
    cin>>n>>ll;
    l = ll;
    priority_queue<int> c;
    for (int i = 0; i < n-1; ++i) {
        cin>>a;
        c.push(a);
    }
    while (l <= c.top()) {
        ++l;
        c.push(c.top()-1);
        c.pop();
    }
    cout<<l-ll<<endl;
    return 0;
}

