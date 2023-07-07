#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int n_max_coodinate = 20000;

int compressed_wall[n_max_coodinate];

void solution() {
    int n;
    cin >> n;
    vector<int> d_p;
    vector<pair<int, int> > o_p;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        d_p.push_back(a);
        d_p.push_back(b);
        o_p.push_back(make_pair(a, b));
    }
    memset(compressed_wall, 0, sizeof(int) * n_max_coodinate);

    sort(d_p.begin(), d_p.end());
    d_p.erase(unique(d_p.begin(), d_p.end()), d_p.end());
    
    int key = 1;
    for(auto e : o_p) {
        int st = e.first;
        int ed = e.second;
        int st_i = lower_bound(d_p.begin(), d_p.end(), st) - d_p.begin();
        int ed_i = lower_bound(d_p.begin(), d_p.end(), ed) - d_p.begin();

        for(int i=st_i; i<=ed_i; i++) 
            compressed_wall[i] = key;
        key++;
    }

    vector<int> result;
    for(int i=0; i<n_max_coodinate; i++)
        if(compressed_wall[i])
            result.push_back(compressed_wall[i]);
    
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    cout << result.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
