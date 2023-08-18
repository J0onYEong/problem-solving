#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Query pair<int ,pair<int, int>>

using namespace std;

const int max_n = 100000+1;
const int max_q = 1000000+1;

int N, Q;

int node_cc[max_n];
int node_color[max_n];

map<int, int> cc_color_data[max_n];

stack<Query> query;

int find_cc(int node) {
    int &ret = node_cc[node];
    if(ret == node)
        return ret;
    return ret = find_cc(ret);
}

void divide_node(int node) {
    node_cc[node] = node;
}

void uinion_cc(int node, int parent) {
    int cc1_num = find_cc(node);
    int cc2_num = find_cc(parent);

    map<int, int> &cc1 = cc_color_data[cc1_num];
    map<int, int> &cc2 = cc_color_data[cc2_num];

    if(cc1.size() > cc2.size()) {
        for(auto e : cc2)
            cc1[e.first] += e.second;
        node_cc[cc2_num] = cc1_num;
    } else {
        for(auto e : cc1)
            cc2[e.first] += e.second;
        node_cc[cc1_num] = cc2_num;
    }
}

void input() {
    cin >> N >> Q;

    node_cc[1] = 1;
    for(int i=2; i<=N; i++)
        cin >> node_cc[i];
    
    for(int i=1; i<=N; i++)
        cin >> node_color[i];
    
    for(int i=1; i<=N-1+Q; i++) {
        int x, a;
        cin >> x >> a;
        //분리전에 부모에 대한 정보를 저장
        query.push({x, {a, node_cc[a]}});
        //
        if(x == 1)
            divide_node(a);
    }
}

void solution() {
    input();

    for(int i=1; i<=N; i++) {
        int node_num = i;
        int cc_num = find_cc(node_num);
        map<int ,int> &m = cc_color_data[cc_num];
        m[node_color[node_num]]+=1;
    }

    stack<int> result;

    while(!query.empty()) {
        Query temp = query.top();
        query.pop();

        int x = temp.first;
        int a = temp.second.first;
        int p = temp.second.second;

        if(x==1)
            uinion_cc(a, p);
        if(x==2) {
            int cc_num = find_cc(a);
            result.push(cc_color_data[cc_num].size());
        }
    }

    while(!result.empty()) {
        int temp = result.top();
        result.pop();
        cout << temp << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
