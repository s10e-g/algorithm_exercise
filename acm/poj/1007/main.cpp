#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct DNA{
    string dna_string;
    int inversions;

    bool operator<(const struct DNA& b) const
    {
        return inversions < b.inversions;
    }
};

int main()
{
    int n, m;
    cin>>n>>m;
    vector<struct DNA> dna(m);
    for(int i = 0; i < m; i++){
        cin>>dna[i].dna_string;
        for(int j = 0; j < n-1; j++)
            for(int k = j+1; k < n; k++)
                if(dna[i].dna_string[j] > dna[i].dna_string[k])
                    dna[i].inversions++;
    }
    stable_sort(dna.begin(), dna.end());
    for(int i = 0; i < m; i++)
        cout<<dna[i].dna_string<<endl;
    return 0;
}

