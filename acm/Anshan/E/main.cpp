#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

struct Node {
    float hit_rate;
    float hit_rate2;
    list<int> edge_to;
};

int main()
{
    int T, n, m, d, a, b;
    float miss[51][51] = {0};
    float tmp_ans;
    ios::sync_with_stdio(false);
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cin>>n>>m>>d;
        vector<Node> nation(n+1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                if (i == j)
                    miss[i][j] = 0;
                else
                    miss[i][j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            cin>>a>>b;
            nation[a].edge_to.push_back(b);
            nation[b].edge_to.push_back(a);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                nation[j].hit_rate = 0;
                nation[j].hit_rate2 = 0;
            }
            nation[i].hit_rate = 1;
            for (int j = 0; j < d; ++j) {
                if (j & 1) {
                    for (int k = 1; k <= n; ++k) {
                        for (list<int>::iterator it = nation[k].edge_to.begin();
                                it != nation[k].edge_to.end(); ++it) {
                            nation[*it].hit_rate += nation[k].hit_rate2 / nation[k].edge_to.size();
                        }
                        nation[k].hit_rate2 = 0;
                    }
                    for (int k = 1; k <= n; ++k) {
                        miss[i][k] *= 1 - nation[k].hit_rate;
                    }
                }
                else {
                    for (int k = 1; k <= n; ++k) {
                        for (list<int>::iterator it = nation[k].edge_to.begin();
                                it != nation[k].edge_to.end(); ++it) {
                            nation[*it].hit_rate2 += nation[k].hit_rate / nation[k].edge_to.size();
                        }
                        nation[k].hit_rate = 0;
                    }
                    for (int k = 1; k <= n; ++k) {
                        miss[i][k] *= 1 - nation[k].hit_rate2;
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            tmp_ans = 0;
            for (int j = 1; j <= n; ++j) {
                tmp_ans += 1 - miss[j][i];
            }
            tmp_ans /= n;
            printf("%.10f\n", 1-tmp_ans);
        }
    }
    return 0;
}

