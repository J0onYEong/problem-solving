#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int recursive(int node, int lastNode, bool **dep, int *delay, int *memo) {
    if(memo[node] != -1) return memo[node];

    for(int i=1; i<=lastNode; i++) {
        // 종속 노드를 발견할 경우
        if(dep[i][node])
            memo[node] = max(memo[node], recursive(i, lastNode, dep, delay, memo));
    }
    // 탐색중인 노드의 가중치를 더하거나 배정한다.
    memo[node] = memo[node]==-1 ? delay[node] : memo[node] + delay[node];
    return memo[node];
}



// top-down approach
void solution() {
    int t;
    cin >> t;
    int count = 0;
    while(count++<t) {
        // 2 <= n <=1000,  1<= k <= 100,000
        int n, k;
        cin >> n >> k;
        // 1 <= v <= 100,000
        int *delay = new int[1001];
        for(int i=1; i<=n; i++)
            cin >> delay[i];
        // dependency[a][b] b는 a에 종속적이다.
        bool **dependency = new bool*[1001];
        for(int i=0; i<1001; i++)
            dependency[i] = new bool[1001];
        for(int i=0; i<1001; i++) 
            memset(dependency[i], false, sizeof(bool)*1001);
        for(int i=0; i<k; i++) {
            int fir, sec;
            cin >> fir >> sec;
            dependency[fir][sec] = true;
        }

        int w;
        cin >> w;
        int *memo = new int[1001];
        memset(memo, -1, sizeof(int)*1001);
        cout << recursive(w, n, dependency, delay, memo) << endl;
        delete[] memo;
        delete[] delay;
        for(int i=0; i<1001; i++)  
            delete[] dependency[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
