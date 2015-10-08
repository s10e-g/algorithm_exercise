#include <iostream>
#include <cstring>

using namespace std;

int matrix(int, int, int*);

int main()
{
    int n, m;
    int num[11] = {0};
    ios::sync_with_stdio(false);
    while (cin>>n>>m) {
        m %= 4994220;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; ++i) {
            cin>>num[i];
            num[i] %= 10000007;
        }
        cout<<matrix(n, m, num)<<endl;
    }
    return 0;
}

int matrix(int n, int m, int* num)
{
    int mat[11] = {0};
    num[0] = 23;
    for (int i = 1; i <= m; ++i) {
        if (i & 1) {
            mat[0] = (num[0] * 10 + 3) % 10000007;
            for (int j = 1; j <= n; ++j) {
                mat[j] = (mat[j-1] + num[j]) % 10000007;
            }
        }
        else {
            num[0] = (mat[0] * 10 + 3) % 10000007;
            for (int j = 1; j <= n; ++j) {
                num[j] = (num[j-1] + mat[j]) % 10000007;
            }
        }
    }
    return m&1 ? mat[n] : num[n];
}

