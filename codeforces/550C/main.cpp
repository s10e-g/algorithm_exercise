#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int e[125][4] = {0};
    vector<int> num;
    char c;
    int max = -1, maxn = -1;
    num.push_back(0);
    num.push_back(0);
    while (cin>>c) {
        num.push_back(int(c-'0'));
    }

    while (!num.empty() && num.back() & 1)
        num.pop_back();

    if (num.size() < 3) {
        cout<<"NO"<<endl;
        return 0;
    }

    for (int i = 0; i < 125; ++i) {
        e[i][0] = i*8%10;
        e[i][1] = i*8/10%10;
        e[i][2] = i*8/100;
    }
    for (int i = 0; i < 125; ++i) {
        int j = num.size()-1;
        for (; j >= 0; --j) {
            if (num[j] == e[i][0])
                break;
        }
        --j;
        for (; j >= 0; --j) {
            //cout<<j<<endl;
            if (num[j] == e[i][1])
                break;
        }
        --j;
        for (; j >= 0; --j) {
            if (num[j] == e[i][2])
                break;
        }
        if (j > max) {
            max = j;
            maxn = i;
        }
    }
    if (max >= 0 && maxn >= 0) {
        cout<<"YES"<<endl;
        for (int i = 2; i < max; ++i) {
            cout<<num[i];
        }
        if (max > 1 || e[maxn][2] > 0)
            cout<<e[maxn][2];
        if (max > 0 || e[maxn][1] > 0)
            cout<<e[maxn][1];
        cout<<e[maxn][0]<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}

