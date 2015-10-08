#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, m;
    long long ans;
    vector<int> a(100000);
    cin>>t;
    for(int i = 0; i < t; ++i){
        cin>>n>>m;
        for(int j = 0; j < n; ++j){
            cin>>a[j];
        }
        sort(a.begin(), a.end());
        while(*a.end() > m)
            a.pop_back();
        cout<<"Case #"<<i+1<<": ";
    }
    return 0;
}

