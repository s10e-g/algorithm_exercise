#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    string str;
    char s[51];
    int l;
    bool pretty = false;
    cin>>T;
    for (int t = 0; t < T; ++t) {
        pretty = false;
        cin>>str;
        str.erase(remove_if(str.begin(), str.end(), [](char x){return ispunct(x);}), str.end());
        strcpy(s, str.c_str());
        l = str.length();

        for (int i = 1; i <= (l-2)/3; ++i) {
            for (int j = 1; i*3+j*2 <= l; ++j) {
                if (strncmp(s, s+i+j, i) == 0 && strncmp(s+i, s+i+i+j, j) == 0 &&
                        (i != j || strncmp(s, s+i, min(i, j) != 0))) {
                    if (l == 3*i+2*j && strncmp(s, s+i+i+j+j, i) == 0) {
                        pretty = true;
                        goto out;
                    }
                    if (l > 3*i+3*j && strncmp(s, s+l-i-j, i) == 0 && strncmp(s+i, s+l-j, j) == 0 &&
                            (l-3*i-3*j != i || strncmp(s+i+i+j+j, s, min(l-3*i-3*j, i)) !=0 )&&
                            (l-3*i-3*j != j || strncmp(s+i+i+j+j, s+i, min(l-3*i-3*j, j)) !=0)) {
                        pretty = true;
                        goto out;
                    }
                }
            }
        }
out:
        if (pretty)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

