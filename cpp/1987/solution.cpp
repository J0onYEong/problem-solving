#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pos pair<int, int> //x, y

using namespace std;
int R, C;
char matrix[20][21];

//알파벳의 int값을 비트로 순서로 변환, Ex) A -> 000000..001
int charToBits(char apb) {
    int init = 1;
    int ascii = apb-97;
    return init <<= ascii;
}

void solution() {
    cin >> R >> C;
    for(int i=0; i<R; i++) 
        cin >> matrix[i];
    
    queue<pair<pos, int> > q;
    pos a = make_pair(0, 0);
    q.push(make_pair(a, charToBits(matrix[0][0])));

    int result = 1;

    int A[] = {1,-1,0,0};
    int B[] = {0,0,1,-1};
    while(!q.empty()) {
        int x, y, move, visit;
        x = q.front().first.first;
        y = q.front().first.second;
        visit = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int next_x = x+A[i];
            int next_y = y+B[i];
            //좌표내에 있는지 확인
            if(next_x>=0&&next_x<R&&next_y>=0&&next_y<C) {
                //알파벳을 지나왔는지 확인
                int nextApb = charToBits(matrix[next_x][next_y]);
                if((visit & nextApb) == 0) {
                    pos temp1 = make_pair(next_x, next_y);
                    q.push(make_pair(temp1, (visit | nextApb)));
                    result = (visit | nextApb);
                }
            }     
        }
    }
    int count = 0;
    for(int i=97; i<=122; i++) {
        int bit = charToBits(i);
        if((result & bit) != 0)
            count++;
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
