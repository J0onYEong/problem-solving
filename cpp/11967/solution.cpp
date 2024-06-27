#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;

vector<pair<int, int>> can_light_up[100][100];

bool can_reach[100][100];
bool isVisited[100][100];
bool isLightedUp[100][100];

void input() {

    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int x, y, a, b;

        cin >> x >> y >> a >> b;

        can_light_up[x-1][y-1].push_back({a-1, b-1});
    }
}

void solution() {
    input();

    queue<pair<int, int>> q;

    isVisited[0][0] = true;
    q.push({0, 0});
    isLightedUp[0][0] = true;

    int A[4] = {0,0,1,-1};
    int B[4] = {1,-1,0,0};

    while(!q.empty()) {

        int current_x = q.front().first;
        int current_y = q.front().second;

        q.pop();

        // 특정 위치의 스위치 키기
        for(auto light_up_pos : can_light_up[current_x][current_y]) {

            int x = light_up_pos.first;
            int y = light_up_pos.second;

            isLightedUp[x][y] = true;

            // 스위치를 켠 곳으로 이동가능한지 확인
            if(!isVisited[x][y] && can_reach[x][y]) {

                q.push({ x, y });
                isVisited[x][y] = true;
            }
        }

        for(int i=0; i<4; i++) {
            int next_x = current_x + A[i];
            int next_y = current_y + B[i];

            // 방문 가능성확인
            if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || isVisited[next_x][next_y])  
                continue;

            // 지금 이동가능한지 확인
            if(isLightedUp[next_x][next_y]) {
                
                q.push({ next_x, next_y });
                isVisited[next_x][next_y] = true;

            } else {

                // 추후 방문 마킹
                can_reach[next_x][next_y] = true;
            }
        }
    }

    int result = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(isLightedUp[i][j]) {

                result++;
            }
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
