#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 401
const int INF = 10000000;

using namespace std;

void solution() {
    int V, E;
    int edge[MAX][MAX];

    cin >> V >> E;

    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            edge[i][j] = INF;

     
    for(int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
    }

    for(int k=1; k<=V; k++) 
        for(int i=1; i<=V; i++) 
            for(int j=1; j<=V; j++) 
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
        
                    
    int result = INF;
    for(int i=1; i<=V; i++) 
        result = min(result, edge[i][i]);
    cout << (result == INF ? -1 : result) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
