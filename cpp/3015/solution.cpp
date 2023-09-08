#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 500000+1;

int N;

int heightsOfPeople[MAX_N];

void input() {
    cin >> N;
    for(int i=1; i<=N ;i++)
        cin >> heightsOfPeople[i];
}

void solution() {
    input();

    ll result = 0;
    stack<pair<int, int>> heights;

    for(int i=1; i<=N; i++) {

        int checkingHeight = heightsOfPeople[i];

        if(heights.empty()) {
            heights.push({checkingHeight, 1});
            continue;
        }

        int cntOfSameHeight = 1;

        //#.1
        while(!heights.empty() && heights.top().first <= checkingHeight) {
            if(heights.top().first == checkingHeight)
                cntOfSameHeight+=heights.top().second;
            result += heights.top().second;
            heights.pop();
        }

        //#.2
        if(!heights.empty())
            result += 1;
        
        heights.push({checkingHeight, cntOfSameHeight});
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
