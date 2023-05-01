#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define element pair<int, int>

using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;

    vector<element> elementList;
    for(int i=0; i<k; i++) {
        element e;
        // first - 중요도, second - 공부시간
        cin >> e.first >> e.second;
        elementList.push_back(e);
    }

    int memo[1000][10001];
    for(int i=0; i<k; i++) {
        int value = elementList[i].first;
        int weight = elementList[i].second;
        // 무게는 0부터 n까지를 모두 고려해야 한다.
        for(int j=0; j<=n; j++) {
            if(j >= weight) 
                memo[i][j] = i != 0 ? memo[i][j] = max(memo[i-1][j], value+memo[i-1][j-weight]) : value;
            else 
                memo[i][j] = i != 0 ? memo[i-1][j] : 0;
        }
    }

    cout << memo[k-1][n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
