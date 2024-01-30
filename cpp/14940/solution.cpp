#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"
#define Pos pair<short, short>

using namespace std;

const short max_input = 1000;

short n, m;

int dp[max_input][max_input];

short my_map[max_input][max_input];

short vertical_move[4] = {1,-1,0,0};
short horizontal_move[4] = {0,0,1,-1};

Pos start_point;

void input() {

    cin >> n >> m;

    for(int i=0; i<n; i++) {

        for(int j=0; j<m; j++) {

            cin >> my_map[i][j];

            if(my_map[i][j] == 2) {

                start_point.first = i;
                start_point.second = j;

            }

        }

    }

}

void solution() {
    input();

    for(int i=0; i<n; i++) {

        for(int j=0; j<m; j++) {

            dp[i][j] = -1;

        }

    }

    queue<Pos> q;

    q.push(start_point);

    dp[start_point.first][start_point.second] = 0;

    while(!q.empty()) {

        Pos current = q.front();
        int accum = dp[current.first][current.second];

        q.pop();

        int next_accum = accum+1;

        for(short i=0; i<4; i++) {

            int next_i = current.first + vertical_move[i];
            int next_j = current.second + horizontal_move[i];

            // 이동한 지점, 이동불가 지점
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= m || dp[next_i][next_j] != -1 || my_map[next_i][next_j] == 0) {

                continue;

            }

            dp[next_i][next_j] = next_accum;

            q.push({next_i, next_j});
        }

    }

    for(int i=0; i<n; i++) {

        for(int j=0; j<m; j++) {

            if(my_map[i][j] == 0) {

                cout << 0;

            } else {

                cout << dp[i][j];

            }

            if(j < m-1) 
                cout << " ";

        }

        cout << endl;

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
