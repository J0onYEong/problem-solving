#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Edge pair<int, pair<int, int>>

using namespace std;

const int max_n = 100000+1;
const int max_k = 50000+1;

int N, K, M;

vector<Edge> edges;

map<int, int> cc_data[max_n];

int cc_node[max_n];

ll result[max_k];
  
void input() {
    cin >> N >> K >> M; 

    for(int i=1; i<=N; i++) {
        int company_number;
        cin >> company_number;
        cc_data[i][company_number] = 1;
    }

    for(int i=0; i<M; i++) {
        int X, Y, W;
        cin >> X >> Y >> W;
        edges.push_back({W, {X, Y}});
    }
}

int find_cc(int node) {
    if(node == cc_node[node])
        return node;
    return cc_node[node] = find_cc(cc_node[node]);
}

void union_cc(int node1, int node2) {
    int cn1 = find_cc(node1);
    int cn2 = find_cc(node2);

    map<int, int> &cc1 = cc_data[cn1];
    map<int, int> &cc2 = cc_data[cn2];
    if(cc1.size() >= cc2.size()) {
        cc_node[cn2] = cn1; 
        for(auto e : cc2)
            cc1[e.first] += e.second;
    }
    else {
        cc_node[cn1] = cn2; 
        for(auto e : cc1)
            cc2[e.first] += e.second;
    }
}

void solution() {
    input();

    for(int i=1; i<=N; i++)
        cc_node[i] = i;

    //내림차순 정렬
    sort(edges.begin(), edges.end(), greater<Edge>());

    memset(result, 0, sizeof(result));

    for(Edge e : edges) {
        int n1 = e.second.first;
        int n2 = e.second.second;
        ll weight = e.first;

        int cc1 = find_cc(n1);
        int cc2 = find_cc(n2);

        //두노드가 서로다른 cc인 경우
        if(cc1 != cc2) {
            int cc1s = cc_data[cc1].size();
            int cc2s = cc_data[cc2].size();

            int less_size = cc1;
            int larger_size = cc2;

            if(cc1s > cc2s) {
                less_size = cc2;
                larger_size = cc1;
            }

            for(auto e : cc_data[less_size]) {
                int company = e.first;
                result[e.first] += weight*(e.second * cc_data[larger_size][company]);
            }
            //연결 요소를 합친다.
            union_cc(n1, n2);  
        }
    }

    for(int i=1; i<=K; i++)
        cout << result[i] <<  endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
 