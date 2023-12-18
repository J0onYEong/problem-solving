#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_HEIGHT = 500;
const int NOT_DEFINED = -500;

int n;

short number_tree[MAX_HEIGHT][MAX_HEIGHT];
int dp[MAX_HEIGHT][MAX_HEIGHT];

void input() {

    cin >> n;

    for(int c=0; c<n; c++)
        for(int r=0; r<=c; r++)
            cin >> number_tree[c][r];
}

int recursive(int height, int row) {
    int &ret = dp[height][row];

    if(ret != NOT_DEFINED)
        return ret;

    if(height == n-1)
        return ret = number_tree[height][row];

    return ret = number_tree[height][row] + max(recursive(height+1, row), recursive(height+1, row+1));
}

void solution() {
    input();

    for(int i=0; i<MAX_HEIGHT; i++)
        for(int j=0; j<MAX_HEIGHT; j++)
            dp[i][j] = NOT_DEFINED;
    
    cout << recursive(0,0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
