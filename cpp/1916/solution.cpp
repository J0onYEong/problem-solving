#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Edge pair<int, int> //cost(start - a point), node
#define PQ priority_queue<Edge, vector<Edge>, greater<Edge> >

using namespace std;

const int MAX = 1001;
const int INF = 2147483647;

void solution() {
    int N, M, start_node, end_node;
    vector<Edge> vertice_data[MAX];
    PQ pq;
    int d[MAX];

    for(int i=1; i<=MAX; i++)
        d[i]=INF;

    cin >> N;
    cin >> M;


    for(int i=0; i<M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        vertice_data[s].push_back(make_pair(c, e));
    }

    cin >> start_node >> end_node;

    d[start_node] = 0;
    for(auto e : vertice_data[start_node]) {
        pq.push(e);
        d[e.second] = e.first;
    }


    while(!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        int cost = edge.first;
        int next_node = edge.second;

        d[next_node] = cost;

        if(next_node == end_node)
            break;

        for(auto e : vertice_data[next_node]) {
            if(d[e.second] > cost + e.first) {
                Edge temp;
                temp.first = e.first + cost;
                temp.second = e.second;
                pq.push(temp);
            }
        }
    }
    cout << d[end_node] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
