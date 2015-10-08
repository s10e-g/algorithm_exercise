#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, a, l, r, c;
    string str;
    cin>>l>>m>>r;
    m += r;
    cin>>str;
    __gnu_cxx::crope s = str.c_str();
    for (int i = 0; i < m; ++i) {
        cin>>a>>l>>r>>c;
        if (a == 1) {
            s.replace(l-1, r-l+1, __gnu_cxx::crope(r-l+1, '0'+c));
        }
        else {
            bool t = true;
            for (int i = l-1; i < r-c; ++i) {
                if (s[i] != s[i+c]) {
                    t = false;
                    break;
                }
            }
            if (t)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}

