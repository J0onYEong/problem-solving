#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int n;
vector<int> cases;

const string max_value = "1000000000000000";

vector<int> hms = { 6, 2, 5, 5, 4, 5, 6, 3, 7 ,6 };
vector<string> dp = vector<string>(101, max_value);

string find_max_num(int number) {

    int temp = number;
    string result = "";

    while(temp != 0 && temp != 3) {

        temp -= 2;
        result += "1";
    }

    if(temp == 3) {
        result = "7"+result;
    }

    return result;
}

void find_min_num_setting() {

    dp[0] = "0";

    for(int i=0; i<=100; i++) {

        if(i+2 <= 100) {
            if(stoll(dp[i+2]) > stoll(dp[i]+"1")) {
                dp[i+2] = dp[i] + "1";   
            }
        }

        if(i+3 <= 100 && stoll(dp[i+3]) > stoll(dp[i]+"7")) {
            dp[i+3] = dp[i]+"7";
        }
        
        if(i+4 <= 100 && stoll(dp[i+4]) > stoll(dp[i]+"4")) {
            dp[i+4] = dp[i]+"4";
        }

        if(i+5 <= 100 && stoll(dp[i+5]) > stoll(dp[i]+"2")) {
            dp[i+5] = dp[i]+"2";
        }

        if(i+6 <= 100 && stoll(dp[i+6]) > stoll(dp[i]+"0")) {

            if(i == 0) {
                dp[i+6] = "6";
            } else {
                dp[i+6] = dp[i]+"0";
            }
        }

        if(i+7 <= 100 && stoll(dp[i+7]) > stoll(dp[i]+"8")) {
            dp[i+7] = dp[i]+"8";
        }
    }
}

void input() {
    cin >> n;

    for(int i=0; i<n; i++) {
        int stick_cnt;
        cin >> stick_cnt;
        cases.push_back(stick_cnt);
    }
}

void solution() {
    input();

    find_min_num_setting();

    for(auto c : cases) {
        cout << stoll(dp[c]) << " " << find_max_num(c) << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
