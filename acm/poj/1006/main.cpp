#include <iostream>

using namespace std;

//Output Format: Case 1: the next triple peak occurs in 21252 days.

int main()
{
    int p, e, i, d, n = 1, res;
    cin>>p>>e>>i>>d;
    while(p != -1){
        p %= 23;
        e %= 28;
        i %= 33;
        res = (p * 5544 + e * 14421 + i * 1288 - d + 21252) % 21252;
        if(res == 0)
            res += 21252;
        cout<<"Case "<<n<<": the next triple peak occurs in "<<res<<" days."<<endl;
        cin>>p>>e>>i>>d;
        n++;
    }
    return 0;
}

