#include <bits/stdc++.h>

using namespace std;

// left - 0, middle - 1, right -2
int A[3] = {1,1,1};
int B[3] = {-1,0,1};
int N, M;

int recursvie(int **matrix, int n, int m, int lastDirec) { 
    // 도착
    if(n == N) 
        return 0;

    int minValue = 1000;
    for(int i=0; i<3; i++) {
        if(i == lastDirec) continue;

        int nextN = n + A[i];
        int nextM = m + B[i];
        if(nextM<0 || nextM >= M) continue; 

        minValue = min(minValue, recursvie(matrix, nextN, nextM, i));
    }
    return matrix[n][m]+minValue;
}


void solution() {
    cin >> N >> M;
    int** matrix = new int*[N];


    for(int i=0;i<N;i++) {
        matrix[i] = new int[M];
        for(int j=0;j<M;j++) 
            cin >>  matrix[i][j];
    }

    // 시작점 지정
    int minValue = 1000;
    for(int i=0; i<M; i++) 
        minValue = min(minValue, recursvie(matrix, 0, i, -1));
    cout << minValue << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}