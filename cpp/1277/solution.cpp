#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vertex pair<int, int>
#define edge pair<int, int>
#define MAX_INT 2147483647

using namespace std;

double get_length(vertex v1, vertex v2) {
    double a = pow((v1.first-v2.first), 2);
    double b = pow((v1.second-v2.second), 2);
    return sqrt(a+b);
}

void solution() {
    int n, w;
    double m;
    cin >> n >> w >> m;
    vector<vertex> vertices;
    vertices.push_back(make_pair(0,0));
    for(int i=1; i<=n; i++) {
        vertex temp;
        cin >> temp.first >> temp.second;
        vertices.push_back(temp);
    }
    
    vector<edge> edges;
    for(int i=0; i<w; i++) {
        edge temp;
        cin >> temp.first >> temp.second;
        edges.push_back(temp);
    }    

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 1));
    int d[1001];
    memset(d, MAX_INT, sizeof(d));

    while(true) {
        int v = pq.top().second;
        cout << v << endl;
        int weight = pq.top().first;

        if(v == n) 
            break;

        for(auto e : edges) {
            if(e.first == v) {
                pq.push(make_pair(weight, e.second));
            } else if(e.second == v) {
                pq.push(make_pair(weight, e.first));
            }
        }

        for(int i=1; i<=v; i++) {
            int temp_w = get_length(vertices[v], vertices[i]);
            if(temp_w >= m)
                continue;
            if(d[i] > temp_w+weight) {
                d[i] = temp_w + weight;
                pq.push(make_pair(temp_w + weight, i));
            }
        }
    }
    cout << d[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
