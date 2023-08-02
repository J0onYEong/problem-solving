#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 100001;

int N;

vector<pair<int, int> > X, Y, Z; 

vector<pair<int, pair<int, int>>> composite;

int parent[max_n];

int find_parent(int node) {
    if(node == parent[node])
        return parent[node];

    return parent[node] = find_parent(parent[node]);
}

void unite(int n1, int n2) {
    int p1 = find_parent(n1);
    int p2 = find_parent(n2);

    if(p1 < p2) 
        parent[p2] = p1;
    else 
        parent[p1] = p2;
}



void input() {
    cin >> N;

    for(int i=1; i<=N; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }
}

void solution() {
    input();

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for(int i=0; i<N-1; i++) {
        composite.push_back({X[i+1].first-X[i].first, {X[i].second, X[i+1].second}});
        composite.push_back({Y[i+1].first-Y[i].first, {Y[i].second, Y[i+1].second}});
        composite.push_back({Z[i+1].first-Z[i].first, {Z[i].second, Z[i+1].second}});
    }

    sort(composite.begin(), composite.end());

    for(int i=1; i<=N; i++)
        parent[i] = i;


    ll result = 0;

    for(auto e : composite) {
        int a = e.second.first;
        int b = e.second.second;
        int dis = e.first;

        if(find_parent(a) != find_parent(b)) {
            unite(a, b);
            result += dis;
        }
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
