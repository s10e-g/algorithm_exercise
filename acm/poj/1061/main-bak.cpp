#include <iostream>
#include <set>

using namespace std;

int main()
{
    unsigned int x, y, m, n, l, dis, step, ans;
    set<unsigned int> rems;
    cin>>x>>y>>m>>n>>l;
    x %= l;
    y %= l;
    if(x > y)
        if(m > n){
            dis = l - (x - y);
            step = m - n;
        }
        else{
            dis = x - y;
            step = n - m;
        }
    else if(m > n){
        dis = y - x;
        step = m - n;
    }
    else{
        dis = l - (y - x);
        step = n - m;
    }
    if(step){
        ans = dis / step;
        dis %= step;
        while(dis){
            rems.insert(dis);
            dis += l;
            ans += dis / step;
            dis %= step;
            if(rems.find(dis) != rems.end()){
                cout<<"Impossible"<<endl;;
                break;
            }
        }
        if(!dis)
        cout<<ans<<endl;
    }
    else
        cout<<"Impossible"<<endl;
    return 0;
}

