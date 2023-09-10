#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 100000+1;

int n;
int d;

vector<pair<int ,int>> rangeOfCommute;

void input() {
    cin >> n;

    for(int i=1; i<=n; i++) {
        int start, end;
        cin >> start >> end;

        int s = min(start, end);
        int e = max(start, end);

        rangeOfCommute.push_back({s, e});
    }

    cin >> d;
}

bool cmp(pair<int, int> &lhs, pair<int, int> &rhs) {
    if(lhs.second != rhs.second)
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}

void solution() {
    input();

    sort(rangeOfCommute.begin(), rangeOfCommute.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;

    int result = 0;

    for(auto commute : rangeOfCommute) {
        int start = commute.first;
        int end = commute.second;

        int boundStart = end - d;

        while(!pq.empty() && pq.top() < boundStart) {
            pq.pop();
        }

        if(start >= boundStart)
            pq.push(start);
        
        result = max(result, (int)pq.size());
    }   

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
