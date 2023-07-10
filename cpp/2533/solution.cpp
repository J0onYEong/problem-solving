#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 1000001;

// 시작점이 정해져 있을 때 특정노드의 상태에 따른 필요한 얼리어답터수
// 이게 가능한 이유는 트리가 스패닝트리이며 시작점을 임임의 노드로 고정함으로 성립한다.
int dp[2][max_n];
int N;
vector<int> edge[max_n];


int recursive(int node, int status, int last) {
    int& ret = dp[status][node];
    if(ret != -1)
        return ret;

    int result = status;
    for(int next : edge[node]) {
        if(next == last)
            continue;

        if(status) 
            result += min(recursive(next, 0, node), recursive(next, 1, node));
        else 
            result += recursive(next, 1, node);
    }
    return ret = result;
}


void solution() {
    cin >> N;
    int a, b;
    for(int i=1; i<=N-1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    
    for(int i=0; i<2; i++)
        memset(dp[i], -1, sizeof(int)*max_n);

    int result = min(recursive(1, 0, -1), recursive(1, 1, -1));    
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
