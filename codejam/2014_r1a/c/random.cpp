#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dis(0, 7);
    int a[100], p;
    for (int t = 0; t < 10000; ++t) {
        for (int i = 0; i < 8; ++i)
            a[i] = i;
        for (int i = 0; i < 8; ++i) {
            p = dis(mt);
            swap(a[i], a[p]);
        }
        for (int i = 0; i < 8; ++i) {
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}

