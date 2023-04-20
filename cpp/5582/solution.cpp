#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
int memo[4000][4000];

int recursive(string &str1, string &str2, int s1Index, int s2Index) {
    if(s1Index >= str1.length() || s2Index >= str2.length()) return 0;

    if(memo[s1Index][s2Index] != -1) 
        return memo[s1Index][s2Index];
    
    memo[s1Index][s2Index] = str1[s1Index] == str2[s2Index] ? 1 + recursive(str1, str2, s1Index+1, s2Index+1) : 0;
    return memo[s1Index][s2Index];
}

void solution() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i=0;i<4000;i++) 
        for(int j=0;j<4000;j++)
            memo[i][j] = -1;
    
    int result = 0;
    int length1 = str1.length();
    int length2 = str2.length();
    for(int i=0; i<length1; i++) {
        for(int j=0; j<length2; j++) {
            int temp = recursive(str1, str2, i, j);
            result = max(result, temp);
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
