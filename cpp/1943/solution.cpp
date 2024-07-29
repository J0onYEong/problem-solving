#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

vector<vector<pair<int, int>>> testCases(3, vector<pair<int, int>>());

void input() {
    
    for(int t=0; t<3; t++) {

        int n;
        cin >> n;

        for(int i=0; i<n; i++) {
            int coin, cnt;
            cin >> coin >> cnt;
            
            testCases[t].push_back({coin, cnt});
        }
    }
}   

void solution() {
    input();

    vector<bool> dp;

    for(auto t : testCases) {

        dp = vector<bool>(50001, false);

        dp[0] = true;

        int sum = 0;

        for(auto d : t) {
            sum += d.first * d.second;
        }

        if(sum % 2 == 1) {
            cout << 0 << endl;
            continue;
        }

        sort(t.begin(), t.end());
    
        for(int i=0; i<t.size(); i++) {

            for(int j=sum/2; j>= t[i].first; j--) {

                if(dp[j-t[i].first]) {

                    for(int k=0; k<=t[i].second; k++) {

                        if(j+t[i].first * k > sum/2) 
                            break;

                        dp[j+t[i].first * k] = true;
                    }
                }
            }
        }

        cout << dp[sum/2] << endl;   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
