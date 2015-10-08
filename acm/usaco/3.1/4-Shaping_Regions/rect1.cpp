/*
ID: shadowm6
PROG: rect1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

struct RECT{
    int llx, lly, urx, ury, color;
};

struct RECT make_rect(int, int, int, int, int);

int main()
{
    ifstream fin("rect1.in");
    ofstream fout("rect1.out");

    int a, b, n, colors[2501] = {0};
    int llx, lly, urx, ury, color;
    fin>>a>>b>>n;

    list<struct RECT> rect_list;
//    rect_list.push_back(RECT{0, 0, a, b, 1}); //c++11 only
    rect_list.push_back(make_rect(0, 0, a, b, 1));

    for(int i = 0; i < n; i++){
        fin>>llx>>lly>>urx>>ury>>color;
        for(list<RECT>::iterator it = rect_list.begin(); it != rect_list.end();){
            if(it->urx <= llx || it->llx >= urx || it->ury <= lly || it->lly >= ury){
                it++;
                continue;
            }

            if(llx > it->llx)
                rect_list.push_back(make_rect(it->llx, max(it->lly, lly), llx, it->ury, it->color));
            if(lly > it->lly)
                rect_list.push_back(make_rect(it->llx, it->lly, min(it->urx, urx), lly, it->color));
            if(urx < it->urx)
                rect_list.push_back(make_rect(urx, it->lly, it->urx, min(it->ury, ury), it->color));
            if(ury < it->ury)
                rect_list.push_back(make_rect(max(it->llx, llx), ury, it->urx, it->ury, it->color));

            it = rect_list.erase(it);
        }
        rect_list.push_back(make_rect(llx, lly, urx, ury, color));
    }

    for(list<RECT>::iterator it = rect_list.begin(); it != rect_list.end(); it++){
        colors[it->color] += (it->urx - it->llx) * (it->ury - it->lly);
    }

    for(int i = 1; i <= 2500; i++){
        if(colors[i])
            fout<<i<<' '<<colors[i]<<endl;
    }

    return 0;
}

struct RECT make_rect(int llx, int lly, int urx, int ury, int color)
{
    struct RECT result_rect = {llx, lly, urx, ury, color};
    return result_rect;
}

