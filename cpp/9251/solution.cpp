#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

string str1, str2;

vector<vector<int>> dp;

int A[2] = {0,1};
int B[2] = {1,0};

void input() {
    
    cin >> str1 >> str2;
}

int recursive(int start1, int start2) {
    
    if(start1 >= str1.size() || start2 >= str2.size()) { return 0; }

    if(dp[start1][start2] != -1) 
        return dp[start1][start2];

    int result = 0;

    if(str1[start1] == str2[start2]) {

        result = max(result, 1+recursive(start1+1, start2+1));
    } else {

        for(int i=0; i<2; i++) {

            result = max(result, recursive(start1+A[i], start2+B[i]));
        }
    }

    return dp[start1][start2] = result;
}

void solution() {
    input();

    dp = vector<vector<int>> (str1.size(), vector<int>(str2.size(), -1));

    cout << recursive(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
