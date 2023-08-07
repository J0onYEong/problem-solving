#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int d_x[4] = {0,-1,0,1};
    int d_y[4] = {1,0,-1,0};
    int temp_x = 0;
    int temp_y = 0;
    int length = 1;
    int number = 2;
    int count = 0;
    int direction = 0;
    int matrix[50][5];
    for(int i=0; i<50; i++)
        for(int j=0; j<5; j++)
            matrix[i][j] = 0;

    if(0 >= r1 && 0 <= r2 && 0 <= c2 && 0 >= c1)
        matrix[-r1][-c1] = 1;

    
    while(!matrix[0][0] || !matrix[0][c2-c1] || !matrix[r2-r1][0] || !matrix[r2-r1][c2-c1]) {
        if(count == 2) {
            count = 0;
            length++;   
        }
        for(int i=0; i<length; i++) {
            temp_x += d_x[direction];
            temp_y += d_y[direction];
            
            if(temp_x >= r1 && temp_x <= r2 && temp_y <= c2 && temp_y >= c1) {
                matrix[temp_x-r1][temp_y-c1] = number;
            }
            number++;
        }
        direction++;
        if(direction > 3)
            direction = 0;
        count++;
    }

    int max_v = -1;
    for(int i=0; i<=r2-r1; i++) 
        for(int j=0; j<=c2-c1; j++) {
            max_v = max(max_v, matrix[i][j]);
        }

    int place = 0;
    while(max_v != 0) {
        max_v /= 10;
        place++;
    }
    for(int i=0; i<=r2-r1; i++) {
        for(int j=0; j<=c2-c1; j++) {
            printf("%*d", place, matrix[i][j]);
            if(j != c2-c1)
                cout << " ";
        }
        if(i != r2-r1) 
            cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
