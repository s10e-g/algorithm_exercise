#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i){
        cin>>str;

        string::size_type p = str.rfind("desu");

        if(p == str.length() - 4){
            str = str.substr(0, str.length() - 4);
        }

        str += "nanodesu";

        cout<<"Case #"<<i+1<<": "<<str<<endl;
    }
    return 0;
}

