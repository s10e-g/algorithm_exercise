/*
ID: shadowm6
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

struct offer_struct{
    vector< pair<int, int> > product;   //<product, num>
    int price;
};

int main()
{
    int s, n, k, c, b; 

    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin>>s;

    vector<offer_struct> raw_offer(s), offer;
    vector< pair<int, int> > product(5);
    int min_price[6][6][6][6][6];
    memset(min_price, 0x7F, sizeof(min_price));

    for(int i = 0; i < s; i++){
        fin>>n;
        for(int j = 0; j < n; j++){
            fin>>c>>k;
            raw_offer[i].product.push_back(make_pair(c, k));
        }
        fin>>raw_offer[i].price;
    }
    
    fin>>b;
    raw_offer.resize(s + b);

    for(int i = 0; i < b; i++){
        fin>>product[i].first>>product[i].second>>raw_offer[s+i].price;
        raw_offer[s+i].product.push_back(make_pair(product[i].first, 1));
    }

    for(vector<offer_struct>::iterator i = raw_offer.begin(); i != raw_offer.end(); i++){
        bool available = true;
        for(vector< pair<int, int> >::iterator j = i->product.begin();
                j != i->product.end(); j++){
            bool found = false;
            for(int k = 0; k < 5; k++){
                if(product[k].first == j->first){
                    found = true;
                    break;
                }
            }
            if(!found)
                available = false;
        }
        if(available){
            offer.push_back(*i);
            offer.back().product.clear();
            offer.back().product.resize(5);
            for(vector< pair<int, int> >::iterator j = i->product.begin();
                    j != i->product.end(); j++){
                for(int k = 0; k < 5; k++){
                    if(product[k].first == j->first){
                        offer.back().product[k] = make_pair(j->first, j->second);
                    }
                }
            }
        }
    }
/*
    for(auto i : offer){
        for(auto j : i.product)
            cout<<j.first<<' '<<j.second<<endl;
        cout<<i.price<<endl;
    }
*/

    min_price[0][0][0][0][0] = 0;
    for(int i = 0; i <= product[0].second; i++)
        for(int j = 0; j <= product[1].second; j++)
            for(int k = 0; k <= product[2].second; k++)
                for(int l = 0; l <= product[3].second; l++)
                    for(int m = 0; m <= product [4].second; m++)
                        for(vector<offer_struct>::iterator iter = offer.begin(); 
                                iter != offer.end(); iter++){
                            if(i >= iter->product[0].second &&
                                    j >= iter->product[1].second &&
                                    k >= iter->product[2].second &&
                                    l >= iter->product[3].second &&
                                    m >= iter->product[4].second)
                                if(min_price[i - iter->product[0].second]
                                        [j - iter->product[1].second]
                                        [k - iter->product[2].second]
                                        [l - iter->product[3].second]
                                        [m - iter->product[4].second]
                                        + iter->price < min_price[i][j][k][l][m]){
                                    min_price[i][j][k][l][m] =
                                        min_price[i - iter->product[0].second]
                                        [j - iter->product[1].second]
                                        [k - iter->product[2].second]
                                        [l - iter->product[3].second]
                                        [m - iter->product[4].second]
                                        + iter->price;
                                    /*
                                    cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<m<<endl
                                        <<distance(offer.begin(), iter)<<endl
                                        <<min_price[i][j][k][l][m]<<endl;
                                        */
                                }
                        }

    fout<<min_price[product[0].second]
        [product[1].second]
        [product[2].second]
        [product[3].second]
        [product[4].second]<<endl;
    return 0;
}

