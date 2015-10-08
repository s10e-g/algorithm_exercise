#include <iostream>
#include <iomanip>

int main()
{
    double sum = 0, tem;
    for(int i = 0; i < 12; i++){
        std::cin>>tem;
        sum += tem;
    }
    sum /= 12;
    std::cout<<'$'<<std::fixed<<std::setprecision(2)<<sum<<std::endl;
    return 0;
}

