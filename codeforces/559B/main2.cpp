#include <iostream>
#include <string>

using namespace std;

bool eq(string, string);

int main()
{
    string a, b;
    ios::sync_with_stdio(false);
    cin>>a>>b;
    if (a.length() != b.length()) {
        cout<<"NO"<<endl;
        return 0;
    }
    else {
        cout<<(eq(a, b)?"YES":"NO")<<endl;
        return 0;
    }
}

bool eq(string a, string b)
{
    if (a == b)
        return true;

    if (a.length() & 1)
        return false;

    return (eq(a.substr(0, a.length()>>1), b.substr(0, b.length()>>1)) &&
        eq(a.substr(a.length()>>1), b.substr(b.length()>>1))) ||
        (eq(a.substr(0, a.length()>>1), b.substr(b.length()>>1)) &&
         eq(a.substr(a.length()>>1), b.substr(0, b.length()>>1)));
}

