#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int>> nd[100];
vector<int> d, v;
int n, m, ds;

void dijkstra(int s) {
    d[s] = 0;

    for(int i = 1; i <= n; i++)
    {
        int par, minWei = 1e9;
        for(int j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < minWei) {
                par = j;
                minWei = d[j];
            }
        }
        v[par] = 1;

        for (auto p : nd[par]) {
            int cld = p.first;
            int wei = p.second;
            if (d[cld] > d[par] + wei)
                d[cld] = d[par] + wei;
        }
    }
}


vector<int> dd[100];

void floyd_warshall()
{
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dd[i][j] > dd[i][k] + dd[k][j])
                    dd[i][j] = dd[i][k] + dd[k][j];
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    d.resize(n + 1,1e9);
    v.resize(n + 1);
    for(int i=1; i<=n; i++) {
        dd[i].resize(n + 1, 1e9);
        dd[i][i] = 0;
    }

    int s, e, w;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        nd[s].push_back({e, w});
        dd[s][e] = w;
        dd[e][s] = w;
    }

    cin >> ds;

    dijkstra(ds);
    printf("\ndijkstra(from %d): \n", ds);
    for (int k = 1; k <= n; k++) {
        if (d[k] != 1e9)
            printf("%3d ", d[k]);
        else
            printf("NaN ");
    }

    floyd_warshall();
    cout << endl << endl << "floyd-warshall: " << endl;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dd[i][j] != 1e9)
                printf("%3d ", dd[i][j]);
            else
                printf("NaN ");
        }
        cout << endl;
    }
}
