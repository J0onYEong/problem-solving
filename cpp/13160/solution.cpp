#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int N;

vector<pair<int, int>> range;
vector<pair<int, int>> org;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        range.push_back({s, 1});
        range.push_back({e, -1});
        org.push_back({s, e});
    }   
}

void solution() {
    input();
    sort(range.begin(), range.end(), [](pair<int, int>& l, pair<int, int>& r){return l.first == r.first ? l.second > r.second : l.first < r.first;});

    int result = 0;
    int max_value = 0;
    int st = 0;
    for(auto e : range) {
        result += e.second;
        if(result > max_value) {
            max_value = result;
            st = e.first;
        }
    }

    cout << max_value << endl;

    for(int i=0; i<org.size(); i++) {
        int start = org[i].first;
        int end = org[i].second;
        if(start <= st && st <= end)
            cout << i+1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
