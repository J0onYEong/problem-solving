#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#define ll long long
#define endl "\n"
#define Pos pair<int, int>

using namespace std;

int n, m;

char matrix[100][100];
int numOfMirror[100][100][4]; // direction, mirror

//    0
// 1     3
//    2
short A[4] = {-1, 0, 1, 0};
short B[4] = {0, -1, 0, 1};

vector<pair<int, int>> start_points;

void input() {
    cin >> m >> n;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) {
            matrix[i][j] = str[j];

            if(str[j] == 'C') {
                start_points.push_back({i, j});
            }
        }
    }
}

void solution() {
    input();

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                numOfMirror[i][j][k] = -1;
                numOfMirror[i][j][k] = -1;
            }
        }
    }

    queue<pair<Pos, pair<int, int>>> q; // 좌표, {방향, 거울수}

    int start_x = start_points.front().first;
    int start_y = start_points.front().second;
    
    q.push({start_points.front(), {-1, -1}});

    for(int k=0; k<4; k++)
        numOfMirror[start_x][start_y][k] = 0;

    while(!q.empty()) {
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        int currnet_d = q.front().second.first;
        int accum_m = q.front().second.second;

        q.pop();

        for(int direc=0; direc<4; direc++) {

            int temp_x = current_x;
            int temp_y = current_y;
            int temp_accum = accum_m;

            if(currnet_d != direc)
                temp_accum += 1;

            while(true) {

                temp_x += A[direc];
                temp_y += B[direc];

                if(temp_x < 0 || temp_x > n || temp_y < 0 || temp_y > m || matrix[temp_x][temp_y] == '*') {
                    break;
                }

                bool isSmallest = true;
                for(int k=0; k<4; k++) {

                    if(numOfMirror[temp_x][temp_y][k] != -1 && numOfMirror[temp_x][temp_y][k] < temp_accum) {
                        isSmallest = false;
                    }
                }

                if(!isSmallest)
                    break;

                if(numOfMirror[temp_x][temp_y][direc] == temp_accum)
                    break;

                numOfMirror[temp_x][temp_y][direc] = temp_accum;

                q.push({{temp_x, temp_y}, {direc, temp_accum}});
            }

        }

    }

    int min = 987654321;
    for(int k=0; k<4; k++) {
        int current = numOfMirror[start_points.back().first][start_points.back().second][k];

        if(current != -1 && min > current) {
            min = current;
        }
    }
    cout << min << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
