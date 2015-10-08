#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("srand", ios::in);
    fstream fout("in.txt", ios::out);
    int s;
    fin>>s;
    srand(s);
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    fout<<x<<' '<<y<<endl;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++)
            fout<<rand()%1000<<' ';
        fout<<endl;
    }
}

