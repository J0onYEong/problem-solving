#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define order pair<int, int>

using namespace std;

void solution() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<order> orderList;
    for(int i=0; i<n; i++) {
        order temp;
        cin >> temp.first >> temp.second;
        orderList.push_back(temp);
    }

    int memo[100][301][301];
    
    for(int ord=0; ord<n; ord++) {
        for(int bA=0; bA<=m; bA++) {
            for(int fA=0; fA<=k; fA++) {
                int now_b = orderList[ord].first;
                int now_f = orderList[ord].second;
                // 현재 주문을 수행할 수 있는 경우
                if(now_b <= bA && now_f <= fA) {
                    if(ord != 0) 
                        memo[ord][bA][fA] = max(memo[ord-1][bA][fA], 1+memo[ord-1][bA-now_b][fA-now_f]);
                    else 
                        memo[ord][bA][fA] = 1;
                }
                else {
                    // 현재 주문 수행불가
                    memo[ord][bA][fA] = ord == 0 ? 0 : memo[ord-1][bA][fA];
                }
            }
        }    
    }
    cout << memo[n-1][m][k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
