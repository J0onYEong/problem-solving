#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pos pair<int, int>
#define edge pair<pos, int>

using namespace std;

void solution() {
    int n, d;
    cin >> n >> d;
    vector<edge> edges;
    for(int i=0; i<n; i++) {
        edge temp;
        cin >> temp.first.first >> temp.first.second >> temp.second;
        edges.push_back(temp);
    }

    int dp[10001];
    for(int i=0; i<=d; i++)
        dp[i]=i;

    priority_queue<pair<int, int> > pq;
    // weight, node
    pq.push(make_pair(0, 0));

    while(!pq.empty()) {
        int weight = -(pq.top().first);
        int node = pq.top().second;
        if(node == d) {
            cout << weight << endl;
            return;
        }
        pq.pop();
        for(auto e : edges) {
            if(e.first.first == node) {
                int ep = e.first.second;
                if(ep <= d && weight + e.second < dp[ep]) {
                    dp[ep] = weight + e.second;
                    pq.push(make_pair(-(dp[ep]), ep));
                }
            }
        }
        int rest = d-node;
        if(weight+rest < dp[d])
            dp[d] = weight+rest;

        if(node < d)
            pq.push(make_pair(-(weight+1), node+1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
