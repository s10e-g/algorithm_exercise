#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, c;
    int ch[128] = {0}, chb[128] = {0}, chc[128] = {0};
    int maxb = 0, maxc = 0, numb = 1000000, numc;

    ios::sync_with_stdio(false);
    cin>>a>>b>>c;
    for (auto i = a.begin(); i != a.end(); ++i)
        ++ch[*i];
    for (auto i = b.begin(); i != b.end(); ++i)
        ++chb[*i];
    for (auto i = c.begin(); i != c.end(); ++i)
        ++chc[*i];

    for (int i = 'a'; i <= 'z'; ++i) {
        if (chb[i] && ch[i] / chb[i] < numb)
            numb = ch[i] / chb[i];
    }
    for (int i = numb; i >= 0; --i) {
        numc = 1000000;
        for (int j = 'a'; j <= 'z'; ++j) {
            if (chc[j] && (ch[j]-chb[j]*i) / chc[j] < numc)
                numc = (ch[j]-chb[j]*i)/chc[j];
        }

        if (i+numc > maxb+maxc) {
            maxb = i;
            maxc = numc;
        }
    }
    for (int i = 0; i < maxb; ++i)
        cout<<b;
    for (int i = 0; i < maxc; ++i)
        cout<<c;
    for (int i = 'a'; i <= 'z'; ++i)
        for (int j = 0; j < ch[i] - maxb*chb[i] - maxc*chc[i]; ++j)
            cout<<char(i);
    return 0;
}

