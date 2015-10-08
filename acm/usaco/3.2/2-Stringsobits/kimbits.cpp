/*
ID: shadowm6
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

unsigned long long combination(unsigned long long, unsigned long long);

string calc_kimbits(unsigned long long, unsigned long long, unsigned long long);

int main()
{
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");

    unsigned long long n, l, i;
    fin>>n>>l>>i;
    fout<<calc_kimbits(n, l, i)<<endl;
    return 0;
}

string calc_kimbits(unsigned long long n, unsigned long long l, unsigned long long i)
{
//    cout<<n<<' '<<l<<' '<<i<<endl;
    if(n == 1)
        if(i == 1)
            return "0";
        else
            return "1";
    unsigned long long max_mn = 1;
    for(int j = l; j > 0; j--){
        max_mn += combination(n-1, j);
//        cout<<"max_mn on j = "<<j<<": "<<max_mn<<endl;
    }
//    cout<<"final max_mn: "<<max_mn<<endl;
    if(max_mn < i)
        return string("1" + calc_kimbits(n - 1, l - 1, i - max_mn));
    else
        return string("0" + calc_kimbits(n - 1, l, i));
}

unsigned long long combination(unsigned long long a, unsigned long long b)
{
    if(a > 28)
        return combination(a - 1, b) + combination(a - 1, b - 1);
    if(b > a)
        return 0;
    unsigned long long res = 1;
    if(b > a / 2)
        b = a - b;
    for(int i = a; i > a - b; i--)
        res *= i;
    for(int i = b; i > 0; i--)
        res /= i;
    return res;
}

