#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    int n, m, ans = 0;
    char c;
    char s[300003];
    pair<int, int> t;
    cin>>n>>m;

    /*
    getc(stdin);
    for (int i = 0; i < n; ++i) {
        c = getc(stdin);
    }
    */
    cin>>(s+1);
    s[0] = 'a';
    s[n+1] = 'a';

    int left = 0;
    for (int i = 1; i <= n+1; ++i) {
        if (s[i] == '.' && s[i-1] != '.')
            left = i;
        if (s[i] != '.' && s[i-1] == '.')
            ans += i - left - 1;
    }

    for (int i = 0; i < m; ++i) {
        cin>>n>>c;
        if (c == '.' && s[n] != '.') {
            if (s[n-1] == '.')
                ++ans;
            if (s[n+1] == '.')
                ++ans;
        }
        if (c != '.' && s[n] == '.') {
            /*
            if ((s[n-1] != '.' && s[n+1] == '.') ||
                    (s[n-1] == '.' && s[n+1] != '.'))
                --t;
            */
            if (s[n-1] == '.')
                --ans;
            if (s[n+1] == '.')
                --ans;
        }
        s[n] = c;
        cout<<ans<<endl;
    }
    return 0;
}

