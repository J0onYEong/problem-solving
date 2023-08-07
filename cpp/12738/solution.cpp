#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 1000000;

int N;

int A[max_n];

void input() {
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
}

void find_place(vector<int>& v, int value) {
    if(v.empty()) {
        v.push_back(value);
        return;
    }

    if(v.back() < value) {
        v.push_back(value);
        return;
    }

    int index = lower_bound(v.begin(), v.end(), value) - v.begin();
    v[index] = value;
    return;
}

void solution() {
    input();

    vector<int> result;

    for(int i=0; i<N; i++)
        find_place(result, A[i]);

    cout << result.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
