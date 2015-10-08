#include <iostream>
#include <cstring>

using namespace std;

bool eq(char*, char*, int);

int main()
{
    char a[200000], b[200000];
    ios::sync_with_stdio(false);
    cin>>a>>b;
    if (strlen(a) != strlen(b)) {
        cout<<"NO"<<endl;
        return 0;
    }
    else {
        cout<<(eq(a, b, strlen(a))?"YES":"NO")<<endl;
        return 0;
    }
}

bool eq(char* a, char* b, int l)
{
    for (int i = 0; i < l; ++i)
        if (a[i] != b[i])
            goto next;
    return true;

next:
    if (l & 1)
        return false;

    return (eq(a, b, l>>1) && eq(a+(l>>1), b+(l>>1), l>>1)) ||
            (eq(a, b+(l>>1), l>>1) && eq(a+(l>>1), b, l>>1));
}

