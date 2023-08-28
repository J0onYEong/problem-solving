#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 100000+1;

int N;
int col_height[max_n+1];

void input() {
    cin >> N;

    for(int i=1 ;i<=N; i++)
        cin >> col_height[i];
    
    col_height[N+1] = 0;
}

void solution() {
    input();

    stack<int> stk;
    stk.push(0);
    int result = 0;

    //Stack풀이 해석
    //Stack에는 기둥의 번호들이 삽입된다.
    //이 번호들은 항상 top에 저장된 번호들보다 작게 유지된다.
    //이렇게 유지하면 top과 일치하는 기둥의 높이를 직사각형의 높이로 하는 최대 직사각형 넓이가 상수시간으로 구할 수 있다.
    //스택에 top의 바로 아래에 있는 요소는 기동의 높이가 'top보다 처음으로 작아지는 기둥의 번호'를 담고있음으로
    //해당 기둥번호의 앞까지는 top에 저장된 기동번호의 높이가 직사각형의 높이가 될 수 있다.
    //( (i-1) - (stk.top()+1) + 1 ) 이 계산이 의미하는 것이 바로그 영역이다. i는 top바로 다음 번호를 의미한다.

    for(int i=1; i<=N+1; i++) {
        while(!stk.empty() && col_height[stk.top()] > col_height[i]) {
            int now = stk.top();
            stk.pop();
            result = max(result, col_height[now] * ((i-1) - (stk.top()+1) + 1));
        }
        stk.push(i);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
