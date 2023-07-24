#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pt pair<int, int> //pos, time

using namespace std;
const int max_dis = 500001;

int N, K;

bool visited[max_dis][2];

int brother_pos(int time) {
    return K + (time * (time+1))/2;
}

void input() {
    cin >> N >> K;
}

void solution() {
    input();

    memset(visited, 0, sizeof(visited));

    queue<pt> q;

    int result = -1;

    q.push({N, 0});
    visited[N][0] = true;

    while(!q.empty()) {
        int np = q.front().first;
        int t = q.front().second;
        q.pop();

        int bp = brother_pos(t);
        if(bp >= max_dis)
            break;

        if(visited[bp][t%2]) {
            result = t;
            break;
        }

        t++;
        
        if(np+1 < max_dis && !visited[np+1][t%2]) {
            visited[np+1][t%2]=true;
            q.push({np+1, t});
        }
        
        if(np-1 >= 0 && !visited[np-1][t%2]) {
            visited[np-1][t%2]=true;
            q.push({np-1, t});
        }
        
        if(np*2 < max_dis && !visited[np*2][t%2]) {
            visited[np*2][t%2]=true;
            q.push({np*2, t});
        }
    }

    cout << result << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
