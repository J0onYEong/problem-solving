#include <iostream>
#include <vector>
#include <queue>
#include <cstring> 
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;

vector<pair<int, int>> edges[MAX_N+1];
vector<pair<int, int>> query;

bool visit_node[MAX_N+1];

void input() {
    cin >> n >> m;

    for(int i=0; i<n-1; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    for(int i=0; i<m; i++) {
        int a, b;

        cin >> a >> b;

        query.push_back({a, b});
    }
}

void solution() {
    input();

    for(auto q : query) {
        int a = q.first;
        int b = q.second;

        memset(visit_node, false, sizeof(visit_node));

        queue<pair<int, int>> node_with_cost;

        node_with_cost.push({a, 0});
        visit_node[a] = true;

        while(!node_with_cost.empty()) {
            int now_node = node_with_cost.front().first;
            int now_cost = node_with_cost.front().second;
            node_with_cost.pop();

            if(now_node == b) {
                cout << now_cost << endl;
                break;
            }
            
            for(auto edge : edges[now_node]) {
                int next_node = edge.first;
                int next_cost = now_cost+edge.second;

                if(!visit_node[next_node]) {
                    visit_node[next_node] = true;

                    node_with_cost.push({next_node, next_cost});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
