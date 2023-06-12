#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define CumulatedEdge pair<int, int>
#define Edge pair<int, int>

using namespace std;
const int INF = 2147483647;
const int MAX = 801;

class Vertex {
public: 
    vector<Edge> adjNodes;
};

int N, E;
int v1, v2;
Vertex vertice[MAX];


int dijkstra(int start, int end) {
    priority_queue<CumulatedEdge, vector<CumulatedEdge>, greater<CumulatedEdge> > pq;
    int d[MAX];

    for(int i=1; i<=N; i++)
        d[i] = INF;

    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cum_cost = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        d[now_node] = cum_cost;

        if(now_node == end) 
            break;

        for(auto an : vertice[now_node].adjNodes) {
            int cost = an.first;
            int next_node = an.second;
            if(d[next_node] > cum_cost + cost) {
                CumulatedEdge temp;
                temp.first = cum_cost + cost;
                temp.second= next_node;
                pq.push(temp);
            }
        } 
    }
    return d[end];
}

void solution() {
    cin >> N >> E;

    for(int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vertice[a].adjNodes.push_back(make_pair(c, b));
        vertice[b].adjNodes.push_back(make_pair(c, a));
    }
    cin >> v1 >> v2;

    ll result = INF;
    pair<int, int> iter_set[2][3] = {
        {
            make_pair(1, v1),
            make_pair(v1, v2),
            make_pair(v2, N)
        },
        {
            make_pair(1, v2),
            make_pair(v2, v1),
            make_pair(v1, N)
        }
    };

    for(int j=0; j<2; j++) {
        ll temp_result = 0;
        for(int i=0; i<3; i++)
            temp_result += dijkstra(iter_set[j][i].first, iter_set[j][i].second);
        result = min(result, temp_result);
    }

    if(result >= INF) {
        cout << -1 << endl;
        return;
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
