#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void calc_fib(int* fib);

int find_set(int x, int* F);

int main()
{
    int fib[30] = {1, 2};
    int T, n, m, min, max;

    calc_fib(fib);

    ios::sync_with_stdio(false);
    cin>>T;

    for (int t = 1; t <= T; ++t) {
        cin>>n>>m;
        vector< pair<int, int> > white_edge;
        vector< pair<int, int> > black_edge;
        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin>>u>>v>>c;
            if (c)
                white_edge.push_back(make_pair(u, v));
            else
                black_edge.push_back(make_pair(u, v));
        }

        min = 0;
        int fa1[100001] = {0};
        for (vector< pair<int, int> >::iterator i = black_edge.begin(); i != black_edge.end(); ++i) {
            if (find_set(i->first, fa1) != find_set(i->second, fa1)) {
                fa1[fa1[i->first]] = i->second;
            }
        }
        for (vector< pair<int, int> >::iterator i = white_edge.begin(); i != white_edge.end(); ++i) {
            if (find_set(i->first, fa1) != find_set(i->second, fa1)) {
                fa1[fa1[i->first]] = i->second;
                ++min;
            }
        }

        bool connected = true;
        for (int i= 1; i <= n; ++i)
            if (find_set(i, fa1) != find_set(1, fa1)) {
                connected = false;
                break;
            }
        if (!connected) {
            cout<<"Case #"<<t<<": No"<<endl;
            continue;
        }

        max = 0;
        int fa2[100001] = {0};
        for (vector< pair<int, int> >::iterator i = white_edge.begin(); i != white_edge.end(); ++i) {
            if (find_set(i->first, fa2) != find_set(i->second, fa2)) {
                fa2[fa2[i->first]] = i->second;
                ++max;
            }
        }

        bool found = false;
        for (int i = 0; fib[i] <= 100000; ++i)
            if(fib[i] >= min && fib[i] <= max) {
                found = true;
                break;
            }
        if (found)
            cout<<"Case #"<<t<<": Yes"<<endl;
        else
            cout<<"Case #"<<t<<": No"<<endl;
    }
    return 0;
}

void calc_fib(int* fib)
{
    for (int i = 2; fib[i] <= 100000; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int find_set(int x, int* F)
{
    if (F[x] && F[x] != x)
        return F[x] = find_set(F[x], F);
    else
        return F[x] = x;
}

