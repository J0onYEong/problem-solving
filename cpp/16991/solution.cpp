#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 16+1;
const int full_bit = 65535; //2^16-1
const int max_v = 1000000000;

int N;

int all_visit_state;

pair<int, int> pos[max_n];

double dis[max_n][max_n];

//특정 상태에서 특정노드에 도착, '남은'노드를 도는 데 필요한 최적 비용
double dp[max_n][full_bit+1];

double recursive(int now, int state) {
    double &ret = dp[now][state];
    if(ret != max_v)
        return ret;
    
    if((state & all_visit_state) == all_visit_state) {
        ret = dis[now][1];
        return ret;
    }
    
    for(int i=0; i<N; i++) {
        int next = i+1;
        int bit_pos = 1 << i;
        int next_state = state | bit_pos;

        if(next == now || next_state == state)
            continue;

        ret = min(ret, dis[now][next]+recursive(next, next_state));
    }
    return ret;
}

void input() {
    cin >> N;
    for(int i=1; i<=N; i++) 
        cin >> pos[i].first >> pos[i].second;
}

void solution() {
    input();

    //전처리
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            double cx = pow(pos[i].first-pos[j].first, 2);
            double cy = pow(pos[i].second-pos[j].second, 2);
            dis[i][j] = dis[j][i] = sqrt(cx+cy);
        }

    for(int i=1; i<=N; i++) 
        for(int j=0; j<=full_bit; j++) 
            dp[i][j] = max_v;
    
    all_visit_state = pow(2, N) - 1;
    
    double result = max_v;
    
    cout.precision(9);
    cout << recursive(1, 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
