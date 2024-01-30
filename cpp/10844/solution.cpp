#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 100;
const int MOD_VALUE = 1000000000;

int n;

int dp[MAX_N][10];

int recursive(short pos, short number) {

    if(pos == n-1) {

        return 1;

    }

    int &ret = dp[pos][number];

    if(ret != -1) {
        return ret;
    }

    short upper_number = number+1;
    short lower_number = number-1;

    ret = 0;

    if(upper_number < 10) {
        ret += recursive(pos+1, upper_number);
    }

    if(0 <= lower_number) {
        ret += recursive(pos+1, lower_number);
    }

    ret %= MOD_VALUE;

    return ret;

}


void input() {

    cin >> n;

}

void solution() {
    input();

    for(int i=0; i<n; i++) {
        for(int j=0; j<10; j++) {
            dp[i][j] = -1;
        }
    }


    int result = 0;

    for(int i=1; i<10; i++) {

        result += recursive(0, i);

        result %= MOD_VALUE;

    }

    cout << result << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
