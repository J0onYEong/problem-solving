#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int n, m; 
int matrix[1000][1000];
int memo[1000][1000][3];
int d_y[3] = {-1, 0, 1};

int recursive(int x, int y, int last_d) {
    if(memo[x][y][last_d]) return memo[x][y][last_d];

    int temp = 101000;
    for(int i=0; i<3; i++) {
        if(i == last_d) continue;
        int next_x = x+1;
        int next_y = y+d_y[i];
        if(next_y < 0 || next_y >= m) continue;
        else if(next_x >= n) {
            temp = 0;
            continue;
        }
        temp = min(temp, recursive(next_x, next_y, i));
    }
    memo[x][y][last_d] = matrix[x][y] + temp;
    return memo[x][y][last_d];
}


void solution() {
    cin >> n >> m;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin >> matrix[i][j];
    
    for(int i=0; i<1000; i++)
        memset(memo[i], 0, sizeof(int)*1000);

    int result = 101000;
    for(int i=0; i<m; i++)
        result = min(result, recursive(0, i, -1));

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
