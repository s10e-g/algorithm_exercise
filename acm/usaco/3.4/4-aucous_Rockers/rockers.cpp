/*
ID: shadowm6
PROG: rockers
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    
    int n, t, m, ans = 0;
    int f[22][22][22] = {{{0}}};
    fin>>n>>t>>m;
    vector<int> length(n+1);
    for(int i = 1; i <= n; ++i)
        fin>>length[i];

    for(int i = 1; i <= m; ++i)
        for(int j = 0; j <= t; ++j)
            for(int k = 0; k <= n; ++k){
                for(int l = k + 1; l <= n; ++l){
                    if(j + length[l] <= t){
                        if(f[i][j][k] + 1 > f[i][j + length[l]][l])
                            f[i][j + length[l]][l] = f[i][j][k] + 1;
                    }
                    else
                        if(f[i][j][k] + 1 > f[i+1][length[l]][l])
                            f[i+1][length[l]][l] = f[i][j][k] + 1;

                }
                if(f[i][j][k] > ans)
                    ans = f[i][j][k];
            }

    fout<<ans<<endl;

    return 0;
}

