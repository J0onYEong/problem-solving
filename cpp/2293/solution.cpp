#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 100;
const int MAX_K = 100000;

int n, k;

vector<int> coin_values;
int dp[MAX_K+1] = {0};

void input() {
    cin >> n >> k;

    int value;
    for(int i=0; i<n; i++) {
        cin >> value;
        coin_values.push_back(value);
    }
}

void solution() {
    input();

    sort(coin_values.begin(), coin_values.end());

    dp[0] = 1;
    
    for(int i=0; i<n; i++) {

        int value = coin_values[i];

        for(int v = value; v<=k; v++) {
            dp[v] += dp[v-value];
        }   
    }
    
    cout << dp[k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
