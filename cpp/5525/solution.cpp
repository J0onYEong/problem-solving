#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define endl "\n"

using namespace std;

const int max_m = 1000000;

int dp[max_m];

int n, m;
string s;


void input() {

    cin >> n >> m >> s;

}

void solution() {
    input();

    int point = 0;
    bool isChecking = false;

    while(point < m) {

        // I찾기
        if(!isChecking) {

            if(s[point] == 'I') {

                isChecking = true;

                // 탐색 실행

            } else {

                point += 1;
                continue;

            }

        }

        // 탐색

        int next = point+1;
        int next_next = point+2;

        // 다음과 다음 다음이 범이내에 있는 경우 & 두 위치가 조건을 만족
        if(next < m && next_next < m && s[next] == 'O' && s[next_next] == 'I') {

            dp[next_next] = dp[point] + 1;

            point += 2;
             
        } else {

            isChecking = false;
            point += 1;

        }

    }

    int count = 0;

    for(int i=0; i<m; i++) {

        if(dp[i] >= n)
            count += 1;

    }

    cout << count << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
