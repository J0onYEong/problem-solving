#include <iostream>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 200+1;
const int MAX_M = 20000+1;
const int INF = 20000000;
const int NOT_CONNECTED = -1;

/*
    이 문제을 해결법은 다음과 같다.

    특정 노드A, B가 있을 때
    Start노드에서 시작된 불꽃이 A, B로 진행될 때
    A - B사이에 모든 간선을 태우는데 거리는 시간을 계산해야 한다.

    결국 마지막까지 타고있는 간선이 탈경우 불이 꺼진다.

    즉, "Start로 부터시작해 노드-노드 사이 간선둘중 가장긴 간선이 타는데 걸리는 시간"들 중 최대값이 Start부터 시작한 불꽃이 그래프를 모두 태우는 시간이다.

    불꽃이 노드에 도달하는 시간은 최적으로 진행됨으로 

    프롤이드 워셜알고리즘을 사용하여 모든 노드들 사이의 최단경로를 배열(sDist)에 저장한다. 

    노드-노드 사이 거리의 최대값은 입력시에 비교를 통해 따로 배열(longestEdge)에 저장한다.

    - 그래서 어떻게 구하냐?

        두정점에 불이 붙는 시간차 = sDist[start][to] - sDist[start][from]
        (to가 from보다 불이 도달하는 시간이 더 걸림을 가정, 코드에는 시간차가 음수인 경우는 배제)

        to노드부터 가장긴 간선을 태우는데 걸리는 시간 = (가장긴 간선 길이 - 시간차) / 2
        시간차 동안 한쪽에 가장 긴 간선을 태우고 시간차 이후에는 to노드에도 불이 붙음으로 양쪽에서 간선을 태운다.
        따라서 시간은 절반이 된다.

        최종적으로, Start부터 가장 긴 간선을 태우는데 걸리는 시간 = sDist[start][to] + (가장긴 간선 길이 - 시간차) / 2

        모든 노드-노드에 대해 이 값을 도출하여 가장 큰 시간이 걸리는 값이 특정 start부터 모든 그래프를 연소하는데 걸리는 시간이된다.

        start를 1~n노드로 변경해 가며 최소값을 구하면 정답이된다.
*/

int n, m;

int sDist[MAX_N][MAX_N];
int longestEdge[MAX_N][MAX_N];

void input() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) {
            sDist[i][j] = sDist[j][i] = INF;
            longestEdge[i][j] = longestEdge[j][i] = NOT_CONNECTED;
            if(i == j)
                longestEdge[i][j] = longestEdge[j][i] = sDist[i][j] = sDist[j][i] = 0;
        }

    for(int i=1; i<=m; i++) {
        int s, e, l;
        cin >> s >> e >> l;

        int &short_ret = sDist[s][e];
        int &long_ret = longestEdge[s][e];

        if(short_ret == INF || short_ret > l) 
            sDist[s][e] = sDist[e][s] = l;
        if(long_ret == NOT_CONNECTED || long_ret < l)
            longestEdge[s][e] = longestEdge[e][s] = l;
    }
}

double caculateBurningTime(int start, int from, int to) {
    int le = longestEdge[from][to];

    //연결된 간선이 존재하는 경우
    if(le != NOT_CONNECTED) {
        
        int timeGap = sDist[start][to]-sDist[start][from];

        // timeGape이 0보다 작거나 같다는 것은 from에 도달했을 때 이미 to는 불타고 있고나 다탔다는 의미이다.
        // 이 경우는 스킵
        if(timeGap >= 0) {
            //특정점과 특정점을 이어주는 가장긴 간선이 있을 경우 
            //start를 기점에서 불이 붙었을 때 두 점에 도달하는 시간의 차이를 timeGap에 저장한다.
            if(timeGap < le) {
                double remain_edge = le - timeGap;
                return sDist[start][to] + remain_edge/2;
            }
            return sDist[start][to];
        }
    }
    return 0.0;
}

void solution() {
    input();

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                sDist[i][j] = sDist[j][i] = min(sDist[i][j], sDist[i][k]+sDist[k][j]);

    double shortestTime = INF;
    for(int start=1; start<=n; start++) {
        double longestTime = 0.0;
        for(int from=1; from<=n; from++) {
            for(int to=1; to<=n; to++) {
                double time = caculateBurningTime(start, from, to);
                longestTime = max(longestTime, time);
            }
        }
        shortestTime = min(shortestTime, longestTime);
    }

    cout << fixed;
    cout.precision(1);
    cout << shortestTime << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
