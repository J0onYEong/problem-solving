#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX = 101;

int N, M;
int a[MAX];
int c[MAX];
int dp[MAX][10001];

void solution() {
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> a[i];
    
    int sum=0;
    for(int i=1; i<=N; i++) {
        cin >> c[i];
        sum+=c[i];
    }
    
    for(int i=0; i<=N; i++) 
        memset(dp[i], 0, sizeof(int)*(sum+1));
    
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=sum; j++) {
            if(j >= c[i])
                dp[i][j] = max(dp[i-1][j-c[i]] + a[i], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    for(int j=0; j<=sum; j++) {
        if(dp[N][j] >= M) {
            cout << j << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
