#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node {
    int n;
    list<int> a;
};

vector<Node> nodes(100000);

int main()
{
    nodes[1].a.push_back(2);
    nodes[2].a.push_back(1);

    for(auto i = nodes[1].a.begin(); i != nodes[1].a.end(); ++i) {
        nodes[1].a.erase(i);
        nodes[1].a.clear();
        nodes[*i]
    }
}

