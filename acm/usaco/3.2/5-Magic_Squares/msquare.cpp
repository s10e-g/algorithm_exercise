/*
ID: shadowm6
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <map>

using namespace std;

string transform(string&, int);

int main()
{
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");
    string temp_str, target_str;
    for(int i = 0; i < 8; i++){
        fin>>temp_str;
        target_str += temp_str;
    }
    queue<string> bfs_que;
    map<string, string> done_str;
    bfs_que.push("12345678");
    done_str["12345678"] = "";
    while(!bfs_que.empty()){
        for(int i = 0; i < 3; i++){
            temp_str = transform(bfs_que.front(), i);
            if(done_str.find(temp_str) == done_str.end()){
                done_str[temp_str] = done_str[bfs_que.front()] + char('A' + i);
                bfs_que.push(temp_str);
            }
            if(temp_str == target_str){
                fout<<done_str[target_str].length()<<endl<<done_str[target_str]<<endl;
                return 0;
            }
        }
        bfs_que.pop();
    }
    return 0;
}

string transform(string& source_str, int op)
{
    string result_str(source_str);
    switch(op){
        case 0:
            for(int i = 0; i < 8; i++)
                result_str[i] = source_str[7-i];
            return result_str;
        case 1:
            result_str[0] = source_str[3];
            result_str[1] = source_str[0];
            result_str[2] = source_str[1];
            result_str[3] = source_str[2];
            result_str[4] = source_str[5];
            result_str[5] = source_str[6];
            result_str[6] = source_str[7];
            result_str[7] = source_str[4];
            return result_str;
        case 2:
            result_str[1] = source_str[6];
            result_str[2] = source_str[1];
            result_str[5] = source_str[2];
            result_str[6] = source_str[5];
            return result_str;
        default:
            return result_str;
    }
}

