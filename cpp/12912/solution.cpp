#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX = 2000;

int N;

class Edge {
public:
    bool isActive;
    int v1, v2;
    int cost;
};

vector<Edge> edges;

vector<pair<int ,int> > q_edge[MAX];  

pair<ll, int> find_end_point(int start, int last = -1) {
    //이동가능한 노드가 있는지 확인하는 변수
    bool check = false;

    pair<ll, int> result = make_pair(-1, 0);

    for(auto e : q_edge[start]) {
        Edge edge_data = edges[e.first];
        //간선이 활성화 상태인지 확인
        if(!edge_data.isActive) 
            continue;
        
        //간선이 길모퉁이 상태인지 확인
        if(e.second == last)
            continue;
        check = true;
        pair<ll, int> temp = find_end_point(e.second, start);
        temp.first += edge_data.cost;
        if(result.first < temp.first)
            result = temp;
    }

    if(!check) {
        // end point
        return make_pair(0, start);
    }

    return result;
}

void solution() {
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge temp;
        temp.v1 = from;
        temp.v2 = to;
        temp.cost = cost;
        temp.isActive = true;

        edges.push_back(temp);

        q_edge[from].push_back(make_pair(i, to));
        q_edge[to].push_back(make_pair(i, from));
    }


    ll result = 0;
    for(int i=0; i<edges.size(); i++) {
        Edge &e = edges[i];
        e.isActive = false;
        //Tree1
        int t1 = find_end_point(e.v1).second;
        ll r1 = find_end_point(t1).first;

        //Tree2
        int t2 = find_end_point(e.v2).second;
        ll r2 = find_end_point(t2).first;

        result = max(result, r1 + r2 + e.cost);

        e.isActive = true;
    }

    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
