#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int N;
vector<pair<int, int>> pos;

void input() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;

        pos.push_back({x, y});
    }
}

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {

    if(lhs.first != rhs.first) {
        return lhs.first < rhs.first;
    } else {
        return lhs.second < rhs.second;
    }
}

void solution() {
    input();

    sort(pos.begin(), pos.end(), cmp);

    int last_p = -1000000001;
    ll result = 0;

    for(auto current : pos) {

        if(last_p < current.second) {

            result += (current.second-current.first);

            if(current.first < last_p) {
                // 겹치는 경우
                result -= (last_p-current.first);
            }

            last_p = current.second;
        }
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
