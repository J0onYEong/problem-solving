#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

int A[4] = {1,-1,0,0};
int B[4] = {0,0,1,-1};

vector<vector<pair<int, bool>>> matrix;

int n, m;

void input() {
    
    cin >> n >> m;

    matrix = vector<vector<pair<int, bool>>> (n, vector<pair<int, bool>> (m, {0, false}));

    for(int i=0; i<n; i++) {

        for(int j=0; j<m; j++) {

            int cell;

            cin >> matrix[i][j].first;
        }
    }

}

void solution() {
    input();

    queue<pair<int, int>> q;

    int result_count = 0;
    int max_area = 0;

    for(int i=0; i<n; i++) {

        for(int j=0; j<m; j++) {

            if(matrix[i][j].first == 0|| matrix[i][j].second) { continue; }

            q.push({i, j});

            matrix[i][j].second = true;

            int area = 0;

            while(!q.empty()) {

                int c_i = q.front().first;
                int c_j = q.front().second;

                area++;

                q.pop();

                for(int k=0; k<4; k++) {
                    
                    int n_i = c_i+A[k];
                    int n_j = c_j+B[k];

                    if(n_i < 0 || n_i >= n || n_j < 0 || n_j >= m) { continue; }
                    
                    if(matrix[n_i][n_j].first != 1 || matrix[n_i][n_j].second) { continue; }
                    
                    matrix[n_i][n_j].second = true;

                    q.push({n_i, n_j});
                }
            }

            result_count += 1;

            max_area = max(max_area, area);
        }
    }

    cout << result_count << "\n" << max_area << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
