#include <iostream>

using namespace std;

int main()
{
    int f[1001] = {0, 1, 1, 2};
    int n, max_n = 3, t = 1;
    while(cin>>n){
        for(int i = max_n + 1; i <= n; ++i){
            f[i] = 0;
            for(int j = 1; j < i; ++j){
                if((i-1) % j == 0)
                    f[i] += f[(i-1) / j];
                f[i] %= 1000000007;
            }
        }
        cout<<"Case "<<t++<<": "<<f[n]<<endl;
        if(n > max_n)
            max_n = n;
    }
    return 0;
}

