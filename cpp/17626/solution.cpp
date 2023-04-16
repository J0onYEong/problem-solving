#include <bits/stdc++.h>

using namespace std;

void solution() {
    int n;
    cin >> n;
    int* memo = new int[n+1];

    for(int i=1; i<=n; i++) {
        int min = 5;
        for(int sq=1; sq<=220; sq++) {
            int rest = i-pow(sq,2);

            if(rest<0) break;

            int temp = rest == 0 ? 1 : 1 + memo[rest];

            if(temp < min) min = temp;
        }
        memo[i] = min;
    }
    cout << memo[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}