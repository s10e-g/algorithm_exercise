#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    unsigned long long n, m, k;
    cin>>T;
    for(int t = 1; t <= T; ++t){
        cin>>n>>m>>k;

        cout<<"Case #"<<t<<": "
            <<n*m*k-1<<' '
            <<ceil(log(n)/log(2))+ceil(log(m)/log(2))+ceil(log(k)/log(2))<<endl;
    }
    return 0;
}

