#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
#define MC 987654321

using namespace std;

void solution() {
    
    int T;

    ll dp[500][500];
    int sum[500];

    cin >> T;

    for(int t=0; t<T; t++) {

        for(int i=0; i<500; i++) {
            for(int j=0; j<500; j++) {
                dp[i][j] = MC;
             }
        }

        int k;

        cin >> k;

        for(int i=0; i<k; i++) {

            int page; 

            cin >> page;

            if(i == 0) {
                sum[i] = page;
            } else {
                sum[i] = sum[i-1] + page;
            }

            dp[i][i] = 0;
        }

        for(int i=2; i<=k; i++) {

            for(int sp=0; sp<k-(i-1); sp++) {
                
                int ep = sp+(i-1);

                int mc;

                if(sp == 0) {
                    mc = sum[ep];
                } else {
                    mc = sum[ep]-sum[sp-1];
                }

                for(int m=sp; m<ep; m++) {

                    ll &ret = dp[sp][ep];

                    ret = min(ret, dp[sp][m]+dp[m+1][ep]+mc);
                }
            }
        }    

        cout << dp[0][k-1] << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
