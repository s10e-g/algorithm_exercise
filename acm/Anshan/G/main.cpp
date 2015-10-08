#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T, n, tmp;
    double weight, pp;
    vector<int> score;
    ios::sync_with_stdio(false);
    cin>>T;
    
    for (int t = 0; t < T; ++t) {
        score.clear();
        pp = 0;
        weight = 1;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>tmp;
            score.push_back(tmp);
        }
        sort(score.begin(), score.end(), greater<int>());
        for (int i = 0; i < n; ++i) {
            pp += weight * score[i];
            weight *= 0.95;
        }
        printf("%.10f\n", pp);
    }
    return 0;
}

