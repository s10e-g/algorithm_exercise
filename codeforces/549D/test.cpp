#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j)
            cout<<(((i+j)&1)?'B':'W');
        cout<<endl;
    }
    return 0;
}

