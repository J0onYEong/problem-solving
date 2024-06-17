#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int N;

vector<int> stair;

int dp[10001][3];

void input() {
    cin >> N;

    stair = vector<int>(N+1, 0);

    for(int i=1; i<=N; i++) {
        cin >> stair[i];
    }
}

void solution() {
    input();

    for(int i=0; i<=N; i++) 
        for(int s=0; s<3; s++) 
            dp[i][s] = 0;
    
    for(int i=1; i<=N; i++) {

        dp[i][2] = dp[i-1][1]+stair[i];

        if(i-2 >= 0) {
            dp[i][1] = max(dp[i-2][1], dp[i-2][2])+stair[i];
        } else {
            dp[i][1] = stair[i];
        }
    }

    cout << max(dp[N][1], dp[N][2]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
