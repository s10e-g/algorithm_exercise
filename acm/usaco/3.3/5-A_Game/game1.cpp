/*
ID: shadowm6
PROG: game1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("game1.in");
    ofstream fout("game1.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n;
    int ans[200][200] = {{0}}, sum[200][200] = {{0}};
    fin>>n;
    for(int i = 0; i < n; i++){
        fin>>sum[i][i];
        ans[i][i] = sum[i][i];
    }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n ; j++){
            if(i == j)
                continue;
            sum[i][j] = sum[i][j-1] + sum[j][j];
        }

    for(int i = 1; i < n; i++)
        for(int j = 0; j < n - i; j++){
            ans[j][j+i] = max(sum[j+1][j+i] - ans[j+1][j+i] + sum[j][j],
                    sum[j][j+i-1] - ans[j][j+i-1] + sum[j+i][j+i]);
        }

    fout<<ans[0][n-1]<<' '<<sum[0][n-1] - ans[0][n-1]<<endl;
    return 0;
}

