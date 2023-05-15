#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define INF 80000

using namespace std;



void solution() {
    int n, m;
    cin >> n >> m;
    int graph[501][501];

    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++)
            graph[i][j] = INF;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;           
    }

    for(int m_node=1; m_node<=n; m_node++) {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) {
                int temp = graph[i][m_node]+graph[m_node][j];
                if(temp < graph[i][j])
                    graph[i][j] = temp;
            }
    }

    int result = 0;
    for(int i=1; i<=n; i++) {
        int temp = 0;
        for(int j=1; j<=n; j++) {
            if(graph[i][j]!=INF || graph[j][i]!=INF)
                temp++;
        }
        if(temp == n-1)
            result++;
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
