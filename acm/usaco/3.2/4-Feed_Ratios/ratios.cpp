/*
ID: shadowm6
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");
    int a, b, c, a1, b1, c1, a2, b2, c2, a3, b3, c3;
    fin>>a>>b>>c>>a1>>b1>>c1>>a2>>b2>>c2>>a3>>b3>>c3;
    for(int t = 1; t < 300; t++)
        for(int i = 0; i < 100 && i <= t; i++)
            for(int j = 0; j < 100 && j <= t && t-i-j >= 0; j++){
                int n = 0;
                if(((t-i-j) * a1 + i * a2 + j * a3) % a == 0)
                    n = ((t-i-j) * a1 + i * a2 + j * a3) / a;
                if(n && ((t-i-j) * b1 + i * b2 + j * b3) == b * n &&
                        ((t-i-j) * c1 + i * c2 + j * c3) == c * n){
                    fout<<t-i-j<<' '<<i<<' '<<j<<' '
                        <<((t-i-j) * a1 + i * a2 + j * a3) / a<<endl;
                    return 0;
                }
            }
    fout<<"NONE"<<endl;
    return 0;
}

