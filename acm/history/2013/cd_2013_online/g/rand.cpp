#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout<<10<<endl;

    srand(time(NULL));
    for(int i = 0; i < 10; ++i){
        cout<<rand()%1000000000<<" "<<rand()%1000000000<<endl;
    }
    return 0;
}

