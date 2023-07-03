#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define con pair<int, int>

using namespace std;

void solution() {
    int N, K;
    string num_str;
    cin >> N >> K >> num_str;

    deque<int> dq;

    int k = K;

    for(int i=0; i<N; i++) {
        int now = num_str[i]-48;
        while(!dq.empty() && k > 0 && dq.back() < now) {
            dq.pop_back();
            k--;
        }
        dq.push_back(now);
    }

    for(int i=0; i<N-K; i++)
        cout << dq[i];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
