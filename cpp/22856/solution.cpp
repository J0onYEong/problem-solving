#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX = 100001;

class Vertex {
public:
    int left;
    int right;
    
    void InitMembers(int l, int r);
};
void Vertex::InitMembers(int l, int r)
{
    left = l;
    right = r;
}

int N;
Vertex vertice[MAX];
int ans = 0;
int result = -1;
int last_node = -1;

int finEndNode(int node) {
    if(vertice[node].right != -1)
        return finEndNode(vertice[node].right);
    return node;
}

void dfs(int node) {
    if(vertice[node].left != -1) {
        ans++;
        dfs(vertice[node].left);
    }
    
    if(vertice[node].right != -1) {
        ans++;
        dfs(vertice[node].right);
    }

    //마지막 노드인지 확인 후 부모로 돌아감
    if(node == last_node) {
        result = ans;
    } else {
        ans++;
    }
} 


void solution() {    
    cin >> N;
    for(int i=1; i<=N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vertice[a].InitMembers(b, c);
    }
    last_node = finEndNode(1);
    dfs(1);
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
