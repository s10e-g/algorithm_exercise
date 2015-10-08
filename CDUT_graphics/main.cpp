#include <bits/stdc++.h>
#include <boost/optional.hpp>

using namespace std;

struct intersection_connection {
    pair<float, float> p;   //point coordinate
    list<struct intersection_connection>::iterator trans;
    //if this point is a intersection
    //trans points to same point on the other polygon
    //else trans points to end()
};

//intersection(a, b, c, d)
//a, b: two vertics of the first line
//c, d: two vertics of the second line
boost::optional< pair<float, float> > intersection(pair<float, float>, pair<float, float>,
        pair<float, float>, pair<float, float>);

//clip(vc, vw)
//vc: the coordinate of vertics on candidiate polygon to be clipped.
//vw: the coordinate of vertics on clipping (window) polygon.
vector< vector< pair<float, float> > > clip(list <struct intersection_connection>&,
        list <struct intersection_connection>&);

int main(int argc, char** argv)
{
    //fast input
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int nc, nw;
    bool has_intersection = false;
    struct intersection_connection ic;
    list <struct intersection_connection> vc, vw;
    cin>>nc>>nw;
    for (int i = 0; i < nc; ++i) {
        cin>>ic.p.first>>ic.p.second;
        vc.push_back(ic);
    }
    //some trick
    vc.push_back(vc.front());
    for (int i = 0; i < nw; ++i) {
        cin>>ic.p.first>>ic.p.second;
        vw.push_back(ic);
    }
    //some trick
    vw.push_back(vw.front());
    for (auto i = vc.begin(); i != vc.end(); ++i) {
        i->trans = vw.end();
    }
    for (auto i = vw.begin(); i != vw.end(); ++i) {
        i->trans = vc.end();
    }

    //produce intersections
    boost::optional< pair<float, float> > inter;
    list<struct intersection_connection>::iterator insert_point_c, insert_point_w;
    for (auto i = vc.begin(), inext = ++vc.begin(); inext != vc.end(); ++i, ++inext) {
        for (auto j = vw.begin(), jnext = ++vw.begin(); jnext != vw.end(); ++j, ++jnext) {
            while (i->trans != vw.end())
                ++i;
            while (inext->trans != vw.end())
                ++inext;
            while (j->trans != vc.end())
                ++j;
            while (jnext->trans != vc.end())
                ++jnext;

            inter = intersection(i->p, inext->p, j->p, jnext->p);
            if (inter) {
                has_intersection = true;
                ic.p = *inter;
                if (i->p < inext->p) {
                    for (insert_point_c = i; insert_point_c != inext; ++insert_point_c) {
                        if (insert_point_c->p > ic.p) {
                            break;
                        }
                    }
                    insert_point_c = vc.insert(insert_point_c, ic);
                }
                else {
                    for (insert_point_c = i; insert_point_c != inext; ++insert_point_c) {
                        if (insert_point_c->p < ic.p) {
                            break;
                        }
                    }
                    insert_point_c = vc.insert(insert_point_c, ic);
                }
                if (j->p < jnext->p) {
                    for (insert_point_w = j; insert_point_w != jnext; ++insert_point_w) {
                        if (insert_point_w->p > ic.p) {
                            break;
                        }
                    }
                    insert_point_w = vw.insert(insert_point_w, ic);
                }
                else {
                    for (insert_point_w = j; insert_point_w != jnext; ++insert_point_w) {
                        if (insert_point_w->p < ic.p) {
                            break;
                        }
                    }
                    insert_point_w = vw.insert(insert_point_w, ic);
                }
                insert_point_c->trans = insert_point_w;
                insert_point_w->trans = insert_point_c;
            }
        }
    }

    if (has_intersection) {
        vector< vector< pair<float, float> > > res = clip(vc, vw);
        for (auto i = res.begin(); i != res.end(); ++i) {
            for (auto j = i->begin(); j != i->end(); ++j) {
                cout<<'('<<j->first<<','<<j->second<<") ";
            }
            cout<<endl;
        }
    }
    else {
        //window in candidiate
        bool in = false;
        for (auto i = vc.begin(), inext = ++vc.begin(); inext != vc.end(); ++i, ++inext) {
            if (intersection(i->p, inext->p, vw.front().p, make_pair(99999., 99998.))) {
                in = !in;
            }
        }
        if (in) {
            vc.pop_back();
            vw.pop_back();
            for (auto j = vw.begin(); j != vw.end(); ++j) {
                cout<<'('<<j->p.first<<','<<j->p.second<<") ";
            }
            cout<<endl;
            return 0;
        }
        //candidiate in window
        for (auto i = vw.begin(), inext = ++vw.begin(); inext != vw.end(); ++i, ++inext) {
            if (intersection(i->p, inext->p, vc.front().p, make_pair(99999., 99998.))) {
                in = !in;
            }
        }
        if (in) {
            vc.pop_back();
            vw.pop_back();
            for (auto j = vc.begin(); j != vc.end(); ++j) {
                cout<<'('<<j->p.first<<','<<j->p.second<<") ";
            }
            cout<<endl;
            return 0;
        }
        //not overlap
        cout<<"None"<<endl;
    }

    return 0;
}

boost::optional< pair<float, float> > intersection(pair<float, float> a, pair<float, float> b,
        pair<float, float> c, pair<float, float> d)
{
    //calculate area of triangles
    float abc = (a.first - c.first) * (b.second - c.second)
        - (a.second - c.second) * (b.first - c.first);
    float abd = (a.first - d.first) * (b.second - d.second)
        - (a.second - d.second) * (b.first - d.first);
    if (abc * abd >= 0) {
        return boost::optional< pair<float, float> >();
    }

    float cda = (c.first - a.first) * (d.second - a.second)
        - (c.second - a.second) * (d.first - a.first);
    float cdb = cda + abc - abd;
    if (cda * cdb >= 0) {
        return boost::optional< pair<float, float> >();
    }

    float t = cda / (abd - abc);
    return make_pair(a.first + t * (b.first - a.first), a.second + t * (b.second - a.second));
}

vector< vector< pair<float, float> > > clip(list <struct intersection_connection>& vc,
        list <struct intersection_connection>& vw)
{
    vector< vector< pair<float, float> > > res;
    bool start_in_window = false;
    for (auto i = vw.begin(), inext = ++vw.begin(); inext != vw.end(); ++i, ++inext) {
        if (intersection(i->p, inext->p, vc.front().p, make_pair(99999., 99998.))) {
            start_in_window = !start_in_window;
        }
    }
    //deal with trick
    vc.pop_back();
    vw.pop_back();

    if (start_in_window) {
        res.push_back(vector< pair<float, float> >());
        res.back().push_back(vc.begin()->p);
        auto j = vc.begin();
        ++j;
        for (; j != vc.begin(); ) {
            if (j->trans != vc.end() && j->trans != vw.end()) {
                res.back().push_back(j->p);
                j = j->trans;
                j->trans->trans = vw.end();
                j->trans = vw.end();
                ++j;
                if (j == vc.end()) {
                    j = vc.begin();
                }
                if (j == vw.end()) {
                    j = vw.begin();
                }
            }
            else {
                res.back().push_back(j->p);
                ++j;
                if (j == vc.end()) {
                    j = vc.begin();
                }
                if (j == vw.end()) {
                    j = vw.begin();
                }
            }
        }
    }
    for (auto i = vc.begin(); i != vc.end(); ++i) {
        if (i->trans != vw.end()) {
            res.push_back(vector< pair<float, float> >());
            res.back().push_back(i->p);
            auto j = i;
            ++j;
            for (; j != i && j != i->trans; ) {
                if (j->trans != vc.end() && j->trans != vw.end()) {
                    res.back().push_back(j->p);
                    j = j->trans;
                    j->trans->trans = vw.end();
                    j->trans = vw.end();
                    ++j;
                    if (j == vc.end()) {
                        j = vc.begin();
                    }
                    if (j == vw.end()) {
                        j = vw.begin();
                    }
                }
                else {
                    res.back().push_back(j->p);
                    ++j;
                    if (j == vc.end()) {
                        j = vc.begin();
                    }
                    if (j == vw.end()) {
                        j = vw.begin();
                    }
                }
            }
            i->trans->trans = vw.end();
            i->trans = vw.end();
        }
    }
    return res;
}

