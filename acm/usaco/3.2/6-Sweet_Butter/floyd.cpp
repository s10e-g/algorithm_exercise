/*
ID: shadowm6
PROG: butter
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <list>

using namespace std;

int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    int n, p, c, x, y, z, ans = 2147483647;
    fin>>n>>p>>c;
    int g[801][801];
    vector<int> pasture(p+1);
    for(int i = 0; i < n; i++){
        fin>>z;
        pasture[z]++;
    }
    for(int i = 1; i <= p; i++)
        for(int j = 1; j <= p; j++)
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = 999999999;
    for(int i = 0; i < c; i++){
        fin>>x>>y>>z;
        g[x][y] = z;
        g[y][x] = z;
    }
    for(int k = 1; k <= p; k++)
        for(int i = 1; i <= p; i++)
            for(int j = 1; j <= p; j++)
                if(g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
    for(int i = 1; i <= p; i++){
        z = 0;
        for(int j = 1; j <= p; j++)
            z += g[j][i] * pasture[j];
        if(z < ans)
            ans = z;
    }
    fout<<ans<<endl;
    return 0;
}

