/*
ID: shadowm6
PROG: camelot
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>

using namespace std;

const int MAX_ROWS = 30;
const int MAX_COLUMNS = 26;

class board{
    int r, c;
    int d[MAX_ROWS][MAX_COLUMNS][MAX_ROWS][MAX_COLUMNS];
    void bfs(int, int);
    void bfs_step(int, int, queue< pair<int, int> >&, int, int);
public:
    board(int, int);
    inline int distance(int, int, int, int) const;
};

void calc_min_cost_k(int, int, int&, int, int, const board&, int, int, pair<int, int>, int);

int main()
{
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(true);

    int r, c, king_x, king_y, temp_x, temp_y, ans = INT_MAX;
    int min_cost[MAX_ROWS][MAX_COLUMNS][2] = {{{0}}};
    vector< pair<int, int> > knight;

    fin>>r>>c;
    board cb(r, c);

    char temp_char;
    fin.get(temp_char);
    while(temp_char == ' ' || temp_char == '\n')
        fin.get(temp_char);
    king_y = temp_char - 'A';
    fin>>king_x;
    king_x--;
    while(fin.get(temp_char)){
        if(temp_char == ' ' || temp_char == '\n')
            continue;
        temp_y = temp_char - 'A';
        fin>>temp_x;
        knight.push_back(make_pair(temp_x - 1, temp_y));
    }

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            min_cost[i][j][1] = max(king_x - i, max(i - king_x, max(king_y - j, j - king_y)));
            for(vector< pair<int, int> >::iterator k = knight.begin(); k != knight.end(); k++){
                int min_cost_this_k = INT_MAX;
                for(int l = 0; l < max(r, c); l++){
                    calc_min_cost_k(king_x + l, king_y, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x - l, king_y, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x, king_y + l, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x, king_y - l, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x + l, king_y + l, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x + l, king_y - l, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x - l, king_y + l, min_cost_this_k, i, j, cb, r, c, *k, l);
                    calc_min_cost_k(king_x - l, king_y - l, min_cost_this_k, i, j, cb, r, c, *k, l);
                }
                if(min_cost_this_k + min_cost[i][j][0] <
                        cb.distance(k->first, k->second, i, j) + min_cost[i][j][1]){
                    min_cost[i][j][1] = min_cost_this_k + min_cost[i][j][0];
                }
                else
                    min_cost[i][j][1] += cb.distance(k->first, k->second, i, j);
                min_cost[i][j][0] += cb.distance(k->first, k->second, i, j);
            }
            if(min_cost[i][j][1] < ans)
                ans = min_cost[i][j][1];
        }

    fout<<ans<<endl;

    return 0;
}

void calc_min_cost_k(int king_x, int king_y, int& min_cost_this_k,
        int i, int j, const board& cb, int r, int c, pair<int, int> k, int l)
{
    if(king_x >= 0 && king_y >= 0 && king_x < r && king_y < c)
        if(cb.distance(k.first, k.second, king_x, king_y) +
                cb.distance(king_x, king_y, i, j) + l <
                min_cost_this_k)
            min_cost_this_k = cb.distance(k.first, k.second, king_x, king_y) +
                cb.distance(king_x, king_y, i, j) + l;
}

board::board(int r_in, int c_in)
{
    r = r_in;
    c = c_in;
    memset(d, CHAR_MAX>>4, sizeof(d));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            bfs(i, j);
}

void board::bfs(int x, int y)
{
    queue< pair<int, int> > bfs_queue;
    d[x][y][x][y] = 0;
    bfs_queue.push(make_pair(x, y));
    
    while(!bfs_queue.empty()){
        bfs_step(2, 1, bfs_queue, x, y);
        bfs_step(1, 2, bfs_queue, x, y);
        bfs_step(2, -1, bfs_queue, x, y);
        bfs_step(1, -2, bfs_queue, x, y);
        bfs_step(-2, 1, bfs_queue, x, y);
        bfs_step(-1, 2, bfs_queue, x, y);
        bfs_step(-2, -1, bfs_queue, x, y);
        bfs_step(-1, -2, bfs_queue, x, y);

        bfs_queue.pop();
    }
}

void board::bfs_step(int row_offset, int col_offset,
        queue< pair<int, int> >& bfs_queue, int x, int y)
{
    if(bfs_queue.front().first + row_offset >= 0 &&
            bfs_queue.front().second + col_offset >= 0 &&
            bfs_queue.front().first + row_offset < r &&
            bfs_queue.front().second + col_offset < c &&
            d[x][y][bfs_queue.front().first][bfs_queue.front().second] <
            d[x][y][bfs_queue.front().first + row_offset]
            [bfs_queue.front().second + col_offset] - 1){

        bfs_queue.push(make_pair(bfs_queue.front().first + row_offset,
                    bfs_queue.front().second + col_offset));

        d[x][y][bfs_queue.front().first + row_offset][bfs_queue.front().second + col_offset] = 
            d[x][y][bfs_queue.front().first][bfs_queue.front().second] + 1;
    }
}

inline int board::distance(int x, int y, int xx, int yy) const
{
    return d[x][y][xx][yy];
}

