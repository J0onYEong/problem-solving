#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int FAIL = 10000;

int matrix[10][10];

void input() {
    for(int i=0; i<10; i++) {
        string temp;
        cin >> temp;
        for(int j=0; j<10; j++)
            matrix[i][j] = temp[j] == '#' ? 0 : 1; 
    }
}

int state[10];

int checkClickCount() {
    int tempMatrix[10][10];

    for(int i=0; i<10; i++)
        copy(begin(matrix[i]), end(matrix[i]), begin(tempMatrix[i]));

    int cnt = 0;

    int lastRowState[10];
    copy(begin(state), end(state), begin(lastRowState));

    int A[] = {1, -1, 0, 0};
    int B[] = {0, 0, 1, -1};

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(lastRowState[j] == 1) {
                cnt++;
                tempMatrix[i][j] = tempMatrix[i][j] == 0 ? 1 : 0;
                for(int k=0; k<4; k++) {
                    int tempX = i + A[k];
                    int tempY = j + B[k];

                    if(tempX < 0 || tempX > 9 || tempY < 0 || tempY > 9)   
                        continue;

                    tempMatrix[tempX][tempY] = tempMatrix[tempX][tempY] == 0 ? 1 : 0;
                }
            }
        }

        for(int j=0; j<10; j++)
            lastRowState[j] = tempMatrix[i][j] == 1 ? 1 : 0;
    }

    //마지막 검증
    for(int i=0; i<10; i++) 
        for(int j=0; j<10; j++) 
            if(tempMatrix[i][j] == 1)
                return FAIL;

    return cnt;
}


int recursive(int order) {
    if(order == 10)
        return checkClickCount();

    state[order] = 1;
    
    int tempResult = recursive(order+1);

    state[order] = 0;

    return min(tempResult, recursive(order+1));
}

void solution() {
    input();

    int result = recursive(0);
    if(result == FAIL) {
        cout << -1 << endl;
        return;
    } 

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
