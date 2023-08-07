#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 3000001;

int N;

int src[max_n];

vector<int> children[max_n];

vector<pair<int, int>> edges;

int depth[max_n];

void input() {
    cin >> N;

    for(int i=1; i<=N-1; i++) {
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
        edges.push_back({a, b});
    }
}

int count_sub_root(int node, int parent, int level) {
    depth[node] = level;
    int& ref = src[node];
    
    for(int child : children[node]) {
        if(child == parent)
            continue;
        ref += count_sub_root(child, node, level+1);
    }
    return 1 + ref;
}

void solution() {
    input();

    memset(src, 0, sizeof(src));
    count_sub_root(1, -1, 0);

    ll whole = N * (N-1) / 2;
    ll result = 0;
    for(auto edge : edges) {
        int tar = depth[edge.first] > depth[edge.second] ? edge.first : edge.second;
        ll x = N - src[tar] - 1;
        result += (whole - x*(x-1)/2);
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
