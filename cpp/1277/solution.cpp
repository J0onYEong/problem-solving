#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vertex pair<int, int>
#define edge pair<int, int>
#define MAX 2000000000

using namespace std;

vector<edge> edges;
vector<vertex> vertices;

double get_length(int n1, int n2) {
    for(auto e : edges) {
        if((e.first==n1 && e.second==n2) || (e.first==n2 && e.second == n1))
            return 0;
    }
    vertex v1 = vertices[n1];
    vertex v2 = vertices[n2];

    double a = pow((v1.first-v2.first), 2);
    double b = pow((v1.second-v2.second), 2);
    return sqrt(a+b);
}

void solution() {
    int n, w;
    double m;
    cin >> n >> w >> m;
    vertices.push_back(make_pair(0,0));
    for(int i=1; i<=n; i++) {
        vertex temp;
        cin >> temp.first >> temp.second;
        vertices.push_back(temp);
    }
    for(int i=0; i<w; i++) {
        edge temp;
        cin >> temp.first >> temp.second;
        edges.push_back(temp);
    }

    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(0, 1));
    double d[1001];
    bool visit[1001];
    for(int i=0; i<1001; i++) {
        d[i] = MAX;
        visit[i] = false;
    }

    while(!pq.empty()) {
        int v = pq.top().second;
        visit[v] =true;
        double weight = -pq.top().first;
        pq.pop();
        if(v == n)
            break;
        for(int i=1; i<=n; i++) {
            if(visit[i])
                continue;
            double  temp_w = get_length(v, i);
            if(temp_w >= m)
                continue;
            if(d[i] > temp_w+weight) {
                d[i] = temp_w + weight;
                pq.push(make_pair(-d[i], i));
            }
        }
    }
    cout << (int)(d[n]*1000) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
