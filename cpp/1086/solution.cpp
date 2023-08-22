#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 15+1;
const int max_len = 50+1;
const int dp_size = 32768+1;

int N, K;
string numbers[max_n];

long long dp[dp_size][100];

//preprocess
int ptm[51];

int numbers_rest[max_n];

void input() {
    cin >> N;
    for(int i=1; i<=N; i++) 
        cin >> numbers[i];
    cin >> K; 
}

/*
마쥴러 공식
(A + B) % K = ( (A % K) + (B % K) ) % K
(A * B) % K = ( (A % K) * (B % K) ) % K
*/

long long uclid(long long lhs, long long rhs) {
    long long big, small;

    big = max(lhs, rhs);
    small = min(lhs, rhs);

    while(small != 0) {
        long long temp = big % small;
        big = small;
        small = temp;
    }
    return big;
}

int get_mod(string &str) {
    int temp = 0;
    int length = str.size();
    for(int i=0; i<length; i++) {
        temp += str[i] - '0';
        if(i != length-1)
            temp *= 10;
        temp %= K;
    }
    return temp;
}

long long dfs(int state, int rest) {
    long long &ret = dp[state][rest];

    if(ret != -1)
        return ret;
    ret = 0;
    int bit = 1;
    int check = false;
    for(int i=0; i<N; i++) {
        if(i!=0)
            bit <<= 1;
        if(!(state & bit)) {
            check = true;
            int number_index = i+1;
            string& num = numbers[number_index];
            int length = num.size();
            int temp_rest = ((rest*ptm[length])%K + numbers_rest[number_index])%K;
            ret += dfs(state+bit, temp_rest);
        }
    }

    if(!check)
        return ret = rest == 0 ? 1 : 0;
    
    return ret;
}

void solution() {
    input();
    ptm[1] = 10 % K;
    for(int i=2; i<=50; i++)
        ptm[i] = (ptm[1] * ptm[i-1]) % K;
    
    for(int i=1; i<=N; i++)
        numbers_rest[i] = get_mod(numbers[i]);

    memset(dp, -1, sizeof(dp));

    long long nominator = dfs(0, 0);

    long long denominator = 1;
    for(int i=1; i<=N; i++)
        denominator *= i;
    long long gcd = uclid(nominator, denominator);

    cout << nominator/gcd << "/" << denominator/gcd << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
