#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define edge pair<int, int>

using namespace std;

void solution() {
    int v, e, start;
    cin >> v >> e >> start;
    unordered_map<int, vector<edge> > m;
    for(int i=0; i<e; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        m[n1].push_back(make_pair(w, n2));
    }

    // node, weight, start노드로 부터 node로 이동하는 데 걸린 비용
    int d[20001];
    for(int i=0; i<20001; i++)
        d[i] = 200000;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()) {
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        for(auto e : m[v]) {
            int t_node = e.second;
            int t_weight= e.first;
            t_weight += w;
            if(d[t_node] > t_weight) {
                d[t_node] = t_weight;
                pq.push(make_pair(-t_weight, t_node));
            } 
        }
    }

    for(int i=1; i<=v; i++) {
        if(d[i] == 200000)
            cout << "INF" << endl;
        else 
            cout << d[i] << endl;
    } 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
