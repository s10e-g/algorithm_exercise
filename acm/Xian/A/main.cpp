#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string str;
    while (getline(cin, str)) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'A' && str.substr(i, 5) == "Apple")
                cout<<"MAI MAI MAI!"<<endl;
            if (str[i] == 'i' && (str.substr(i, 6) == "iPhone" || str.substr(i, 4) == "iPod"
                        || str.substr(i, 4) == "iPad"))
                cout<<"MAI MAI MAI!"<<endl;
            if (str[i] == 'S' && str.substr(i, 4) == "Sony")
                cout<<"SONY DAFA IS GOOD!"<<endl;
        }
    }
    return 0;
}

