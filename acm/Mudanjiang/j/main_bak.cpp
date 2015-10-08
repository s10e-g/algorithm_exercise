#include <iostream>
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
                if (str.substr(0, i) == str.substr(i+j, i) && str.substr(i, j) == str.substr(i+j+i, j) && str.substr(0, i) != str.substr(i, j)) {
                    if (str.substr(0, i) == str.substr(i+i+j+j)) {
                        pretty = true;
                        goto out;
                    }
                    if (str.substr(0, i) == str.substr(l-i-j, i) && str.substr(i, j) == str.substr(l-j) &&
                            str.substr(i+i+j+j, l-3*i-3*j) != str.substr(0, i) && str.substr(i+i+j+j, l-3*i-3*j) != str.substr(i, j)) {
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

