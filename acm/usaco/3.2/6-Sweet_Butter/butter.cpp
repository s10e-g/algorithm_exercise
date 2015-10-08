/*
ID: shadowm6
PROG: butter
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <list>

using namespace std;

struct edge_struct{
    int from, to, length;
    bool operator<(const edge_struct& b) const
    {
        return this->length > b.length;
    }
};

struct node_struct{
    int node_id;
    list< pair<int, int> > edge;  //pair: (to, distance)
};

edge_struct make_edge(int, int, int);
vector<int> dijkstra(int, vector<node_struct>&, int);

int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    int n, p, c, x, y, z, ans = 2147483647;
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin>>n>>p>>c;
    vector< vector<int> > dist(p+1);
    vector<int> pasture(p+1);
    vector<node_struct> node(p+1);
    for(int i = 0; i < n; i++){
        fin>>z;
        pasture[z]++;
    }
    for(int i = 0; i < c; i++){
        fin>>x>>y>>z;
        node[x].edge.push_back(make_pair(y, z));
        node[y].edge.push_back(make_pair(x, z));
    }
    for(int i = 1; i <= p; i++)
        if(pasture[i])
            dist[i] = dijkstra(i, node, p);
    for(int i = 1; i <= p; i++){
        z = 0;
        for(int j = 1; j <= p; j++)
            if(pasture[j])
                z += dist[j][i] * pasture[j];
        if(z < ans)
            ans = z;
    }
    fout<<ans<<endl;
    return 0;
}

edge_struct make_edge(int from, int to, int length)
{
    edge_struct result = {from, to, length};
    return result;
}

vector<int> dijkstra(int source, vector<node_struct>& node, int p)
{
    priority_queue<edge_struct> heap;
    vector<bool> done(p+1);
    vector<int> distance(p+1); 

    distance.assign(p+1, 999999999);
    distance[source] = 0;
    done[source] = true;

    for(list< pair<int, int> >::iterator i = node[source].edge.begin();
            i != node[source].edge.end(); i++){
        if(!done[i->first])
            heap.push(make_edge(source, i->first, i->second));
        if(distance[i->first] > i->second)
            distance[i->first] = i->second;
    }

    while(!heap.empty()){
        edge_struct current_edge = heap.top();
        heap.pop();
        if(done[current_edge.to])
            continue;
        done[current_edge.to] = true;

        for(list< pair<int, int> >::iterator i = node[current_edge.to].edge.begin();
                i != node[current_edge.to].edge.end(); i++){
            if(distance[i->first] > distance[current_edge.to] + i->second){
                distance[i->first] = distance[current_edge.to] + i->second;
                if(!done[i->first])
                    //heap.push(make_edge(current_edge.to, i->first, i->second));
                    heap.push(make_edge(source, i->first, i->second + distance[current_edge.to]));
            }
        }
    }

    return distance;
}

