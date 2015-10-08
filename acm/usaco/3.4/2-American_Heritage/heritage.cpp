/*
ID: shadowm6
PROG: heritage
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string post_order(string, string);

int main()
{
    ifstream fin("heritage.in");
    ofstream fout("heritage.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    string in_order, pre_order;
    fin>>in_order>>pre_order;

    fout<<post_order(in_order, pre_order)<<endl;;

    return 0;
}

string post_order(string in_order, string pre_order)
{
    size_t root = in_order.find(pre_order[0]);
    if(root)
        if(root == in_order.size() - 1)
            return post_order(in_order.substr(0, root), pre_order.substr(1, root)) +
                in_order[root];
        else
            return post_order(in_order.substr(0, root), pre_order.substr(1, root)) +
                post_order(in_order.substr(root+1), pre_order.substr(root+1)) +
                in_order[root];
    else
        if(in_order.size() == 1)
            return in_order;
        else
            return post_order(in_order.substr(root+1), pre_order.substr(root+1)) + in_order[root];
}

