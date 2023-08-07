#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int N, M, K;
int noteBook[40][40];
int cnt = 0;

/*
행렬의 회전 알고리즘
A = max(N, M)
90도 시계방향 회전: i, j => j, A-i-1
90도 반시계방향 회전:   
*/

void turnSticker(int &r, int &c, int sticker[10][10]) {
    int temp_arr[10][10];

    int a = max(r,c);
    if(c > r) 
        a-=(c-r);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) {
            temp_arr[j][a-i-1] = sticker[i][j];
        }


    int temp = r;
    r = c;
    c = temp;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            sticker[i][j] = temp_arr[i][j];

}

bool checkPossible(int r, int c, int sticker[10][10]) {
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            bool check = true;
            for(int e=0; e<r; e++) {
                for(int f=0; f<c; f++) {
                    if(i+e < N && j+f < M) {
                        if(noteBook[i+e][j+f]==1 && sticker[e][f]==1) {
                            check = false;
                            break;
                        }
                    } else {
                        check = false;
                        break;
                    }
                }
                if(!check)
                    break;
            }

            if(check) {
                for(int e=0; e<r; e++)
                    for(int f=0; f<c; f++) 
                        if(sticker[e][f]==1) {
                            noteBook[i+e][j+f] = sticker[e][f];
                            cnt++;
                        } 
                return true;
            }
        }
                        
    return false;
}


void solution() {
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++)
        memset(noteBook, 0, sizeof(int)*M);
    for(int input_index=0; input_index<K; input_index++) {
        int R, C;
        cin >> R >> C;
        int sticker[10][10];
        
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                cin >> sticker[i][j];

        int tempR = R;
        int tempC = C;
        for(int a=0; a<4; a++) {
            if(checkPossible(tempR, tempC, sticker))
                break;
            turnSticker(tempR, tempC, sticker);   
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
