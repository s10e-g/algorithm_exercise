#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int pre[201315] = {0, 0, 2, 0, 2, 0};
    int mid[201315] = {0, 0, 0, 0, 0, 5};
    for (int i = 6; i < 201315; ++i) {
        pre[i] = pre[i-2];
        mid[i] = mid[i-2] + mid[i-1] + pre[i-1] + 3;
        mid[i] %= 530600414;
    }
    int T, n;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>n;
        cout<<"Case "<<t<<": "<<mid[n]<<endl;
    }
    return 0;
}

