/*
ID: shadowm6
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TrieTree{
    vector<int> data;
    int max;
public:
    TrieTree(const string &, int);
    void fill_tree(const string &, int, int, int);
    int find_max(int);
    string most_freq_str(int);
    void pop_max();
};

int main()
{
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    int a, b, n, bef = -1, tl = 0;
    fin>>a>>b>>n;

    string str, temp_str;
    while(fin>>temp_str)
        str += temp_str;

    TrieTree tt(str, b);

    fout<<tt.find_max(a);
    while(n && tt.find_max(a)){
        if(tl)
            fout<<' ';
        else
            fout<<endl;
        fout<<tt.most_freq_str(a);
        bef = tt.find_max(a);
        tt.pop_max();

        if(tt.find_max(a) != bef){
            n--;
            tl = 0;
            if(n && tt.find_max(a))
                fout<<endl<<tt.find_max(a);
        }
        else
            tl = (tl + 1) % 6;
    }
    fout<<endl;

    return 0;
}

TrieTree::TrieTree(const string &str, int depth)
{
    data.resize(8192);
    max = 0;
    for(int i = 0; i < str.length(); i++){
        fill_tree(str, i, 1, depth);
    }
}

void TrieTree::fill_tree(const string &str, int str_begin, int begin, int depth)
{
    if(depth && str[str_begin])
        if(str[str_begin] == '0'){
            data[begin * 2]++;
            fill_tree(str, str_begin + 1, begin * 2, depth - 1);
        }
        else{
            data[begin * 2 +1]++;
            fill_tree(str, str_begin + 1, begin * 2 + 1, depth - 1);
        }
}

int TrieTree::find_max(int min_depth)
{
    if(!max){
        for(int i = 1<<min_depth; i < 8192; i++)
            if(data[i] > data[max])
                max = i;
    }
    return data[max];
}

string TrieTree::most_freq_str(int min_depth)
{
    find_max(min_depth);

    string res;
    int l = max;
    while(l > 1){
        if(l & 1)
            res = '1' + res;
        else
            res = '0' + res;
        l >>= 1;
    }

    return res;
}

void TrieTree::pop_max()
{
    if(max){
        data[max] = 0;
        max = 0;
    }
}

