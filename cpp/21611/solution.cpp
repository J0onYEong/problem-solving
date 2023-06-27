#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX_N = 50;
const int MAX_M = 101;

int N, M;
int matrix[MAX_N][MAX_N];

int d[MAX_M];
int s[MAX_M];

int A[] = {0, -1, 1, 0, 0};
int B[] = {0, 0, 0, -1, 1};

map<int, int> result;

// 앞으로 한칸씩 이동 움직임이 없으면 false, 있으면 true
bool move_forward() {
    bool check = false;

    int A[] = {1,0,-1,0};
    int B[] = {0,1,0,-1};

    int turn = 1;
    int dis = 1;
    int dir = 0;

    int temp_x = (N+1)/2;
    int temp_y = (N+1)/2-1;

    bool trigger = true;

    while(trigger) {
        for(int i=1; i<=dis; i++) {
            int next_x = temp_x + A[dir];
            int next_y = temp_y + B[dir];

            if(next_x < 0 || next_y < 0 || next_x > N || next_y > N) {
                trigger = false;
                break;
            }



            if(matrix[temp_x][temp_y] == 0) {
                if(matrix[next_x][next_y] != 0)
                    check = true;
                matrix[temp_x][temp_y] = matrix[next_x][next_y];
                matrix[next_x][next_y] = 0;
            }

            temp_x = next_x;
            temp_y = next_y;
        }

        turn += 1;
        dir = (dir+1) % 4;

        if(turn == 2) {
            turn = 0;
            dis+=1;
        }
    }
    return check;
}

bool boom() {
    bool check = false;

    int A[] = {1,0,-1,0};
    int B[] = {0,1,0,-1};

    int turn = 1;
    int dis = 1;
    int dir = 0;

    int temp_x = (N+1)/2;
    int temp_y = (N+1)/2-1;

    int con_count = 1;

    vector<pair<int, int> > con_pos;

    con_pos.push_back(make_pair(temp_x, temp_y));

    bool trigger = true;

    while(trigger) {
        for(int i=1; i<=dis; i++) {
            
            int next_x = temp_x + A[dir];
            int next_y = temp_y + B[dir];

            if(next_x < 0 || next_y < 0 || next_x > N || next_y > N) {
                trigger = false;
                break;
            }

            if(matrix[next_x][next_y] == matrix[temp_x][temp_y]) {
                if(matrix[temp_x][temp_y] != 0) {
                    con_count+=1;
                    con_pos.push_back(make_pair(next_x, next_y));
                }
            }
            else {
                if(con_count >= 4) {
                    check = true;

                    result[matrix[temp_x][temp_y]] += con_pos.size();

                    for(auto e : con_pos)
                        matrix[e.first][e.second] = 0;
                }
                con_count=1;
                con_pos.clear();
                con_pos.push_back(make_pair(next_x, next_y));
            }
            
            

            temp_x = next_x;
            temp_y = next_y;
        }

        turn += 1;
        dir = (dir+1) % 4;

        if(turn == 2) {
            turn = 0;
            dis+=1;
        }
    }
    return check;

}


void grouping() {
    bool check = false;

    int A[] = {1,0,-1,0};
    int B[] = {0,1,0,-1};

    int turn = 1;
    int dis = 1;
    int dir = 0;

    int temp_x = (N+1)/2;
    int temp_y = (N+1)/2-1;

    vector<pair<int, int> > con_pos;

    queue<int> element;

    con_pos.push_back(make_pair(temp_x, temp_y));

    bool trigger = true;

    while(trigger) {
        for(int i=1; i<=dis; i++) {
            
            int next_x = temp_x + A[dir];
            int next_y = temp_y + B[dir];

            if(next_x < 0 || next_y < 0 || next_x > N || next_y > N) {
                trigger = false;
                break;
            }

            if(matrix[next_x][next_y] == matrix[temp_x][temp_y]) {
                if(matrix[temp_x][temp_y] != 0)
                    con_pos.push_back(make_pair(next_x, next_y));
            }
            else {
                element.push(con_pos.size());
                element.push(matrix[temp_x][temp_y]);

                con_pos.clear();
                con_pos.push_back(make_pair(next_x, next_y));
            }
        

            temp_x = next_x;
            temp_y = next_y;
        }

        turn += 1;
        dir = (dir+1) % 4;

        if(turn == 2) {
            turn = 0;
            dis+=1;
        }
    }
    turn = 1;
    dis = 1;
    dir = 0;

    temp_x = (N+1)/2;
    temp_y = (N+1)/2-1;

    con_pos.push_back(make_pair(temp_x, temp_y));

    trigger = true;
    int temp_m[MAX_N][MAX_N];

    for(int i=1; i<=N; i++)
        memset(temp_m[i], 0, sizeof(int)*(N+1));

    while(trigger) {
        for(int i=1; i<=dis; i++) {
            
            int next_x = temp_x + A[dir];
            int next_y = temp_y + B[dir];

            if(next_x < 0 || next_y < 0 || next_x > N || next_y > N) {
                trigger = false;
                break;
            }

            if(!element.empty()) {
                temp_m[temp_x][temp_y] = element.front();
                element.pop();
            } else {
                trigger = false;
                break;
            }

            temp_x = next_x;
            temp_y = next_y;
        }

        turn += 1;
        dir = (dir+1) % 4;

        if(turn == 2) {
            turn = 0;
            dis+=1;
        }
    }

    for(int i=1; i<=N; i++) 
        for(int j=1; j<=N; j++)
            matrix[i][j] = temp_m[i][j];
}


void solution() {
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> matrix[i][j];
    
    int middle = (N+1)/2;
    
    for(int i=0; i<M; i++) {
        int d, s;
        cin >> d >> s;

        // 블라스트
        for(int dis=1; dis<=s; dis++) {
            int temp_x = middle+A[d]*dis;
            int temp_y = middle+B[d]*dis; 
            matrix[temp_x][temp_y] = 0;
        }

        // 당기기
        bool check1 = true;
        while(check1) {
            while(true) {
                // 움직임이 없을 때가지 반복
                if(!move_forward()) 
                    break;
            }

            check1 = false;
            while(true) {
                // 폭발이 없을 때까지 반복
                if(!boom()) 
                    break;
                check1 = true;
            }
        }

        //그룹화
        grouping();
    }

    cout << (result[1] + 2*result[2] + 3*result[3]) << endl;
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
