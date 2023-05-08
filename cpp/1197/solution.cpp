#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define edge pair<int, int>

using namespace std;

int find_root(int parent[], int node);

bool union_node(int parent[], int node1, int node2) {
    int r1 = find_root(parent, node1);
    int r2 = find_root(parent, node2);
    if(r1 != r2) {
        if(r1 < r2) parent[r2] = r1;
        else parent[r1] = r2;
        return true;
    }
    return false;
}

int find_root(int parent[], int node) {
    if(parent[node] == node) 
        return node;
    return parent[node] = find_root(parent, parent[node]);
}

void solution() {
    int v, e;
    cin >> v >> e;

    vector<pair<int, edge> > edges;

    for(int i=0; i<e; i++) {
        edge temp;
        int value;
        cin >> temp.first >> temp.second >> value;
        edges.push_back(make_pair(value, temp));
    }

    sort(edges.begin(), edges.end());

    ll result = 0;
    int edgeCount = 0;
    int parent[10001];
    for(int i=1; i<=v; i++) 
        parent[i] = i;

    for(auto e : edges) {
        int n1 = e.second.first;
        int n2 = e.second.second;
        if(union_node(parent, n1, n2)) {
            result+=e.first;
            edgeCount++;
        }
        if(edgeCount == v-1)
            break;
    }
    
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
