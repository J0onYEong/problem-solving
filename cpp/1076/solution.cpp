#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    map<string, pair<ll, ll> > m;

    m["black"] = make_pair(0, 1);
    m["brown"] = make_pair(1, 10);
    m["red"] = make_pair(2, 100);
    m["orange"] = make_pair(3, 1000);
    m["yellow"] = make_pair(4, 10000);
    m["green"] = make_pair(5, 100000);
    m["blue"] = make_pair(6, 1000000);
    m["violet"] = make_pair(7, 10000000);
    m["grey"] = make_pair(8, 100000000);
    m["white"] = make_pair(9, 1000000000);

    string a, b, c;

    cin >> a >> b >> c;

    cout << (m[a].first*10 + m[b].first) * m[c].second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
