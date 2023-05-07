#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define edge pair<int, int>

using namespace std;

void solution() {
    int v, e;
    cin >> v >> e;

    int group[10001];
    memset(group, -1, sizeof(int)*10001);

    vector<pair<int, edge> > edges;

    for(int i=0; i<e; i++) {
        edge temp;
        int value;
        cin >> temp.first >> temp.second >> value;
        edges.push_back(make_pair(value, temp));
    }

    sort(edges.begin(), edges.end());

    int groupIndex = 0;
    int edgeCount = 0;
    ll result = 0;

    for(auto d : edges) {
        int v = d.first;
        int lhs = d.second.first;
        int rhs = d.second.second;
        if(group[lhs] == group[rhs]) {
            if(group[lhs] == -1) {
                group[lhs] = groupIndex;
                group[rhs] = groupIndex++;
                result+=v;
                edgeCount++;
            } else {
                // cycle
                continue;
            }
        } else {
            result+=v;
            edgeCount++;
            if(group[lhs] == -1) {
                group[lhs] = group[rhs];
            } else if(group[rhs] == -1) {
                group[rhs] = group[lhs];
            } else {
                int sg = group[lhs];
                for(int i=1; i<=10000; i++)
                    if(group[i] == sg)
                        group[i] = group[rhs];
            }
        }

        if(edgeCount == v-1)
            break;
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
