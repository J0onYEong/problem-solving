#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define ll long long
#define endl "\n"

using namespace std;

const int max_row = 12;
const int max_col = 6;

// '/0'을 위해 공간을 하나더 확보합니다.
char matrix[max_row][max_col+1];

void input() {
    
    for(int i=0; i<max_row; i++) {

        cin >> matrix[i];
    }
}

int A[4] = {1,-1,0,0};
int B[4] = {0,0,1,-1};

bool checkAndBoom() {

    vector<vector<bool>> isVisited = vector<vector<bool>>(max_row, vector<bool>(6, false));

    bool flag = false;

    for(int i=0; i<max_row; i++) {

        for(int j=0; j<max_col; j++) {
            
            if(matrix[i][j] != '.' && !isVisited[i][j]) {

                isVisited[i][j] = true;

                vector<pair<int ,int>> willBoom;

                queue<pair<int, int>> q;

                char currentColor = matrix[i][j];

                q.push({i, j});

                while(!q.empty()) {

                    int current_x = q.front().first;
                    int current_y = q.front().second;
                    q.pop();

                    willBoom.push_back({current_x, current_y});

                    for(int i=0; i<4; i++) {
                        
                        int next_x = current_x + A[i];
                        int next_y = current_y + B[i];

                        if(next_x < 0 || next_x >= max_row || next_y < 0 || next_y >= max_col) { continue; }

                        if(matrix[next_x][next_y] == currentColor && !isVisited[next_x][next_y]) {
                            
                            isVisited[next_x][next_y] = true;

                            q.push({next_x, next_y});
                        }
                    }   
                }

                if(willBoom.size() >= 4) {

                    for(auto target : willBoom) {

                        matrix[target.first][target.second] = '.';
                    }

                    flag = true;
                }

                willBoom.clear();
            }
        }
    }

    return flag;
}

void makeThemDown() {

    for(int i=max_row-2; i >= 0; i--) {

        for(int j=0; j<max_col; j++) {

            if(matrix[i][j] != '.' && matrix[i+1][j] == '.') {

                int current_row = i;

                while(current_row+1 < max_row && matrix[current_row+1][j] == '.') {
                    
                    current_row++;
                }

                matrix[current_row][j] = matrix[i][j];

                matrix[i][j] = '.';
            }
        }
    }
}

void printMatrix(string prevText) {

    cout << "\n" << prevText << "\n" << endl;

    for(int i=0; i<max_row; i++) {

        cout << matrix[i] << endl;
    }
}

void solution() {
    input();

    int result = 0;

    while(checkAndBoom()) {
        
        // printMatrix("폭파완료");

        result++;

        makeThemDown();

        // printMatrix("떨어트림 완료");
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
