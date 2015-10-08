#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, maxi = 0, maxj;
    int v[100], fv[100] = {0};
    cin>>n>>m; 
    for (int i = 0; i < m; ++i) {
        maxj = 0;
        for (int j = 0; j < n; ++j) {
            cin>>v[j];
            if (v[j] > v[maxj])
                maxj = j;
        }
        ++fv[maxj];
    }
    for (int i = 0; i < n; ++i) {
        if (fv[i] > fv[maxi])
            maxi = i;
    }
    cout<<maxi+1<<endl;
    return 0;
}

