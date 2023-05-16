    #include <bits/stdc++.h>
    #define ll long long
    #define endl "\n"
    
    const ll Mod = 1000000003;

    using namespace std;

    int dp[1001][1001];

    int N, K;

    ll recursive(int n, int k) {
        if(k == 0) 
            return 1;
        else if(k ==1)
            return n;

        if (k > n/2+1)
            return 0;    

        if(dp[n][k])
            return dp[n][k];
        return dp[n][k] = (recursive(n-2, k-1) + recursive(n-1, k)) % Mod;
    }


    void solution() {
        cin >> N >> K;

        for(int i=0; i<=N; i++) 
            for(int j=1; j<=K; j++)
                dp[i][j] = 0;
        

        cout << (recursive(N-1, K) + recursive(N-3, K-1)) % Mod << endl;
        
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        solution();
        return 0;
    }
