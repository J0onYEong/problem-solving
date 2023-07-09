#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define edge pair<int, int> // 목적지, 가중치

using namespace std;

const int max_n = 100001;

vector<edge> edges[max_n];
int N;

bool visited[max_n];

edge dfs(int node) {
    edge result = {node, 0};
 
    for(auto e : edges[node]) {
        if(!visited[e.first]) {
            visited[e.first] = true;
            edge temp = dfs(e.first);
            temp.second += e.second;
            if(temp.second > result.second)
                result = temp;
            visited[e.first] = false;
        }
    }

    return result;
}

void solution() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int start, end, value;
        cin >> start;
        
        while (true)
        {
            cin >> end;

            if(end == -1)
                break;
            
            cin >> value;

            edges[start].push_back({end, value});
        }
    }
    memset(visited, false, sizeof(bool) * max_n);

    visited[1] = true;
    edge temp = dfs(1);
    visited[1] = false;

    visited[temp.first] = true;
    edge result = dfs(temp.first);
    visited[temp.first] = false;
    cout << result.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
