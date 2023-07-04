#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX = 17;
const int NOT = -1;
const int row = 0;
const int col = 1;
const int dia = 2;

int N;
int matrix[MAX][MAX];

int dp[MAX][MAX][3];

int numer_of_ways(int x, int y, int way);

int move_row(int x, int y) {
    int temp_x = x;
    int temp_y = y+1;
    if(temp_x < 1 || temp_x > N || temp_y < 1 || temp_y > N || matrix[temp_x][temp_y])
        return 0;
    return numer_of_ways(temp_x, temp_y, row);
}

int move_col(int x, int y) {
    int temp_x = x+1;
    int temp_y = y;
    if(temp_x < 1 || temp_x > N || temp_y < 1 || temp_y > N || matrix[temp_x][temp_y])
        return 0;
    return numer_of_ways(temp_x, temp_y, col);
}

int move_dia(int x, int y) {
    int A[] = {0, 1, 1};
    int B[] = {1, 0, 1};
    for(int i=0; i<3; i++) {
        int temp_x = x+A[i];
        int temp_y = y+B[i];
        if(temp_x < 1 || temp_x > N || temp_y < 1 || temp_y > N || matrix[temp_x][temp_y])
            return 0;
    }
    return numer_of_ways(x+1, y+1, dia);
}



int numer_of_ways(int x, int y, int way) {
    if(x == N && y == N)
        return 1;

    if(dp[x][y][way] != NOT)
        return dp[x][y][way];
    
    int result = 0;
    if(way == row)
        result += ( move_row(x, y)+move_dia(x, y) );
    else if(way == col)
        result += ( move_col(x, y)+move_dia(x, y) );
    else 
        result += ( move_col(x, y)+move_row(x, y)+move_dia(x, y) );

    return dp[x][y][way] = result;
}


void solution() {
    cin >> N;
    for(int i=1; i<=N; i++) 
        for(int j=1; j<=N; j++)
            cin >> matrix[i][j];
    
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            memset(dp[i][j], NOT, sizeof(int)*3);
    
    cout << numer_of_ways(1, 2, row) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
