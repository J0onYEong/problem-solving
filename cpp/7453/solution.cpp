#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int N;

vector<int> arr[4];

void input() {

    cin >> N;

    for(int i=0; i<N; i++) {

        for(int j=0; j<4; j++) {

            int temp;

            cin >> temp;

            arr[j].push_back(temp);
        }
    }
}

void solution() {
    input();

    vector<int> AB, CD;

    for(int i=0; i<N; i++) {

        for(int j=0; j<N; j++) {

            AB.push_back(arr[0][i] + arr[1][j]);
            CD.push_back(arr[2][i] + arr[3][j]);
        }
    }

    sort(CD.begin(), CD.end());

    ll result = 0;

    for(int i=0; i<N*N; i++) {

        int target = -AB[i];

        auto l = lower_bound(CD.begin(), CD.end(), target);
        auto u = upper_bound(CD.begin(), CD.end(), target);

        result += (u-l);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
