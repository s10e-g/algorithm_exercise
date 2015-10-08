#include <iostream>

using namespace std;

int main()
{
    long long a = 999999999999999999;
    long long b = 999999999999999998;
    __int128_t i;
    i = a * b;
    cout<<a<<' '<<b<<endl;
    cout<<i<<endl;
    return 0;
}

