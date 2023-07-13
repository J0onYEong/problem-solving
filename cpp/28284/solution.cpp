#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define range pair<int, int>
#define event pair<int, int>

using namespace std;
const int max_n = 500001;
const int max_coor = 1000001;

int N, M;

int A[max_n];
ll sum[max_n];


int com_map[max_coor];
vector<event> coordi;
vector<range> org;

void input() {
    cin >> N >> M;

    for(int i=1; i<=N; i++)
        cin >> A[i];

    for(int i=1; i<=M; i++) {
        int s, e;
        cin >> s >> e;
        coordi.push_back({s, 1});
        coordi.push_back({e+1, -1});
        org.push_back({s, e});
    }
}

void solution() {
    input();
    //오름차순 정렬 & 누적합
    sort(A+1, A+(N+1));
    memset(sum, 0, sizeof(sum));
    for(int i=1; i<=N; i++)
        sum[i] = sum[i-1] + A[i];

    sort(coordi.begin(), coordi.end(), [](const event& l, const event& r){return l.first==r.first?l.second>r.second:l.first<r.first;});

    ll min_result = 0;
    ll max_result = 0;
    ll min_temp = 0;
    ll max_temp = 0;
    int last_number = 0;

    int temp = 0;
    for(int i=0; i<=coordi.size(); i++) {
        if(i == coordi.size()) {
            min_result += min_temp;
            max_result += max_temp;
            break;
        }
        int now_number = coordi[i].first;

        int num_of_dates = (now_number-1)-last_number+1;

        min_result += min_temp * num_of_dates;
        max_result += max_temp * num_of_dates;

        temp += coordi[i].second;

        min_temp = sum[temp];
        max_temp = sum[N]-sum[N-temp];

        last_number = coordi[i].first;
    }

    cout << min_result << " " << max_result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
