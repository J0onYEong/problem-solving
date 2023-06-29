#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX = 10000;

int n;
int grape[MAX];

int dp[MAX][4]; 

int recursive(int pos, int count) {
    if(pos == n)
        return 0;

    if(dp[pos][count] != -1) 
        return dp[pos][count];
    
    int result = -1;

    if(count == 2)
        return dp[pos][count] = recursive(pos+1, 0);

    return dp[pos][count] = max(grape[pos]+recursive(pos+1, count+1), recursive(pos+1, 0));    
}

void solution() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> grape[i];

    for(int i=0; i<n; i++)
        memset(dp[i], -1, sizeof(int) * 4);
    
    cout << recursive(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
