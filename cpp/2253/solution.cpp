#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_num = 10000;
int n, m;
int stoneBridge[max_num+1];
int dp[max_num+1][401];
int j[] = {-1,0,1};

int recursive(int node, int lastJump) {
    if(node == n) 
        return 0;

    if(dp[node][lastJump])
        return dp[node][lastJump];
    else 
        dp[node][lastJump] = max_num;
    
    for(int i=0; i<3; i++) {
        int temp = lastJump + j[i];

        //점프는 1이상, 최대범위 이내, 이동가능한 지점
        if(temp >= 1 && node+temp <= n && stoneBridge[node+temp]) {
            dp[node][lastJump] = min(dp[node][lastJump], 1+recursive(node+temp, temp));
        }
    }
    return dp[node][lastJump];
}

void solution() {
    cin >> n >> m;

    memset(stoneBridge, 1, sizeof(int)*max_num+1);
    for(int i=0; i<=max_num; i++)
        for(int j=0; j<=400; j++)
            dp[i][j] = 0;
    
    for(int i=0; i<m; i++) {
        int num;
        cin >> num;
        stoneBridge[num] = 0;
    }

    int result = recursive(1, 0);

    if(result == max_num)
        cout << -1 << endl;
    else 
        cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
