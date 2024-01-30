#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"
#define Pos pair<int, int> // pos, time

using namespace std;

const int max_n = 100001;

int n, k;

int isVisited[max_n];

void input() {

    cin >> n >> k;
}

void solution() {
    input();

    for(int i=0; i<max_n; i++){
        isVisited[i] = -1;
    }

    queue<Pos> q;

    q.push({n, 0});
    
    isVisited[n] = 0;

    int A[2] = {1, -1};

    while(!q.empty()) {
        int current_pos = q.front().first;
        int accumTime = q.front().second;

        q.pop();

        // 순간이동 확인
        for(int i=current_pos*2; i < max_n; i*=2) {

            if(isVisited[i] == -1) {

                isVisited[i] = accumTime;

                q.push({i, accumTime});

            } else {
                break;
            }
            
        }

        // 일반 이동
        for(int i=0; i<2; i++) {

            int next_pos = current_pos + A[i];
            
            if(0 <= next_pos && next_pos < max_n && isVisited[next_pos] == -1) {
                
                int next_accum = accumTime+1;

                isVisited[next_pos] = next_accum;

                q.push({next_pos, next_accum});

                for(int j = next_pos*2; j<max_n; j*=2) {
                    
                    if(isVisited[j] == -1) {
                        
                        isVisited[j] = next_accum;

                        q.push({j, next_accum});
                    } else {
                        break;
                    }
                }
            }
        }    
    }

    cout << isVisited[k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
