#include <iostream>

using namespace std;

int main()
{
    int n, k, a, odd, even;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        if (a&1)
            ++odd;
        else
            ++even;
    }
    if ((n-k)&1) {
    }
    else {
    }
    return 0;
}

