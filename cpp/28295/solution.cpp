#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int order[10];

//처음 시작은 북쪽(N)부터 시작

//인덱스의 증가를 우회적으로 간주한다.
char direction[4] = {'N', 'E', 'S', 'W'};

void input() {
    for(int i=0; i<10; i++)
        cin >> order[i];
}

void solution() {
    input();

    int result_direc_index = 0;
    for(int i=0; i<10; i++) {
        int temp = order[i];
        if(temp==1)
            result_direc_index += 1;
        if(temp==2)
            result_direc_index += 2;
        if(temp==3) {
            result_direc_index -= 1;
            if(result_direc_index < 0)
                result_direc_index = 3;
        }
        result_direc_index %= 4;
    }

    cout << direction[result_direc_index] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
