#include <iostream>

int main()
{
    double c, now;
    int n;
    std::cin>>c;
    while(c != 0.){
        n = 1;
        now = 0;
        while(now < c){
            n++;
            now += 1./n;
        }
        std::cout<<n-1<<" card(s)"<<std::endl;
        std::cin>>c;
    }
    return 0;
}

