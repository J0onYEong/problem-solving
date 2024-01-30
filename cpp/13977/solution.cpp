#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

const int Tree_size = 17000000;

const int MAX_N = 4000000+1;
const int MAX_M = 100000+1;

int M;

vector<pair<int, int>> query;

void input() {
    cin >> M;

    for(int i=0; i<M; i++) {
        int n, k;
        cin >> n >> k;
        query.push_back({n, k});
    }
}

void solution() {
    input();


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
