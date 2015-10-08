/*
ID: shadowm6
PROG: fence4
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

typedef pair<int, int> point_rect;
typedef pair< pair<int, int>, pair<int, int> > line;
typedef pair<double, int> point_polar;

const double PI = 3.14159265358979323846;

inline bool cross(line, line, bool);

inline double crossproduct(point_rect, point_rect, point_rect);

inline bool greater_arg(double a, double b)
{
    return (a > b) ^ (a - b > PI);
}

int main()
{
    ifstream fin("fence4.in");
    ofstream fout("fence4.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n, ans_num = 0;
    cin>>n;

    point_rect ob;
    vector<point_rect> vertex(n+1);
    vector< complex<double> > vertex_ob(n+1);
    vector<bool> vertex_visible(n+1);

    vertex_visible.reserve(2000000000);

    cin>>ob.first>>ob.second;

    for (int i = 0; i <= n; ++i) {
        if (i == n) {
            vertex[i] = vertex[0];
            vertex_ob[i] = vertex_ob[0];
        } else {
            cin>>vertex[i].first>>vertex[i].second;

            vertex_ob[i].real(vertex[i].first - ob.first);
            vertex_ob[i].imag(vertex[i].second - ob.second);

            cout<<arg(vertex_ob[i])<<endl;
        }

        for (int j = 1; j < i; ++j)
            if (cross(make_pair(vertex[i], vertex[i-1]),
                        make_pair(vertex[j], vertex[j-1]), true)) {
                cout<<"NOFENCE"<<endl;
                return 0;
            }
    }

    for (int i = 0; i < n; ++i) {
        double max_dis = max(norm(vertex_ob[i]), norm(vertex_ob[i+1]));
        double min_arg;
        double max_arg;
        if (greater_arg(arg(vertex_ob[i]), arg(vertex_ob[i+1]))) {
            min_arg = arg(vertex_ob[i+1]);
            max_arg = arg(vertex_ob[i]);
        } else {
            min_arg = arg(vertex_ob[i]);
            max_arg = arg(vertex_ob[i+1]);
        }

        for (int j = 2; j < n - 1; ++j) {
            if (norm(vertex_ob[(i + j) % n]) < max_dis) {
                if (greater_arg(arg(vertex_ob[(i + j) % n]),
                            arg(vertex_ob[(i + j + 1) % n]))) {
                    if (greater_arg(arg(vertex_ob[(i + j) % n]), min_arg))
                        min_arg = arg(vertex_ob[(i + j) % n]);
                } else {
                    if (greater_arg(max_arg, arg(vertex_ob[(i + j) % n])))
                        max_arg = arg(vertex_ob[(i + j + 1) % n]);
                }
            }
        }
        if (max_arg > min_arg) {
            vertex_visible[i] = true;
            ans_num++;
        }
    }

    cout<<ans_num<<endl;
    for (int i = 0; i < n; i++) {
        if (vertex_visible[i])
            cout<<vertex[i].first<<' '<<vertex[i].second<<' '
                <<vertex[(i+1)%n].first<<' '<<vertex[(i+1)%n].second<<endl;
    }

    return 0;
}

inline bool cross(line A, line B, bool strict)
{
    double A1 = crossproduct(A.first, A.second, B.first),
           A2 = crossproduct(A.first, A.second, B.second),
           B1 = crossproduct(B.first, B.second, A.first),
           B2 = crossproduct(B.first, B.second, A.second);

    if ((A1==0 || A2==0) && !strict) return true;

    if (A1*A2<0 && B2*B1<0) return true;

    return false;
}

inline double crossproduct(point_rect start, point_rect U, point_rect V)
{
    double Ux = U.first - start.first, Uy = U.second - start.second,
           Vx = V.first - start.first, Vy = V.second - start.second;
    return (Ux * Vy - Uy * Vx);
}

