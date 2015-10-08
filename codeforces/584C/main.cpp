#include <bits/stdc++.h>

using namespace std;

char diff(char, char);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, d = 0, d1, d2;
    string s1, s2, s3;
    cin>>n>>t>>s1>>s2;
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i])
            ++d;
    }
    if ((d+1)/2 > t) {
        cout<<-1<<endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                s3.push_back(diff(s1[i], s2[i]));
            }
            else {
                s3.push_back(s1[i]);
            }
        }
        if (d > t) {
            d1 = d;
            d2 = d;
            for (int i = 0; i < n && (d1 > t || d2 > t); ++i) {
                if (s1[i] != s2[i]) {
                    if (d1 > d2) {
                        s3[i] = s1[i];
                        --d1;
                    }
                    else {
                        s3[i] = s2[i];
                        --d2;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < n && d < t; ++i) {
                if (s1[i] == s2[i]) {
                    s3[i] = diff(s1[i], s2[i]);
                    ++d;
                }
            }
        }
        cout<<s3<<endl;
    }
    return 0;
}
char diff(char a, char b)
{
    if (a == 'a' || b == 'a') {
        if (a == 'b' || b == 'b') {
            return 'c';
        }
        else {
            return 'b';
        }
    }
    else {
        return 'a';
    }
}

