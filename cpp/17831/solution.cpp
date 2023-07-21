#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int max_n = 200001;

int N;
vector<int> children[max_n];
int skill[max_n];

int dp[max_n][2];

int dfs(int node, bool isSelected=false) {
    int &ref = dp[node][isSelected];
    if(ref != -1) 
        return ref;

    //현재노드가 선택되지 않는 경우
    int non_selected_result=0;
    for(auto child : children[node])
        non_selected_result += dfs(child, false);    

    int selected_result = 0;
    //현재노드가 멘토링을 형성하는 경우
    if(!isSelected) {
        for(auto partner : children[node]) {
            int synergy = skill[partner] * skill[node];
            int temp = synergy+(non_selected_result-dp[partner][0])+dfs(partner, true);
            selected_result = max(selected_result, temp);
        }
    }

    return ref = max(selected_result, non_selected_result);
}


void input() {
    cin >> N;
    for(int i=2; i<=N; i++) {
        int parent;
        cin >> parent;
        children[parent].push_back(i);
    }

    for(int i=1; i<=N; i++) 
        cin >> skill[i];
}

void solution() {
    input();

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, false) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
