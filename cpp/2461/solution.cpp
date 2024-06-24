#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;

vector<vector<int>> students;

void input() {

    cin >> N >> M;

    students = vector<vector<int>>(N, vector<int>(M));

    for(int cid=0; cid<N; cid++) {

        for(int i=0; i<M; i++) {

            int power;
            cin >> power;

            students[cid][i] = power;
        }
    }
}

void solution() {
    input();

    // value, {cid, index}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    int max_value = -1;

    for(int cid=0; cid<N; cid++) {
        
        sort(students[cid].begin(), students[cid].end());

        int min_value = students[cid][0];

        max_value = max(max_value, min_value);

        pq.push({min_value, {cid, 0}});
    }

    // pq.top - 최솟값 + 반번호

    int min_diff = 1000000000;
    
    while(true) {
        
        int min_value = pq.top().first;
        int min_class_cid = pq.top().second.first;
        int min_class_index = pq.top().second.second;

        pq.pop();

        min_diff = min(min_diff, max_value-min_value);

        if(min_class_index < M-1) {

            min_class_index += 1;
            
            int new_value = students[min_class_cid][min_class_index];

            pq.push({new_value, { min_class_cid, min_class_index }});

            max_value = max(max_value, new_value);
        } else {

            break;
        }
    }

    cout << min_diff << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
