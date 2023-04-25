#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int memo[51];

int fiboCount(int n) {
    if(memo[n]) return memo[n];
    memo[n] = (1+fiboCount(n-2)+fiboCount(n-1)) % 1000000007;
    return memo[n];
}

void solution() {
    int n;
    cin >> n;
    memo[0] = 1;
    memo[1] = 1;
    cout << fiboCount(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
