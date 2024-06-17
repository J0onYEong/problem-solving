#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;
vector<int> S;
int A, D;

int dp[1001][1001];

void input() {

    cin >> N >> M;
    S = vector<int>(N, 0);
    
    for(int i=0; i<N; i++)
        cin >> S[i];

    cin >> A >> D;
}

void solution() {
    input();

    int max_b = (N-1) / D + 1;

    for(int i=1; i<=N; i++)
        for(int j=0; j<=max_b; j++) 
            dp[i][j] = 0;

    for(int i=1; i<=N; i++) {
        for(int jump=0; jump<=max_b; jump++) {
            
            dp[i][jump] = max(dp[i][jump], dp[i-1][jump] + S[i-1]);

            // 현재 위치에서 헌혈을 하는 경우
            if(jump < max_b) {

                int des = i+D-1;
                des = des > N ? N : des;

                dp[des][jump+1] = max(dp[des][jump+1], dp[i-1][jump] + A);
            }
        }
    }
    
    for(int i=0; i<=max_b; i++) {

        if(dp[N][i] >= M) {

             cout << i << endl;
             return;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
