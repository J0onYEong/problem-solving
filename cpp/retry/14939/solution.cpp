#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

const int Fail = 10000;

using namespace std;

int matrix[10][10];

int firstLineCase[10];

void input() {

    for(int i=0; i<10; i++) {

        char str[11];

        cin >> str;

        for(int j=0; j<10; j++) {

            matrix[i][j] = str[j] == '#' ? 0 : 1;
        }
    }
}

void flip(int &tile) {

    tile = tile == 0 ? 1 : 0;
}

int get_minimun_click() {

    int testMatrix[10][10];

    for(int i=0; i<10; i++) {

        copy(begin(matrix[i]), end(matrix[i]), begin(testMatrix[i]));
    }   
    
    int clk_cnt = 0;

    int A[4] = {1,-1,0,0};
    int B[4] = {0,0,1,-1};

    for(int i=0; i<10; i++) {

        for(int j=0; j<10; j++) {

            if(i == 0 && !firstLineCase[j]) { continue; }

            if(i != 0 && !testMatrix[i-1][j]) { continue; }

            flip(testMatrix[i][j]);

            clk_cnt+=1;

            for(int k=0; k<4; k++) {

                int near_x = i + A[k];
                int near_y = j + B[k];

                if(near_x < 0 || near_x >= 10 || near_y < 0 || near_y >= 10) { continue; }

                flip(testMatrix[near_x][near_y]);
            }
        }
    }

    for(int i=0; i<10; i++) {

        for(int j=0; j<10; j++) {

            if(testMatrix[i][j]) {

                return Fail;
            }
        }
    }

    return clk_cnt;
}

int find_combination(int order) {

    if(order == 10) {

        return get_minimun_click();
    }

    firstLineCase[order] = 1;

    int clicked_result = find_combination(order+1);

    firstLineCase[order] = 0;

    int unclicked_result = find_combination(order+1);

    return min(clicked_result, unclicked_result);
}

void solution() {
    input();

    int result = find_combination(0);

    if(result == Fail) {
        cout << -1 << endl;
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
