#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int INIT = -1;
const int NOPE = -2;
/*
dp배열 저장기준 : 이동가능횟수 M내에서 1에서 N으로 이동이 성공했을 때 기내식 만족도의 최대값
세부사항1 : 1에서 N까지 이동이 성공한 경우에만 값을 저장헤야함
	- 실패한 경우에 대한 값 필요
세부사항2 : 이동횟수가 M을 넘지 않아야함
	- M횟수 안에 N에 도달하지 못 했을 경우 실패로판단 
세부사항3 : 실패가 재귀적으로 전달되게 해야함
*/
int dp[301][301];
int edge[301][301];
int N, M, K;

int recursive(int node, int m) {
    //도착한 경우 0을 반환 세부사항1과 2를 모두 만족함 
    if(node == N && m <= M)
        return 0;
    
    //이동횟수가 M을 초과할 경우 실패로 판단
    if(m > M)
        return NOPE;

    if(dp[node][m] != INIT)
        return dp[node][m];
    
    for(int i=node+1; i<=N; i++)
        if(edge[node][i]) {
            int temp = recursive(i, m+1);
            //실패가 재귀적으로 전달되도록 설정, 세부사항3 만족
            if(temp == NOPE)
                continue;
            dp[node][m] = max(dp[node][m], edge[node][i]+temp);
        }

    //실패가 재귀적으로 전달되도록 설정, 세부사항3 만족
    if(dp[node][m] == INIT)
        dp[node][m] = NOPE;
    return dp[node][m];
}

void solution() {
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++) {
        memset(dp[i], INIT, sizeof(int)*(N+1));
        memset(edge[i], 0, sizeof(int)*(N+1));
    }

    for(int i=0; i<K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b) {
            edge[a][b]=max(edge[a][b], c);
        }
    }


    cout << recursive(1, 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
