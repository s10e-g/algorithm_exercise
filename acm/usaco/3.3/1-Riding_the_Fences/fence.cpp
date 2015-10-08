/*
ID: shadowm6
PROG: fence
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

void find_next_path(int, vector< list<int> >&, list<int>&);

int main()
{
    vector< list<int> > node(501);  //Adjacency list
    list<int> path;
    int f, x, y, begin = 0;

    //input
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin>>f;
    while(f--){
        fin>>x>>y;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    //pretreatment
    for(int i = 1; i < 501; i++){
        if(!begin && node[i].size())
            begin = i;
        if(1 & node[i].size()){
            begin = i;
            break;
        }
    }
    for(int i = 1; i < 501; i++)
        if(node[i].size())
            node[i].sort();

    //dfs
    find_next_path(begin, node, path);

    for(list<int>::reverse_iterator i = path.rbegin(); i != path.rend(); i++)
        fout<<*i<<endl;

    return 0;
}

void find_next_path(int current, vector< list<int> >& node, list<int>& path)
{
    while(!node[current].empty()){
        int next_node = node[current].front();
        node[current].pop_front();
        for(list<int>::iterator i = node[next_node].begin();
                i != node[next_node].end(); i++)
            if(*i == current){
                node[next_node].erase(i);
                break;
            }

        find_next_path(next_node, node, path);
    }

    path.push_back(current);
}

