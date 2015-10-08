/*
ID: shadowm6
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");

    int n, res;
    fin>>n;
    res = n;
    while(--n){
        while(res % 10 == 0)
            res /= 10;
        res %= 10000;
        res *= n;
    }
    fout<<res%10<<endl;
    return 0;
}

