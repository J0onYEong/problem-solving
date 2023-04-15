#include <bits/stdc++.h>

using namespace std;

int dfs(bool *visit, int *value, int state, int count, int size) {
    if(state < 0) return 0;
    if(count == size) 
        return state >= 0 ? 1 : 0;
    int numOfSuccess = 0;
    for(int i=0; i<size; i++) {
        if(!visit[i]) {
            visit[i] = true;
            int tempState = state + value[i];
            numOfSuccess += dfs(visit, value, tempState, count+1, size);
            visit[i] = false;
        }
    }
    return numOfSuccess;
}

void solution() {
    int n, k;
    cin >> n >> k;
    int* toolValue = new int[n];
    bool* visit = new bool[n];
    for(int i=0; i<n; i++) {
        cin >> toolValue[i];
        toolValue[i] -= k;
    }
    cout << dfs(visit, toolValue, 0, 0, n) << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}