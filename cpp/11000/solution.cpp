#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int N;
    cin >> N;

    priority_queue<pair<int, int> > pq1;
    priority_queue<pair<int, int> > pq2;
    
    vector<pair<int ,int> > cls;
    for(int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;
        pq1.push(make_pair(-start, -end));
    }

    int result = 1;
    while(!pq1.empty()) {
        if(pq2.empty()) {
            pq2.push(make_pair(pq1.top().second, pq1.top().first));
            pq1.pop();
        }
        int ls = -pq1.top().first;
        int le = -pq2.top().first;

        //두수업이 양립불가
        if(ls < le)
            result++;
        else
            pq2.pop();
        pq2.push(make_pair(pq1.top().second, pq1.top().first));
        pq1.pop();
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
