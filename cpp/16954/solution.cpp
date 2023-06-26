#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

string matrix[8];

bool visited[8][8][15];

int A[] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
int B[] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

void move_wall() {
    string temp[8];
    for(int i=0; i<8; i++)
        temp[i] = matrix[i];
    
    for(int i=0; i <= 7; i++)
        matrix[i+1] = temp[i];
    
    matrix[0] = "........";
}

void solution() {
    for(int i=0; i<8; i++)
        cin >> matrix[i];

    queue<pair<int, pair<int, int> > > q, temp;

    q.push(make_pair(0, make_pair(7,0)));
    bool check = false;
    while(!q.empty()) {
        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()) {
            pair<int, pair<int, int> > d = temp.front();
            int x = d.second.first;
            int y = d.second.second;
            int t = d.first;
            temp.pop();

            if(x == 0 && y == 7) {
                check = true;
                break;
            }

            if(visited[x][y][t] || matrix[x][y] == '#')
                continue;
            
            visited[x][y][t] = true;

            for(int i=0; i<9; i++) {
                int temp_x = x+A[i];
                int temp_y = y+B[i];
                if(temp_x >= 0 && temp_x < 8 && temp_y >= 0 && temp_y < 8 && matrix[temp_x][temp_y] != '#') 
                    q.push(make_pair(t+1, make_pair(temp_x, temp_y)));
            }
        }

        if(check)
            break;

        //벽이동
        move_wall();
    }

    cout << (check ? '1' : '0') << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
