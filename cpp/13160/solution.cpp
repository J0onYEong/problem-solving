#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Range pair<int, int>

using namespace std;

const int max_cor = 600001;

int N;

int com_line[max_cor];

vector<Range> range;
vector<int> com_cor;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        range.push_back({s, e});
        com_cor.push_back(s);
        com_cor.push_back(e);
    }   
}

void solution() {
    input();
    sort(com_cor.begin(), com_cor.end());
    com_cor.erase(unique(com_cor.begin(), com_cor.end()), com_cor.end());

    memset(com_line, 0, sizeof(com_line));

    for(Range element : range) {
        int l = lower_bound(com_cor.begin(), com_cor.end(), element.first)-com_cor.begin();
        int r = lower_bound(com_cor.begin(), com_cor.end(), element.second)-com_cor.begin();
        com_line[l] += 1;
        com_line[r+1] -= 1;    
    }

    int result = 1;
    vector<int> nodes;
    int st = range[0].first;
    for(int i=1; i<max_cor; i++) {
        com_line[i] += com_line[i-1];
        if(result < com_line[i]) {
            result = com_line[i];
            st = com_cor[i];
        }
    }

    cout << result << endl;

    for(int i=0; i<range.size(); i++) {
        int node_number = i+1;
        int start = range[i].first;
        int end = range[i].second;
        if(start <= st && st <= end)
            cout << node_number << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
