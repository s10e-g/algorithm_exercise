#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, p;
    int *num;
    ios::sync_with_stdio(false);
    while (cin>>n) {
        num = new int[n];
        for (int i = 0; i < n; ++i) {
            cin>>num[i];
        }
        p = 0;
        for (unsigned int i = 1; i <= 0x40000000; i <<= 1) {
            for (int j = 0; j < n; ++j) {
                if (num[j] & i)
                    ++p;
            }
            if (p & 1) {
                cout<<"Win"<<endl;
                goto out;
            }
        }
        cout<<"Lose"<<endl;
out:
        delete[] num;
    }
    return 0;
}

