#include <iostream>
#include <cstring>

using namespace std;

int matrix(int, int, int*);

int main()
{
    int n, m;
    int num[11] = {0};
    while (cin>>n>>m) {
        m %= 4994220;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; ++i) {
            cin>>num[i];
        }
        cout<<matrix(n, m, num)<<endl;
    }
    return 0;
}

int matrix(int n, int m, int* num)
{
    int *mat, *mat2;
    mat = new int[m+1];
    mat2 = new int[m+1];
    mat[0] = 0;
    mat[1] = 233;
    for (int i = 2; i <= m; ++i) {
        mat[i] = (mat[i-1] * 10 + 3) % 10000007;
    }
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            mat2[0] = num[i];
            for (int j = 1; j <= m; ++j) {
                mat2[j] = (mat[j] + mat2[j-1]) % 10000007;
            }
        }
        else {
            mat[0] = num[i];
            for (int j = 1; j <= m; ++j) {
                mat[j] = (mat2[j] + mat[j-1]) % 10000007;
            }
        }
    }
    return n&1 ? mat2[m] : mat[m];
}

