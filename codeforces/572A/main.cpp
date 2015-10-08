#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a[100000] = {0}, b[100000] = {0};
    int na, nb, k, m;
    cin>>na>>nb>>k>>m;
    for (int i = 0; i < na; ++i)
        cin>>a[i];
    for (int i = 0; i < nb; ++i)
        cin>>b[i];
    if (a[k-1] < b[nb-m])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

