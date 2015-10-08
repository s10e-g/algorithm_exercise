#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int xa, xb, xc, ya, yb, yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    if (ya > xa)
        swap(xa, ya);
    if (yb > xb)
        swap(xb, yb);
    if (yc > xc)
        swap(xc, yc);
    //---
    //---
    //---
    if ((ya+yb+yc)==xa && xa == xb && xb == xc) {
        cout<<xa<<endl;
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'B';
            }
            cout<<endl;
        }
        for (int i = 0; i < yc; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //abc
    //---
    //| |
    if (xa == (yb+yc) && xa == (ya+xb) && xb == xc) {
        cout<<xa<<endl;
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        for (int i = 0; i < xb; ++i) {
            for (int j = 0; j < yb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < yc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //- -
    if (xa == (xb+xc) && xa == (ya+yb) && yb == yc) {
        cout<<xa<<endl;
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //- |
    if (xa == (xb+yc) && xa == (ya+yb) && yb == xc) {
        cout<<xa<<endl;
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < yc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //| -
    if (xa == (yb+xc) && xa == (ya+xb) && xb == yc) {
        cout<<xa<<endl;
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        for (int i = 0; i < xb; ++i) {
            for (int j = 0; j < yb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //bac
    //---
    //| |
    if (xb == (ya+yc) && xb == (yb+xa) && xa == xc) {
        cout<<xb<<endl;
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            cout<<endl;
        }
        for (int i = 0; i < xa; ++i) {
            for (int j = 0; j < ya; ++j) {
                cout<<'A';
            }
            for (int j = 0; j < yc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //- -
    if (xb == (xa+xc) && xb == (yb+ya) && ya == yc) {
        cout<<xb<<endl;
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            cout<<endl;
        }
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //- |
    if (xb == (xa+yc) && xb == (yb+ya) && ya == xc) {
        cout<<xb<<endl;
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            cout<<endl;
        }
        for (int i = 0; i < ya; ++i) {
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            for (int j = 0; j < yc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //| -
    if (xb == (ya+xc) && xb == (yb+xa) && xa == yc) {
        cout<<xb<<endl;
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            cout<<endl;
        }
        for (int i = 0; i < xa; ++i) {
            for (int j = 0; j < ya; ++j) {
                cout<<'A';
            }
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        return 0;
    }
    //cba
    //---
    //| |
    if (xc == (yb+ya) && xc == (yc+xb) && xb == xa) {
        cout<<xc<<endl;
        for (int i = 0; i < yc; ++i) {
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        for (int i = 0; i < xb; ++i) {
            for (int j = 0; j < yb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < ya; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //- -
    if (xc == (xb+xa) && xc == (yc+yb) && yb == ya) {
        cout<<xc<<endl;
        for (int i = 0; i < yc; ++i) {
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //- |
    if (xc == (xb+ya) && xc == (yc+yb) && yb == xa) {
        cout<<xc<<endl;
        for (int i = 0; i < yc; ++i) {
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        for (int i = 0; i < yb; ++i) {
            for (int j = 0; j < xb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < ya; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        return 0;
    }
    //---
    //| -
    if (xc == (yb+xa) && xc == (yc+xb) && xb == ya) {
        cout<<xc<<endl;
        for (int i = 0; i < yc; ++i) {
            for (int j = 0; j < xc; ++j) {
                cout<<'C';
            }
            cout<<endl;
        }
        for (int i = 0; i < xb; ++i) {
            for (int j = 0; j < yb; ++j) {
                cout<<'B';
            }
            for (int j = 0; j < xa; ++j) {
                cout<<'A';
            }
            cout<<endl;
        }
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}

