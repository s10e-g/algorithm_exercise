/*
ID: shadowm6
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int number_lattice_point(int, int);
int number_lattice_point_include_incline(int, int);

int main()
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n, m, p;
    fin>>n>>m>>p;

    if(!n || n == p)
        fout<<number_lattice_point(p, m)<<endl;
    else if(n < p)
        fout<<number_lattice_point(n, m) + number_lattice_point(p - n, m) + m - 1<<endl;
    else
        fout<<number_lattice_point(n, m) - number_lattice_point_include_incline(n - p, m)<<endl;

    return 0;
}

int number_lattice_point(int x, int y)
{
    double slope = (double)y / x;
    int res = 0;
    for(int i = 1; i < x; ++i)
        res += ceil(slope * i) - 1;
    return res;
}

int number_lattice_point_include_incline(int x, int y)
{
    double slope = (double)y / x;
    int res = 0;
    for(int i = 1; i < x; ++i)
        res += floor(slope * i);
    return res;
}

