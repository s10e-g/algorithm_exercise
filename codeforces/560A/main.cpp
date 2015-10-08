#include <iostream>

using namespace std;

int main()
{
    int n, a;
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        if (a == 1) {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<"1"<<endl;
    return 0;
}

