/*
ID: shadowm6
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    int k, n, max_val = 0;
    fin>>k>>n;
    vector<int> val(n);
    for(int i = 0; i < n; i++){
        fin>>val[i];
        if(val[i] > max_val)
            max_val = val[i];
    }
    max_val *= k;

    vector<int> min_stamp;
    min_stamp.assign(max_val+1, 201);
    min_stamp[0] = 0;

    queue<int> bfs_que;
    for(int i = 0; i < n; i++){
        min_stamp[val[i]] = 1;
        bfs_que.push(val[i]);
    }

    while(!bfs_que.empty()){
        if(min_stamp[bfs_que.front()] < k){
            for(int i = 0; i < n; i++){
                if(min_stamp[bfs_que.front()] < min_stamp[bfs_que.front() + val[i]] - 1){
                    min_stamp[bfs_que.front() + val[i]] = min_stamp[bfs_que.front()] + 1;
                    bfs_que.push(bfs_que.front() + val[i]);
                }
            }
        }
        bfs_que.pop();
    }
    int ans = 0;
    for(int i = 1; i <= max_val; i++)
        if(min_stamp[i] <= k)
            ans++;
        else
            break;

    fout<<ans<<endl;

    return 0;
}

