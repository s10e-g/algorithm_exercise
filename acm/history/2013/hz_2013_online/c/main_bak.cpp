#include <iostream>
#include <vector>

using namespace std;

bool walk(vector< vector<int> >, int &, int &, int &, int);
int move_x(int, int);
int move_y(int, int);

int main()
{
    vector< vector<int> > map(1002);
    bool t, d;
    int tx, ty, td, dx, dy, dd, n;
    cin>>n;
    while(n){
        cin>>dx>>dy>>dd>>tx>>ty>>td;
        ++dx;
        ++dy;
        ++tx;
        ++ty;
        t = true;
        d = true;
        for(int i = 0; i < 1002; ++i)
            map[i].resize(1002, 0);
        for(int i = 0; i <= n; ++i){
            map[i][0] = 3;
            map[0][i] = 3;
            map[i][n+1] = 3;
            map[n+1][i] = 3;
        }
        map[dx][dy] = 1;
        map[tx][ty] = 2;
        while(!(dx == tx && dy == ty)){
            if(d)
                d = walk(map, dx, dy, dd, 2);
            if(t)
                t = walk(map, tx, ty, td, 1);
            if(!t && !d)
                break;
        }

        if(dx == tx && dy == ty)
            cout<<dx-1<<" "<<dy-1<<endl;
        else
            cout<<-1<<endl;

        cin>>n;
    }
    return 0;
}

bool walk(vector< vector<int> > map, int &x, int &y, int &d, int t)
{
    if(!(map[move_x(x, d)][move_y(y, d)] & t)){
        map[move_x(x, d)][move_y(y, d)] |= t;
        x = move_x(x, d);
        y = move_y(y, d);
    }
    else{
        if(t == 1)
            --d;
        else
            ++d;
        d += 4;
        d %= 4;
        if(!(map[move_x(x, d)][move_y(y, d)] & t)){
            map[move_x(x, d)][move_y(y, d)] |= t;
            x = move_x(x, d);
            y = move_y(y, d);
        }
        else
            return false;
    }
    return true;
}

int move_x(int x, int d)
{
    if(d == 1)
        return x+1;
    if(d == 3)
        return x-1;
    return x;
}

int move_y(int y, int d)
{
    if(d == 0)
        return y+1;
    if(d == 2)
        return y-1;
    return y;
}

