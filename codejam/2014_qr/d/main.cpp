#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int war(list<float>, list<float>);
int dwar(list<float>, list<float>);

int main()
{
    int T, n;
    list<float> bn, bk;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        cin>>n;
        istream_iterator<float> iiter(cin);
        bn.clear();
        bk.clear();
        bn.push_back(*iiter);
        for (int i = 1; i < n; ++i)
            bn.push_back(*++iiter);
        for (int i = 0; i < n; ++i)
            bk.push_back(*++iiter);

        bn.sort();
        bk.sort();

        cout<<"Case #"<<t<<": "<<dwar(bn, bk)<<' '<<war(bn, bk)<<endl;;
    }
    return 0;
}

int war(list<float> a, list<float> b)
{
    auto j = b.begin();
    for (float i : a) {
        for (; j != b.end(); ++j) {
            if (i < *j) {
                b.erase(j++);
                break;
            }
        }
    }
    return b.size();
}

int dwar(list<float> a, list<float> b)
{
    for (auto i = a.begin(); i != a.end();) {
        if (*i < b.front()) {
            i = a.erase(i);
            b.pop_back();
        } else {
            b.pop_front();
            i++;
        }
    }
    return a.size();
}

