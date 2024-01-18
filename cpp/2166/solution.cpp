#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
#define ld long double
#define Pos pair<long long, long long>

using namespace std;


int n;

vector<Pos> poses;

void input() {

    cin >> n;

    for(int i=0; i<n; i++) {

        long long x, y;

        cin >> x >> y;

        poses.push_back({x, y});
    }

}

void solution() {
    input();

    Pos stand = {poses[0].first, poses[0].second};

    ld result = 0;

    for(int i=1; i<n-1; i++) {

        Pos first_pos = poses[i];
        Pos second_pos = poses[i+1];

        ld temp = (first_pos.first - stand.first)*(second_pos.second - stand.second) - (first_pos.second - stand.second)*(second_pos.first- stand.first);

        temp /= 2.0;

        result += temp;
    }

    if(result < 0) result *= -1;

    cout.precision(1);

    printf("%.1Lf\n", result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
