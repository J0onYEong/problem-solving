#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int max_n = 300001;

const int max_p = 15;

int rtn[max_n];

int ancestor[max_n][max_p];

vector<int> edge[max_n];


int N;

void to_root(int node, int value, int parent) {
    rtn[node] = value;

    for(int child : edge[node]) {
        if(child != parent) {
            ancestor[child][0] = node;
            to_root(child, value+1, node);
        }
    }
}

int findLCA(int node1, int node2) {
    int d1 = rtn[node1];
    int d2 = rtn[node2];

    if(d1 < d2)
        swap(node1, node2);

    for(int i=(max_p-1); i >= 0; i--) {
        int temp = ancestor[node1][i];
        if(rtn[temp] >= rtn[node2])
            node1 = temp;
    }

    if(node1 == node2)
        return node1;

    int lca;
    for(int i=(max_p-1); i >= 0; i--) {
        if(ancestor[node1][i] != ancestor[node2][i]) {
            node1 = ancestor[node1][i];
            node2 = ancestor[node2][i];
        }
        lca = ancestor[node1][i];
    }
    return lca;
}

void input() {
    cin >> N;

    for(int i=1; i<=N-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

void solution() {
    input();

    memset(ancestor, 0, sizeof(ancestor));
    //1. 1번루트까지의 거리 + 첫번째 조상 설정
    //+ 1번루트까지의 거리는 곧 depth를 의미함을 인지하자
    to_root(1, 0, -1);
    //2. ancester배열을 완성한다.
    for(int i=1; i<max_p; i++)
        for(int node=2; node<=N; node++)
            ancestor[node][i] = ancestor[ancestor[node][i-1]][i-1];
    
    //3. 두노드의 LCA를 찾으면서 오솔길 수를 알아낸다.
    int result = 0;
    for(int i=1; i<=N; i++) {
        for(int j=i+1; j<=N; j++) {
            int t = result;
            int lca = findLCA(i, j);
            result += rtn[i] - rtn[lca];
            result += rtn[j] - rtn[lca];
            result += rtn[lca];
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
