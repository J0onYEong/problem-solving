#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX = 500;

int N, M, K;

string matrix[MAX];


int check(int x, int y) {
    int result = 0;
    for(int i=0; i<N; i+=K) {
        for(int j=0; j<M; j+=K) {

            for(int tx=0; tx<K; tx++) {
                for(int ty=0; ty<K; ty++) {

                    if(matrix[i+tx][j+ty] != matrix[x+tx][y+ty]) {
                        result++;
                    }

                }
            }

        }
    }

    return result;
}

void draw(int x, int y) {
    for(int i=0; i<N; i+=K) {
        for(int j=0; j<M; j+=K) {

            for(int tx=0; tx<K; tx++) {
                for(int ty=0; ty<K; ty++) {

                    matrix[i+tx][j+ty] = matrix[x+tx][y+ty];

                }
            }

        }
    }   
}

void solution() {
    cin >> N >> M >> K;

    for(int i=0; i<N; i++) 
        cin >> matrix[i];
    

    int result_value = 2501;
    int result_x, result_y;

    for(int i=0; i<N; i+=K) {
        for(int j=0; j<M; j+=K) {
            int temp_result = check(i, j);
            if(result_value > temp_result) {
                result_value = temp_result;
                result_x = i;
                result_y = j;
            } 
        }
    }

    draw(result_x, result_y);

    cout << result_value << endl;
    for(int i=0; i<N; i++)
        cout << matrix[i] << endl;;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
