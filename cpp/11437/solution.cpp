#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int max_N = 50001;
int N, M;

vector<int> edge[max_N];

vector<pair<int, int>> test_case;

int parent[max_N];

int visited[max_N];

int node_layer[max_N];

void set_prarent(int node, int layer) {
    visited[node] = true;
    node_layer[node] = layer;

    for(int child : edge[node]) {
        if(!visited[child]) {
            parent[child]=node;
            set_prarent(child, layer+1);
        }
    }
}

int find_mutual_parent(int n1, int n2) {
    int p1=n1;
    int p2=n2;

    while(p1!=1 && p2!=1) {
        int l1 = node_layer[p1];
        int l2 = node_layer[p2];
        if(l1 == l2) {
            if(p1 == p2)
                return p1;
            p1 = parent[p1];
        } else if(l1 > l2)
            p1 = parent[p1];
        else 
            p2 = parent[p2];
    }    
    return 1;
}

void input() {
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> M;

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        test_case.push_back({a, b});
    }
}

void solution() {
    input();
    memset(visited, false, sizeof(visited));

    set_prarent(1, 0);

    for(auto t : test_case)
        cout << find_mutual_parent(t.first, t.second) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
