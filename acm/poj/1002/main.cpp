#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    const string trans = "                                                0123456789       2223334445556667 77888999";
    vector<int> dict(10000000);
    int n;

    cin>>n;
    for(int i = 0; i < n; i++){
        string raw_str, num_str;
        cin>>raw_str;
        for(int j = 0; j < raw_str.size(); j++)
            if(raw_str[j] != '-')
                num_str += trans[raw_str[j]];
        dict[atoi(num_str.c_str())]++;
    }

    cout.fill('0');
    for(int i = 0; i < 10000000; i++)
        if(dict[i] > 1)
            cout<<setw(3)<<i/10000<<'-'<<setw(4)<<i%10000<<' '<<dict[i]<<endl;
    return 0;
}

