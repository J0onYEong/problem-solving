#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define endl "\n"

using namespace std;

string str1, str2;

vector<vector<int>> dp;

void input() {
    cin >> str1 >> str2;
}

void solution() {
    input();

    dp = vector<vector<int>> (str1.size()+1, vector<int>(str2.size()+1, 0));
    
    int str1_index = 1;
    int str2_index = 1;

    while(str1_index <= str1.length()) {

        int &ret = dp[str1_index][str2_index];

        if(str1[str1_index-1] == str2[str2_index-1]) {

            ret = dp[str1_index-1][str2_index-1]+1;

        } else {

            ret = max(dp[str1_index][str2_index-1], dp[str1_index-1][str2_index]);
        }

        str2_index++;

        if(str2_index > str2.length()) {

            str1_index++;
            str2_index = 1;
        }

    }

    cout << dp[str1.length()][str2.length()] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
