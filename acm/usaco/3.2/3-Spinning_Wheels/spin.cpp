/*
ID: shadowm6
PROG: spin
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    int speed[5], t, start, len;
    bool empty[5][360] = {0};
    for(int i = 0; i < 5; i++){
        fin>>speed[i]>>t;
        for(int j = 0; j < t; j++){
            fin>>start>>len;
            for(int k = 0; k <= len; k++)
                empty[i][(start + k) % 360] = true;
        }
    }

    for(int i = 0; i < 360; i++)
        for(int j = 0; j < 360; j++){
            int k;
            for(k = 0; k < 5; k++)
                if(!empty[k][(j - speed[k] * i % 360 + 360) % 360])
                    k = 5;
            if(k == 5){
                fout<<i<<endl;
                return 0;
            }
        }
    fout<<"none"<<endl;
    return 0;
}

