#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 100000;

struct Meeting {
    unsigned int start, end;
    int people;
} meets[max_n];

int dp[max_n];

int N;

bool cmp(const Meeting &l, const Meeting &r) { 
    return (l.end != r.end) ? (l.end < r.end) : (l.start < r.start); 
}

bool cmp2(const Meeting &l, const Meeting &r) {
    return l.end < r.start;
}

void solution() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> meets[i].start >> meets[i].end >> meets[i].people;
    }
    memset(dp, 0, sizeof(int) * max_n);
    sort(meets, meets+N, cmp);
    
    dp[0] = meets[0].people;

    for(int i=1; i<N; i++) {
        int t = lower_bound(meets, meets+i, meets[i], cmp2) - meets;
        
        dp[i] = max(dp[i-1], (t > 0 ? dp[t-1] : 0) + meets[i].people);
    }
    cout << dp[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // solution();

    vector<pair<int, int> > a;

    a.push_back({1,2});

    cout << a.size();

    return 0;
}