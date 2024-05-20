#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define ll long long
#define endl "\n"

using namespace std;

int N, M;

unordered_map<int, bool> edge[100000];

void input() {

    cin >> N >> M;

    for(int i=0; i<M; i++) {

        int u, v;

        cin >> u >> v;

        edge[u-1].insert({v-1, true});
        edge[v-1].insert({u-1, true});
    }
}

void solution() {
    input();

    vector<bool> isVisted = vector<bool>(N, false);

    int cycle_cnt = 0;
    int cluster_cnt = 0;

    for(int node=0; node<N; node++) {

        if(!isVisted[node]) {
        
            cluster_cnt+=1;

            // parent, child
            queue<pair<int, int>> q;

            isVisted[node] = true;

            q.push({-1, node});

            while(!q.empty()) {
                
                int parent = q.front().first;
                int current = q.front().second;

                q.pop();

                for(pair<int, bool> next : edge[current]) {

                    int next_node = next.first;
                    bool isValid = next.second;

                    if(!isValid) { continue; }
                    
                    if(!isVisted[next_node]) {
                        
                        isVisted[next_node] = true;

                        q.push({current, next_node});
                    } else {

                        if(next_node != parent) {

                            edge[next_node][current] = false;

                            cycle_cnt+=1;
                        }
                    }
                }
            }
        }
    }

    cout << (cluster_cnt-1) + cycle_cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
