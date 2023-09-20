#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int CARD_CNT = 52;
const int MOD = 10007;

int N;

int combination[CARD_CNT+1][CARD_CNT+1];

void input() {
    cin >> N;
}

void solution() {
    input();

    for(int i=0; i<=52; i++) combination[i][0] = 1;
    for(int i=1; i<=52; i++)
        for(int j=1; j<=52; j++)
            combination[i][j] = (combination[i-1][j] + combination[i-1][j-1]) % MOD;
    int result = 0;
    for(int i=1; 4*i<=N; i++) {
        result += pow(-1, i+1) * combination[13][i] * combination[52-4*i][N-4*i];
        result %= MOD;
        if(result < 0)
            result += MOD;
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
