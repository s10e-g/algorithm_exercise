#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

vector<int> num[10];
int m[3];

bool scn()
{
    if (num[m[0]].size() == 0 || num[m[1]].size() == 0 || num[m[2]].size() == 0)
        return false;
    int l = num[m[0]][0];
    int r = num[m[2]][num[m[2]].size() -1];
    for (int i = 0; i < num[m[1]].size(); i++)
    {
        int mid = num[m[1]][i];
        if (l < mid && mid < r)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '0')
        {
            printf("YES\n0");
            return 0;
        }
        num[str[i]-48].push_back(i);
    }
    for (int i = 1; i < 1000; ++i)
    {
        if (i % 8 != 0)
            continue;

        int ti = i;
        for (int j = 0; j < 3; ++j)
        {
            m[2-j] = ti % 10;
            ti = ti / 10;
        }
        if (scn())
        {
            printf("YES\n%d", i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}




//811111 hacked
