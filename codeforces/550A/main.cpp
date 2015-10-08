#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    bool ans = 0, tried = 0;
    cin>>str;
    for (int i = 0; (i < str.length()-1) &&! tried; ++i) {
        if (str[i] == 'A' && str[i+1] == 'B') {
            tried = true;
            for (int j = i+2; j < str.length()-1; ++j) {
                if (str[j] == 'B' && str[j+1] == 'A') {
                    ans = true;
                    break;
                }
            }
        }
    }
    tried = false;
    for (int i = 0; (i < str.length()-1) && !tried && !ans; ++i) {
        if (str[i] == 'B' && str[i+1] == 'A') {
            tried = true;
            for (int j = i+2; j < str.length()-1; ++j) {
                if (str[j] == 'A' && str[j+1] == 'B') {
                    ans = true;
                    break;
                }
            }
        }
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}

