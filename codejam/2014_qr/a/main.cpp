#include <iostream>
using namespace std;

int main()
{
    int T, r1, r2, m1[4][4], m2[4][4], ans;
    bool bad;
    cin>>T;
    for (int t = 1; t <= T; ++t) {
        ans = 0;
        bad = false;
        cin>>r1;
        --r1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin>>m1[i][j];
            }
        }
        cin>>r2;
        --r2;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin>>m2[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (m1[r1][i] == m2[r2][j]) {
                    if (ans) {
                        bad = true;
                    } else {
                        ans = m1[r1][i];
                    }
                }
            }
        }

        cout<<"Case #"<<t;
        if (bad) {
            cout<<": Bad magician!"<<endl;
        } else if (ans) {
            cout<<": "<<ans<<endl;
        } else {
            cout<<": Volunteer cheated!"<<endl;
        }
    }
    return 0;
}

