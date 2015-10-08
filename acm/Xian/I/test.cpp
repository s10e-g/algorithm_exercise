#include <iostream>

using namespace std;

int main()
{
    int a = 233;
    while (1) {
        a *= 10;
        a += 3;
        a %= 10000007;
        cout<<a<<endl;
    }
    return 0;
}

