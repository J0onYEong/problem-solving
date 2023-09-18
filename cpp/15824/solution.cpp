#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 300000;
const int MOD = 1000000007;

int N;

ll pepperRate[MAX_N];

ll resultOfCustomPow[MAX_N];

void input() {
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> pepperRate[i];
}

void solution() {
    input();

    sort(pepperRate, pepperRate+N);

    for(int i=0; i<N; i++)
        pepperRate[i] %= MOD;

    resultOfCustomPow[0] = 1;

    for(int i=1; i<N; i++)
        resultOfCustomPow[i] = (resultOfCustomPow[i-1]*2)%MOD;

    ll result = 0;
    for(int i=0; i<N; i++) {
        result += resultOfCustomPow[i] * pepperRate[i];
        result %= MOD;
        result -= resultOfCustomPow[(N-1)-i] * pepperRate[i];
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
