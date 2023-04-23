#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int n;
    cin >> n;
    int memo[100001];
    int coins[4] = {1, 2, 5, 7};

    memo[0] = 0;
    for(int i=1;i<=n; i++) {
        memo[i] = i;
        for(int j=3;j>=0;j--) {
            int temp = i-coins[j];
            if(temp<0) continue;
            memo[i] = min(memo[i], 1 + memo[temp]);
        }
    }
    cout << memo[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
