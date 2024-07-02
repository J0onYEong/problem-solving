#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define ll long long
#define endl "\n"

using namespace std;

int N, M, K;

int matrix[1000][1000];

bool visited[1000][1000][11];

void input() {

    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {

        string row;
        cin >> row;

        for(int j=0; j<M; j++) {

            matrix[i][j] = row[j]-48;
        }
    }
}

struct Move {

    int x, y, k, move_cnt;
};

void solution() {
    input();

    if(N==1 && M==1) {

        cout << 1 << endl;
        return;
    }

    queue<Move> q;

    q.push({0,0,K,1});

    visited[0][0][K] = true;

    int A[4] = {1,-1,0,0};
    int B[4] = {0,0,1,-1};

    while(!q.empty()) {
        
        Move current = q.front();
        q.pop();

        for(int i=0; i<4; i++) {

            int nx = current.x + A[i];
            int ny = current.y + B[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            int nk = current.k;

            if(matrix[nx][ny]) {
                
                if(current.k > 0) {
                    // 이동하려는 곳이 벽이고 이동가능한 경우
                    nk-=1;

                } else {
                    continue;
                }
            }

            if(!visited[nx][ny][nk]) {
                // 첫방문인 경우
                visited[nx][ny][nk] = true;

                int nm = current.move_cnt + 1;

                if(nx == N-1 && ny == M-1) {

                    cout << nm << endl;
                    return;
                }

                q.push({nx, ny, nk, nm});
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
