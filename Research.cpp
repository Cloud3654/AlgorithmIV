// dfs
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector <pair<int,int>> cld;
    bool visit;
};

Node nd[10];
int n, S=1, D=7, minPath = 1e9;


void dfs(int idx, int sumWei)
{
    if(idx == D) {
        minPath = min(minPath,sumWei);
        return;
    }

    for(auto p : nd[idx].cld)
    {
        if(nd[p.first].visit == false) {
            nd[p.first].visit = true;
            dfs(p.first, sumWei+p.second);
            nd[p.first].visit = false;
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for (int sp, ep, w; m--; ) {
        cin >> sp >> ep >> w;
        nd[sp].cld.push_back({ep,w});
    }

    nd[1].visit = true;
    dfs(S,0);
    cout << minPath;
}


