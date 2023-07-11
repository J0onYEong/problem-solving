#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int max_n = 10001;

int n, result;

int parent[max_n];
int ball_count[max_n];

vector<int> edge[max_n];


void input() {
    memset(parent, 0, sizeof(parent));
    memset(ball_count, 0, sizeof(ball_count));
    for(int i=1; i<=n; i++)
        edge[i].clear();

    for(int i=1; i<=n; i++) {
        int node, nc;

        cin >> node >> ball_count[node] >> nc;

        for(int j=0; j<nc; j++) {
            int child;
            cin >> child;
            parent[child] = node;
            edge[node].push_back(child);
        }
    }
}

int find_root() {
    for(int i=1; i<=n; i++) 
        if(parent[i]==0)
            return i;
    
    return 0;
}

void dfs(int node) {
    for(int child : edge[node]) 
        dfs(child);

    int gap = ball_count[node]-1;
    ball_count[parent[node]] += gap;
    result+=abs(gap);
}


void solution() {
    while(cin >> n, n != 0) {
        input();
        int root = find_root();
        result = 0;
        dfs(root);
        cout << result << endl;;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
