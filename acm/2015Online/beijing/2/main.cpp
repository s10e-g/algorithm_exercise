#include <bits/stdc++.h>

using namespace std;

inline bool lower(char);
int main()
{
    ios::sync_with_stdio(false);
    int T;
    unsigned int m;
    bool cmode, omode;
    string in, out, cb;
    cin>>T;
    for (int t = 0; t < T; ++t) {
        cb.clear();
        out.clear();
        cmode = false;
        omode = false;
        cin>>m>>in;
        auto caret = out.begin();   //real caret is in front of this iterator
        string::iterator copy_iter;
        for (auto i = in.begin(); i != in.end(); ++i) {
            if(lower(*i)) {
                if (omode) {
                    //overwrite mode
                    if (caret == out.end()) {
                        if (out.size() >= m)
                            continue;
                        out.push_back(*i);
                        caret = out.end();
                    }
                    else {
                        *caret = *i;
                        ++caret;
                    }
                }
                else {
                    if (out.size() >= m)
                        continue;
                    //insert mode
                    if (caret == out.end()) {
                        out.push_back(*i);
                        caret = out.end();
                    }
                    else {
                        caret = out.insert(caret, *i);
                        ++caret;
                    }
                }
                cmode = false;
            }
            else {
                switch (*i) {
                    case 'L':
                        if (caret != out.begin())
                            --caret;
                        break;
                    case 'R':
                        if (caret != out.end())
                            ++caret;
                        break;
                    case 'S':
                        omode = !omode;
                        cmode = false;
                        break;
                    case 'D':
                        if (!cmode) {
                            if (caret != out.end())
                                caret = out.erase(caret);
                        }
                        else {
                            cmode = false;
                            caret = out.erase(min(copy_iter, caret), max(copy_iter, caret));
                        }
                        break;
                    case 'B':
                        if (caret != out.begin()) {
                            --caret;
                            caret = out.erase(caret);
                        }
                        cmode = false;
                        break;
                    case 'C':
                        if (!cmode) {
                            cmode = true;
                            copy_iter = caret;
                        }
                        else {
                            cmode = false;
                            cb = string(min(copy_iter, caret), max(copy_iter, caret));
                        }
                        break;
                    case 'V':
                        cmode = false;
                        if (omode) {
                            if (cb.size() > (unsigned int)(out.end()-caret) && 
                                    out.size() + (cb.size() - (out.end()-caret)) > m)
                                break;
                            int dist = caret - out.begin();
                            out.replace(caret, min(caret+cb.size(), out.end()), cb);
                            caret = out.begin() + dist;
                            caret += cb.size();
                        }
                        else {
                            if (out.size() + cb.size() > m)
                                break;
                            int dist = caret - out.begin();
                            out.insert(caret, cb.begin(), cb.end());
                            caret = out.begin() + dist;
                            caret += cb.size();
                        }
                        break;
                }
            }
        }
        if (out.size() > 0)
            cout<<out<<endl;
        else
            cout<<"NOTHING"<<endl;
    }
    return 0;
}

inline bool lower(char c)
{
    return ('a'<=c&&c<='z')?true:false;
}

