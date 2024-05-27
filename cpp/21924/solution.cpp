#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"
#define MyEdge pair<int, pair<int, int>>

using namespace std;

int N, M;

vector<MyEdge> edges;

int parent[100000];

void input() {
    cin >> N >> M;

    for(int i=0; i<M; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({c, {--a, --b}});
    }
}

bool cmp(const MyEdge& lhs, const MyEdge& rhs) {

    return lhs.first < rhs.first;
}

int find_root(int node) {

    if(parent[node] == node) {
        return node;
    }

    return parent[node] = find_root(parent[node]);
}

bool union_node(int node1, int node2) {

    int parent1 = find_root(node1);
    int parent2 = find_root(node2);

    if(parent1 < parent2) {

        parent[parent2] = parent1;

        return true;
    } 
    else if(parent2 < parent1) {

        parent[parent1] = parent2;

        return true;
    }   

    return false;
}


void solution() {
    input();

    sort(edges.begin(), edges.end(), cmp);

    for(int i=0; i<N; i++) {

        parent[i] = i;
    }


    ll whole_cost = 0;

    ll temp_reuslt = 0;

    for(MyEdge e : edges) {

        whole_cost += e.first;

        if(union_node(e.second.first, e.second.second)) {

            temp_reuslt += e.first;
        }
    }

    int ancester = find_root(0);
    
    for(int i=1; i<N; i++) {

        if(find_root(i) != ancester) {

            cout << -1 << endl;

            return;
        }
    }

    cout << whole_cost - temp_reuslt << endl;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
