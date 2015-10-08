#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, in;
    bool in_for, in_f, enter, in_func, in_seg;
    cin>>T;
    cin.get();
    string source, s;
    for (int k = 1; k <= T; ++k) {
        cout<<"Case #"<<k<<":"<<endl;
        getline(cin, source);
        s.clear();
        in_f = false;
        for (auto c = source.begin(); c != source.end(); ++c) {
            if (*c == '\\') {
                s.push_back(*c);
                ++c;
                s.push_back(*c);
            }
            else {
                if (*c == '"')
                    in_f = !in_f;
                if (in_f) {
                    s.push_back(*c);
                }
                else if (*c != ' ') {
                    s.push_back(*c);
                }
            }
        }
        auto c = s.begin();
        in = 0;
        in_for = false;
        in_f = false;
        enter = true;
        in_func = false;
        in_seg = false;
        //header
        while (*c == '#') {
            cout<<"#include ";
            while (*c != '<') {
                ++c;
            }
            cout<<'<';
            ++c;
            while (*c != '>') {
                cout<<*c;
                ++c;
            }
            cout<<'>'<<endl;
            ++c;
        }
        if (s.front() == '#')
            cout<<endl;

        for (; c != s.end(); ++c) {
            if (*c == '\\') {
                cout<<*c;
                ++c;
                cout<<*c;
                enter = false;
            }
            else {
                if (*c == '"') {
                    in_f = !in_f;
                }
                if (in_f) {
                    enter = false;
                    cout<<*c;
                }
                else {
                    switch (*c) {
                        case '(':
                            if (in_func)
                                in_seg = true;
                                enter = true;
                            cout<<'(';
                            break;
                        case 'i':
                            if (enter && *(c+1) == 'n' && *(c+2) == 't' &&
                                    *(c+3) != 'f') {
                                for (int i = 0; *(c+i) != ';'; ++i) {
                                    if (*(c+i) == '+' || *(c+i) == '-' || *(c+i) == '*' ||
                                            *(c+i) == '/' || *(c+i) == '=' || *(c+i) == '>' ||
                                            *(c+i) == '<' || *(c+i) == '!')
                                        goto output;
                                }
                                cout<<"int ";
                                c += 2;
                                enter = false;
                                in_func = true;
                            }
                            else {
                                cout<<'i';
                                enter = false;
                            }
                            break;
                        case 'd':
                            if (enter && *(c+1) == 'o' && *(c+2) == 'u' &&
                                    *(c+3) == 'b' && *(c+4) == 'l' && *(c+5) == 'e') {
                                for (int i = 0; *(c+i) != ';'; ++i) {
                                    if (*(c+i) == '+' || *(c+i) == '-' || *(c+i) == '*' ||
                                            *(c+i) == '/' || *(c+i) == '=' || *(c+i) == '>' ||
                                            *(c+i) == '<' || *(c+i) == '!')
                                        goto output;
                                }
                                cout<<"double ";
                                c += 5;
                                enter = false;
                                in_func = true;
                            }
                            else {
                                cout<<'d';
                                enter = false;
                            }
                            break;
                        case 'b':
                            if (enter && *(c+1) == 'o' && *(c+2) == 'o' &&
                                    *(c+3) == 'l') {
                                for (int i = 0; *(c+i) != ';'; ++i) {
                                    if (*(c+i) == '+' || *(c+i) == '-' || *(c+i) == '*' ||
                                            *(c+i) == '/' || *(c+i) == '=' || *(c+i) == '>' ||
                                            *(c+i) == '<' || *(c+i) == '!')
                                        goto output;
                                }
                                cout<<"bool ";
                                c += 3;
                                enter = false;
                                in_func = true;
                            }
                            else {
                                cout<<'b';
                                enter = false;
                            }
                            break;
                        case 'c':
                            if (enter && *(c+1) == 'h' && *(c+2) == 'a' &&
                                    *(c+3) == 'r') {
                                for (int i = 0; *(c+i) != ';'; ++i) {
                                    if (*(c+i) == '+' || *(c+i) == '-' || *(c+i) == '*' ||
                                            *(c+i) == '/' || *(c+i) == '=' || *(c+i) == '>' ||
                                            *(c+i) == '<' || *(c+i) == '!')
                                        goto output;
                                }
                                cout<<"char ";
                                enter = false;
                                in_func = true;
                                c += 3;
                            }
                            else {
                                cout<<'c';
                                enter = false;
                            }
                            break;
                        case 'v':
                            if (enter && *(c+1) == 'o' && *(c+2) == 'i' && *(c+3) == 'd') {
                                for (int i = 0; *(c+i) != ';'; ++i) {
                                    if (*(c+i) == '+' || *(c+i) == '-' || *(c+i) == '*' ||
                                            *(c+i) == '/' || *(c+i) == '=' || *(c+i) == '>' ||
                                            *(c+i) == '<' || *(c+i) == '!')
                                        goto output;
                                }
                                cout<<"void ";
                                enter = false;
                                in_func = true;
                                c += 3;
                            }
                            else {
                                cout<<'v';
                                enter = false;
                            }
                            break;
                        case 'f':
                            if (*(c+1) == 'o' && *(c+2) == 'r' && *(c+3) == '(') {
                                in_for = true;
                            }
                            cout<<'f';
                            enter = false;
                            break;
                        case ',':
                            cout<<", ";
                            enter = in_seg;
                            break;
                        case ')':
                            in_func = false;
                            in_for = false;
                            in_seg = false;
                            cout<<*c;
                            enter = false;
                            ++c;
                            if (*c == '{') {
                                cout<<endl;
                                enter = true;
                                for (int i = 0; i < in; ++i) {
                                    cout<<"  ";
                                }
                                cout<<'{'<<endl;
                                enter = true;
                                ++in;
                                if (*(c+1) == '}') {
                                    for (int i = 0; i < in-1; ++i) {
                                        cout<<"  ";
                                    }
                                }
                                else {
                                    for (int i = 0; i < in; ++i) {
                                        cout<<"  ";
                                    }
                                }
                            }
                            else {
                                --c;
                            }
                            break;
                        case ';':
                            in_func = false;
                            in_seg = false;
                            if (in_for) {
                                cout<<"; ";
                                enter = false;
                            }
                            else {
                                cout<<*c<<endl;
                                enter = true;
                                if (*(c+1) == '}') {
                                    for (int i = 0; i < in-1; ++i) {
                                        cout<<"  ";
                                    }
                                }
                                else {
                                    for (int i = 0; i < in; ++i) {
                                        cout<<"  ";
                                    }
                                }
                            }
                            break;
                        case '}':
                            cout<<*c<<endl;
                            enter = true;
                            --in;
                            if (*(c+1) == '}') {
                                for (int i = 0; i < in-1; ++i) {
                                    cout<<"  ";
                                }
                            }
                            else {
                                for (int i = 0; i < in; ++i) {
                                    cout<<"  ";
                                }
                            }
                            break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                            cout<<' '<<*c<<' ';
                            enter = false;
                            break;
                        case '=':
                        case '!':
                        case '<':
                        case '>':
                            if (*(c+1) == '=') {
                                cout<<' '<<*c<<"= ";
                                enter = false;
                            }
                            else {
                                cout<<' '<<*c<<' ';
                                enter = false;
                            }
                            break;
                        default:
output:
                            cout<<*c;
                            enter = false;
                            break;
                    }
                }
            }
        }
    }
    return 0;
}

