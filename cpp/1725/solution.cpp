#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 100000+1;

int N;
int col_height[max_n+1];

void input() {
    cin >> N;

    for(int i=1 ;i<=N; i++)
        cin >> col_height[i];
    
    col_height[N+1] = 0;
}

void solution() {
    input();

    stack<int> stk;
    stk.push(0);
    int result = 0;

    for(int i=1; i<=N+1; i++) {
        while(!stk.empty() && col_height[stk.top()] > col_height[i]) {
            int now = stk.top();
            stk.pop();
            result = max(result, col_height[now] * ((i-1) - (stk.top()+1) + 1));
        }
        stk.push(i);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
