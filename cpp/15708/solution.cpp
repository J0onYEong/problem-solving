#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int max_n = 100001;
int duration[max_n];

priority_queue<int> rocks_du;

int N, T, P;

void input() {
    cin >> N >> T >> P;
    for(int i=1; i<=N; i++)
        cin >> duration[i];
}

void solution() {
    input();

    int used_time = 0;
    int max_count = -1;
    int time_remaining = T + P;
    for(int rock=1; rock<=N; rock++) {
        time_remaining -= P;
        rocks_du.push(duration[rock]);
        time_remaining -= duration[rock];

        while(time_remaining < 0 && !rocks_du.empty()) {
            time_remaining += rocks_du.top();
            rocks_du.pop();
        }

        if(time_remaining < 0)
            break;
        
        max_count = max(max_count, int(rocks_du.size()));
    }
    cout << max_count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
