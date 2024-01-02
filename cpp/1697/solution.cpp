#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 100000;

int n, k;

bool visited_spot[MAX_N+1];

void input() {
    cin >> n >> k;
}

void solution() {
    input();

    for(int i=0; i<=MAX_N; i++) {

        visited_spot[i] = 0;

    }

    queue<pair<int, int>> spots;

    vector<int> dxs = {1, -1, 2};

    spots.push({n, 0});

    while(!spots.empty()) {

        int pos = spots.front().first;
        int accum = spots.front().second;

        spots.pop();

        if(pos == k) {

            cout << accum << endl;

            return;
        }

        for(auto dx : dxs) {

            int p = pos + dx;

            if(dx == 2)
                p = pos * 2;

            if(p < 0 || p > MAX_N || visited_spot[p])
                continue;

            visited_spot[p] = 1;

            spots.push({p, accum+1});

        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
