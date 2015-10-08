#include <iostream>
#include <string>

using namespace std;

const string tzolkin_d_trans[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

const string haab_m_trans[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

int main()
{
    int n, haab_d, haab_y, tzolkin_m, tzolkin_y, day;
    string haab_m, tzolkin_d;
    cin>>n;
    cout<<n<<endl;  //WTF
    for(int i = 0; i < n; i++){
        cin>>haab_d>>haab_m>>haab_m>>haab_y;

        for(int j = 0; j < 19; j++)
            if(haab_m_trans[j] == haab_m){
                day = j * 20;
                break;
            }

        day += haab_y * 365 + haab_d;
        cout<<day % 13 + 1<<' '<<tzolkin_d_trans[day % 20]<<' '<<day / 260<<endl;
    }
    return 0;
}

