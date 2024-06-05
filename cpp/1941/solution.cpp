#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

vector<string> matrix;
bool tempMatrix[5][5];

void input() {

    matrix = vector<string>(5, "");

    for(int i=0; i<5; i++) {

        cin >> matrix[i];
    }
}

pair<int, int> indexToPos(int index) {

    int line = index / 5;
    int row = index % 5;

    return {line, row};
}

bool validation() {

    vector<vector<bool>> isVisted;

    int A[4] = {1, -1, 0, 0};
    int B[4] = {0, 0, 1, -1};

    for(int i=0; i<25; i++) {
        
        auto pos = indexToPos(i);

        if(tempMatrix[pos.first][pos.second]) {

            isVisted = vector<vector<bool>>(5, vector<bool>(5, false));

            int memberCount = 0;
            int dasomGroupCount = 0;

            queue<pair<int, int>> q;

            q.push(pos);
            isVisted[pos.first][pos.second] = true;

            while(!q.empty()) {
                int curX = q.front().first;
                int curY = q.front().second;

                memberCount++;

                if(matrix[curX][curY] == 'S') {

                    dasomGroupCount++;
                }

                q.pop();
                
                for(int k=0; k<4; k++) {
                    
                    int nextX = curX+A[k];
                    int nextY = curY+B[k];

                    if(nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5) { continue; }
                
                    if(tempMatrix[nextX][nextY] && !isVisted[nextX][nextY]) {

                        isVisted[nextX][nextY] = true;
                        q.push({nextX, nextY});
                    }
                }
            }

            return memberCount==7 && dasomGroupCount>=4;
        }
    }
}

int result = 0;

void recursive(int startIndex, int cnt) {

    if(cnt == 0) {

        if(validation()) {

            result++;
        }

        return;
    }

    for(int i=startIndex; i<25-(cnt-1); i++) {

        auto pos = indexToPos(i);

        tempMatrix[pos.first][pos.second] = true;
        recursive(i+1, cnt-1);
        tempMatrix[pos.first][pos.second] = false;
    }
}


void solution() {
    input();

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            tempMatrix[i][j] = false;

    recursive(0, 7);

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
