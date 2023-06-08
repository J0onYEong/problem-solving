#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ed pair<int, int> // weight, destination

using namespace std;
const int MAX = 1001;

int N, M;
vector<ed> edge[MAX];

template<typename Compare>
int prim() {
    bool T[MAX]; 
    int result = 0;
    memset(T, 0, sizeof(bool)*MAX);
    priority_queue<ed, vector<ed>, Compare> q;

    q.push(make_pair(0, 0));

    for(int i=0; i<=N; i++) {
        int node=-1;
        int weight=0;
        while(!q.empty()) {
            weight = q.top().first;
            node = q.top().second;
            if(!T[node])
                break;
            q.pop();
        }
        T[node] = true;
        result+=weight;
        for(auto e : edge[node])
            q.push(e);
    }
    return result;
}

void solution() {
    cin >> N >> M;

    for(int i=0; i<=M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if(C == 0)
            C = 1;
        else
            C = 0;
        edge[A].push_back(make_pair(C, B));
        edge[B].push_back(make_pair(C, A));
    }
    
    ll max_value = prim<less<ed> >();
    ll min_value = prim<greater<ed> >();

    cout << max_value*max_value - min_value*min_value << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
