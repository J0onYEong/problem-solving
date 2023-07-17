#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_node = 100001;

int N, M, K;

vector<int> edge[max_node];
vector<pair<int, int>> test_cases;

int depth[max_node];

int ancestor[max_node][20];

void set_immediate_ac(int node, int level, int parent = 0) {
    depth[node] = level;

    //set immediate parent
    for(int child : edge[node]) {
        if(child != parent) {
            ancestor[child][0] = node;
            set_immediate_ac(child, level+1, node);
        }
    }
}

void set_k_ancestor() {
    for(int k=1; k<=K; k++)
        for(int node=1; node<=N; node++)
            ancestor[node][k] = ancestor[ancestor[node][k-1]][k-1];
}

int find_lca(int a, int b) {
    //always make 'a' to climb tree
    if(depth[a] < depth[b]) {
        int t = a;
        a = b;
        b = t;
    }
    for(int k=K; k>=0; k--) {
        if(depth[ancestor[a][k]] >= depth[b]) {
            a = ancestor[a][k];
        }
    }
    //이제 a와 b는 같은 레벨에 존재한다.

    if(a == b)
        return a;

    int lca = a;
    for(int k=K; k>=0; k--) {
        if(ancestor[a][k] != ancestor[b][k]) {
            a = ancestor[a][k];
            b = ancestor[b][k];
        }
        lca = ancestor[a][k];
    }
    return lca;
}


void input() {
    cin >> N;

    int a, b;
    for(int i=1; i<=N-1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    cin >> M;

    for(int i=1; i<=M; i++) {
        cin >> a >> b;
        test_cases.push_back({a, b});
    }
}

void solution() {
    input();

    K = 19;

    for(int i=0; i<20; i++)
        memset(ancestor[i], 0, sizeof(int) * max_node);
    memset(depth, 0, sizeof(int) * max_node);

    set_immediate_ac(1, 1);
    set_k_ancestor();

    for(auto t : test_cases)
        cout << find_lca(t.first, t.second) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
