#include <bits/stdc++.h>

using namespace std;

const int MAX_VOLUME = 324;

struct TREENODE {
    int nVolume, nWeight;
    TREENODE *pChildren, *pBrothers;
};

void Solve(TREENODE *pNodes, int nCost, int nWeight[]);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    TREENODE node[325];
    int n, m, k;
    memset(nodes, 0, sizeof(nodes));
    cin>>n>>m>>k;
    for (int i = 1; i <= n; ++i) {
        cin>>node[i].nWeight;
    }
    return 0;
}

void Solve(TREENODE *pNodes, int nCost, int nWeight[])
{
    int nCnt=0;
    TREENODE *NodesPt[MAX_VOLUME];

    for (TREENODE *p=pNodes->pChildren; p!=NULL; p=p->pBrothers)
        NodesPt[nCnt++]=p;
    for (int i=0; i<=nCost; i++)
        nWeight[i]=0;
    nCost=(pNodes->nWeight==0 ? nCost : nCost-pNodes->nVolume);
    for (int i=0; i<nCnt; i++) {
        int w[MAX_VOLUME+1];

        Solve(NodesPt[i], nCost, w);
        for (int j=nCost; j>=NodesPt[i]->nVolume; j--) {
            for (int k=NodesPt[i]->nVolume; k<=j; k++)
                nWeight[j]=max(nWeight[j], nWeight[j-k]+w[k]);
        }
    }
    if (pNodes->nWeight==0)
        return;
    for (int i=nCost+pNodes->nVolume; i>=pNodes->nVolume; i--)
        nWeight[i]=nWeight[i-pNodes->nVolume]+pNodes->nWeight;
}
