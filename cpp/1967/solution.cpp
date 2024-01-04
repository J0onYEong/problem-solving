#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

const short MAX_N = 10000;

short n;
vector<pair<short, short>> edge[MAX_N+1];

void input() {
    
    cin >> n;

    for(int i=0; i<n-1; i++) {

        short p, c, w;

        cin >> p >> c >> w;

        edge[p].push_back({c, w});
        edge[c].push_back({p, w}); 

    }

}

pair<short, short> bfs(short node) {

    bool visited_node[MAX_N+1];

    for(int i=1; i<=n; i++)
        visited_node[i] = false;

    visited_node[node] = true;

    // node, accum
    queue<pair<short, short>> q;

    q.push({node, 0});

    short des_node = 0;
    short max_accum = 0;

    while(!q.empty()) {

        short current_node = q.front().first;
        short accum = q.front().second;

        q.pop();

        bool is_leaf = true;
        
        for(auto e : edge[current_node]) {
            
            short next_node = e.first;
            short weight = e.second;

            if(!visited_node[next_node]) {

                visited_node[next_node] = true;

                is_leaf = false;

                q.push({next_node, accum + weight});

            }

        }

        if(is_leaf) {

            if(max_accum < accum) {

                des_node = current_node;
                max_accum = accum;

            }

        }

    }

    return {des_node, max_accum};

}

void solution() {
    input();

    pair<short, short> first = bfs(1);
    
    cout << bfs(first.first).second << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
