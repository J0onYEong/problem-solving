#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX = 100001;

int N;
vector<int> edges[MAX];
int dp[MAX][2];

//현재 기점을 기준으로 필요한 소방소의 개수를 반환
// bp는 해당노드에 경찰서를 설치해야함을 의미
int dfs(int now, int prev, bool bp) {


    if(dp[now][bp] != -1)
        return dp[now][bp];
    
    int result = bp ? 1 : 0;
    for(int v : edges[now]) {
        if(v != prev) {
            if(bp)
                result += min(dfs(v, now, false), dfs(v, now, true));
            else {
                result += dfs(v, now, true);
            }
        }
    }



    dp[now][bp] = result;
    return dp[now][bp];
}

void solution() {
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i=1; i<=N; i++)
        dp[i][1] = dp[i][0] = -1;

    cout << min(dfs(1, 0, true), dfs(1, 0, false)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
