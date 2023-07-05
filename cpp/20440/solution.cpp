#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    unordered_map<int, int> m;

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        m[a]++;
        m[b]--;
    }

    vector<pair<int, int> > v;
    v.assign(m.begin(), m.end());

    sort(v.begin(), v.end());

    int temp = 0;
    int result = 0;

    int temp_s = 1;
    int temp_e = 1;

    bool change_trigger = false;

    for(auto e : v) {
        temp += e.second;
        if(result < temp) {
            result = temp;
            temp_s = e.first;
            change_trigger = true;
        } else if(result > temp) {
            if(change_trigger) {
                change_trigger = false;
                temp_e = e.first;
            }
        }
    }

    cout << result << endl;
    cout << temp_s << " " << temp_e << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
