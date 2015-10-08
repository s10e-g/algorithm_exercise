#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, a, b;
    cin>>n>>a;
    while (!(a & 1) && a > 0)
        a >>= 1;
    while (a % 3 == 0 && a > 0)
        a /= 3;
    for (int i = 1; i < n; ++i) {
        cin>>b;
        while (!(b & 1) && b > 0)
            b >>= 1;
        while (b % 3 == 0 && b > 0)
            b /= 3;
        if (a != b) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}

