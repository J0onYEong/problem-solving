#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX = 32001;

class Node {
public:
vector<int> children;
};

int N, M;
Node nodes[MAX];
bool visited[MAX];
vector<int> result;

void recursive(int node) {
    for(auto child : nodes[node].children)
        if(!visited[child])
            recursive(child); 
    
    visited[node] = true;
    result.push_back(node);
}

void solution() {
    cin >> N >> M;
    memset(visited, false, sizeof(bool)*MAX);

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].children.push_back(b);
    }

    for(int i=1; i<=N; i++)
        if(!visited[i]) 
            recursive(i);
   
   for(int i=N-1; i>=0; i--) 
        cout << result[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
