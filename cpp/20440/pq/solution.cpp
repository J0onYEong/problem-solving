#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pi pair<int, int>

using namespace std;



struct compare {
    bool operator()(pi &l, pi &r) {
       return l.second > r.second;
    }
};

void solution() {
    int N;
    cin >> N;

    priority_queue<pi, vector<pi>, compare> schedule;
    priority_queue<pi, vector<pi>, compare> pq;

    unordered_map<int, pi> m;

    for(int i=0; i<N; i++) {
        pi temp;
        cin >> temp.first >> temp.second;
        schedule.push(temp);
    }


    pq.push(schedule.top());
    schedule.pop();

    int size = 1;
    int st = pq.top().first;
    int ed = pq.top().second;

    while(!schedule.empty()) {
        pi s = schedule.top();
        schedule.pop();
        pi pq_t = pq.top();

        if(pq_t.second <= s.first)
            pq.pop();

        pq.push(s);
    }

    cout << pq.size() << endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
