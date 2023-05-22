#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int N;
int temp[16];
int cnt = 0;

/*
- 문제해석
    NxN의 체스판위에 N개의 퀸이 존재할 수 있는 방법은 
    각 행, 열에 하나의 퀸만이 존재할 수 있다는 것이 포인트
*/

void nQueen(int col) {
    if(col == N) {
        //N-1개의 Queen놓인 상태
        cnt++;
        return;
    }
    //row 0부터 N-1까지
    for(int i=0; i<N; i++) {
        temp[col] = i;

        bool check = true;
        //이전 column들의 Queen들과 비교
        for(int j=0; j<col; j++) {
            if(temp[j] == temp[col] || j-col == temp[j]-temp[col] || j-col == temp[col]-temp[j]) {
                check = false;
                break;
            }
        }

        if(check) 
            nQueen(col+1);
    }
}


void solution() {
    cin >> N;
    nQueen(0);
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
