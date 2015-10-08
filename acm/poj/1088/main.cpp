#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(vector< vector<int> >, vector< vector<int> >&, vector< pair< int, pair<int, int> > >&);

int r, c;

int main()
{
    cin>>r>>c;
    vector< pair< int, pair<int, int> > > h;    //(hight, (x, y))
    vector< vector<int> > g(r, vector<int>(c)), dis(r, vector<int>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin>>g[i][j];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(i > 0 && g[i-1][j] > g[i][j])
                continue;
            if(j > 0 && g[i][j-1] > g[i][j])
                continue;
            if(i < r-1 && g[i+1][j] > g[i][j])
                continue;
            if(j < c-1 && g[i][j+1] > g[i][j])
                continue;
            h.push_back(make_pair(g[i][j], make_pair(i, j)));
            dis[i][j] = 1;
        }
    make_heap(h.begin(), h.end());
    while(!h.empty()){
        bfs(g, dis, h);
    }
    int max_dis = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(dis[i][j] > max_dis)
                max_dis = dis[i][j];
    cout<<max_dis<<endl;
    return 0;
}

void bfs(vector< vector<int> > g,
        vector< vector<int> > &dis,
        vector< pair< int, pair<int, int> > > &h)
{
    pop_heap(h.begin(), h.end());
    int x = h.back().second.first, y = h.back().second.second;
    h.pop_back();

    if(x > 0 && g[x-1][y] < g[x][y] && dis[x-1][y] <= dis[x][y]){
        dis[x-1][y] = dis[x][y] + 1;
        h.push_back(make_pair(g[x-1][y], make_pair(x-1, y)));
        push_heap(h.begin(), h.end());
    }
    if(y > 0 && g[x][y-1] < g[x][y] && dis[x][y-1] <= dis[x][y]){
        dis[x][y-1] = dis[x][y] + 1;
        h.push_back(make_pair(g[x][y-1], make_pair(x, y-1)));
        push_heap(h.begin(), h.end());
    }
    if(x < r-1 && g[x+1][y] < g[x][y] && dis[x+1][y] <= dis[x][y]){
        dis[x+1][y] = dis[x][y] + 1;
        h.push_back(make_pair(g[x+1][y], make_pair(x+1, y)));
        push_heap(h.begin(), h.end());
    }
    if(y < c-1 && g[x][y+1] < g[x][y] && dis[x][y+1] <= dis[x][y]){
        dis[x][y+1] = dis[x][y] + 1;
        h.push_back(make_pair(g[x][y+1], make_pair(x, y+1)));
        push_heap(h.begin(), h.end());
    }
}

