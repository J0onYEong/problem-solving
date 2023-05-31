#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int getPosFromLevel(int mid, int lev) {
    int dis = (lev/2) + (lev%2);
    bool isOdd = lev % 2;
    return mid + dis * (isOdd ? 1 : -1);
}

void solution() {
    int N, K;
    vector<int> pool_pos;

    //0 - left_bound, 1 - right_bound
    int pool_data[100000][2];

    cin >> N >> K;
    for(int i = 0; i<N; i++) {
        int pos;
        cin >> pos;
        pool_pos.push_back(pos);
    }
    sort(pool_pos.begin(), pool_pos.end());
    for(int i=0; i<N; i++) {
        pool_data[i][0] = pool_pos[i];
        pool_data[i][1] = pool_pos[i];
    }
    
    ll result = 0;
    for(int level = 1; K > 0; level++) {
        for(int i=0; i < N; i++) {
            int middlePos = pool_pos[i];
            int now_pos = getPosFromLevel(middlePos, level);

            //오른쪽 이동
            if(level % 2 != 0) {
                //오른쪽 다음 노드의 왼쪽 바운더리가 현재 삽입하려는 위치보다 작거나 같으면 삽입불가
                if(i < N-1)
                    if(pool_data[i+1][0] <= now_pos)
                        continue;
                pool_data[i][1] = now_pos;
            } else {
                //왼쪽 이동
                if(i > 0) {
                    if(pool_data[i-1][1] >= now_pos)
                        continue;
                }
                pool_data[i][0] = now_pos;
            }
            result += abs(now_pos - middlePos);
            K--;
            if(K == 0)
                break;
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
