#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#define ll long long
#define endl "\n"

using namespace std;

const int max_vertice_count = 20000;

int K, V, E;

vector<vector<int>> edge;

void input() {

    cin >> V >> E;

    edge = vector<vector<int>>(V);

    for(int i=0; i<E; i++) {

        int u, v;

        cin >> u >> v;

        u--;
        v--;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

void solution() {
    cin >> K;

    for(int i=0; i<K; i++) {

        input();

        // 0 - 방문 x, 1, 2
        vector<short> isVisited = vector<short>(V, 0);
        
        for(int p=0; p<V; p++) {

            if(isVisited[p]) { continue; }

            queue<int> q;

            q.push(p);
            isVisited[p] = 1;

            while(!q.empty()) {

                int c = q.front();
                q.pop();

                short next_party = (isVisited[c] == 1) ? 2 : 1;

                for(int n : edge[c]) {

                    if(!isVisited[n]) {

                        isVisited[n] = next_party;
                    
                        q.push(n);
                    }
                }
            }
        }

        bool flag = false;
        for(int k=0; k<V; k++) {

            for(int child : edge[k]) {

                if(isVisited[k] == isVisited[child]) {
                    flag = true;
                    cout << "NO" << endl;

                    break;
                }
            }

            if(flag) { break; }
        }

        if(flag) { continue; }
    
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
