#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;

struct Node {
    Node* father[18];
    Node* son[18];
    int h;
};

void clear(Node*);
void insert(int, int, Node*);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Node* q = new Node;
    vector< pair<int, int> > p;
    int T, n, h, k, s;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>n;
        cout<<"Case #"<<t<<": ";
        p.clear();
        clear(q);
        for (int i = 0; i < n; ++i) {
            cin>>h>>k;
            p.push_back(make_pair(h, k));
        }
        sort(p.begin(), p.end(), greater< pair<int, int> >());
        bool imp = false;
        s = 0;
        q->father[0] = q;
        q->son[0] = q;
        for (auto i = p.begin(); i != p.end(); ++i) {
            if (s < i->second) {
                imp = true;
                break;
            }
            else {
                if (i == p.begin()) {
                    q->h = i->first;
                    ++s;
                }
                else {
                    insert(min(s-(i->second), i->second), i->first, q);
                    ++s;
                }
            }
        }
        if (!imp) {
            while (q->father[0] != q) {
                cout<<q->h<<' ';
                q = q->father[0];
            }
            cout<<q->h<<endl;
        }
        else {
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}

void insert(int n, int h, Node* q)
{
    for (int i = 17; i >= 0; ++i) {
        if (n < 1<<i) {
        }
    }
}
void clear(Node* q)
{
    while (q->father[0] != q)
        q = q->father[0];
    while (q->son[0] != q) {
        q = q->son[0];
        delete q->father[0];
    }
}

