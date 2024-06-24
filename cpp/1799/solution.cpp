#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int N;

int matrix[10][10];

void input() {

    cin >> N;

    for(int i=0; i<N; i++) {

        for(int j=0; j<N; j++) {

            cin >> matrix[i][j];
        }
    }
}


int dp[19][1000000];

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        std::cout << ((num >> i) & 1);
        if (i % 4 == 0) // 4비트마다 공백을 넣어 가독성 향상
            std::cout << " ";
    }
    std::cout << endl;
}

int recursive(int x, int y, int state) {

    // cout << x << " " << y << endl;

    int index = x + y;

    int &ret = dp[index][state];

    if(ret != -1) { return ret; }

    if(x == N-1 && x==y) {

        int cnt = 0;

        if(matrix[x][y] == 1) {

            int b_index = (y-x) + (N-1);

            int b_pos = 1 << b_index;

            if((state & b_pos) == 0) {

                state = state | b_pos;
            }
        }
        
        for(int i=0; i<2*N-1; i++) {

            int b_pos = 1 << i;

            if((state & b_pos) == b_pos) { cnt++; }
        }

        // printBinary(state);

        return ret = cnt;
    }

    int next_x = x;
    int next_y = y;

    int temp_result = 0;

    if(x < N-1) {
        next_x += 1;
    } else {
        next_y += 1;
    }

    int temp_x = x;
    int temp_y = y;

    while(temp_x >= 0 && temp_y < N) {

        if(matrix[temp_x][temp_y] == 1) { 

            int b_index = (temp_y-temp_x) + (N-1);

            int b_pos = 1 << b_index;

            if((state & b_pos)  == 0) {
            
                // 해당 자리가 빈 경우
                temp_result = max(temp_result, recursive(next_x, next_y, state | b_pos));
            } 
        }

        temp_x -= 1;
        temp_y += 1;       
    }

    // 현재 라인에서 선택 안함

    temp_result = max(temp_result, recursive(next_x, next_y, state));

    return ret = temp_result;
}

void solution() {
    input();

    for(int i=0; i< 2*N-1; i++) {
        
        for(int j=0; j<1000000; j++) {

            dp[i][j] = -1;
        }
    }

    cout << recursive(0, 0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
