#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX = 2000;

int N;
vector<pair<int, int> > edges[MAX];

pair<int, int> find_end_point(int start, int last) {
    cout << start << " " << last << endl;

    // end point
    if(edges[start].size() == 1)
        return make_pair(0, start);

    pair<int, int> result = make_pair(-1, 0);
    for(auto e : edges[start]) {
        if(e.second != last) {
            pair<int, int> temp = find_end_point(e.second, start);
            temp.first += e.first;
            if(result.first < temp.first)
                result = temp;
        } 
    }

    return result;
}

void solution() {
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[from].push_back(make_pair(cost, to));
        edges[to].push_back(make_pair(from, to));
    }
    cout << find_end_point(find_end_point(0, -1).second, -1).second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
