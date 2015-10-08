#include <iostream>

using namespace std;

const double PI = 3.1415926535897932384;

int main()
{
    int n, res;
    double x, y, s;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x>>y;
        s = (x*x + y*y) * PI / 2;
        res = s / 50;
        if(s > res * 50)
            res++;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<res<<'.'<<endl;
    }
    cout<<"END OF OUTPUT.";
    return 0;
}

