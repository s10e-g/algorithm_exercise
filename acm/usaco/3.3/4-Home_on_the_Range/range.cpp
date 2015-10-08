/*
ID: shadowm6
PROG: range
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("range.in");
    ofstream fout("range.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    int n, out = 0;
    int g[251][251] = {{0}}, res[251][251] = {{0}};
    int ans[251] = {0};
    char in;

    fin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            fin>>in;
            while(in == '\n')
                fin>>in;
            g[i][j] = in - '0';
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(g[i][j]){
                res[i][j] = min(res[i-1][j], min(res[i][j-1], res[i-1][j-1])) + 1;
                ans[res[i][j]]++;
            }

    for(int i = 2; i <= n; i++)
        out += ans[i];

    for(int i = 2; i <= n; i++){
        fout<<i<<' '<<out<<endl;
        out -= ans[i];
        if(out == 0)
            break;
    }

    return 0;
}

