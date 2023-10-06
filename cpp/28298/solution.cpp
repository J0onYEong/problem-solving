#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define cip pair<char, int>

using namespace std;

//알파벳 97-122 : 26개

const int max_n = 500+1;

int N, M, K;

char init_map[max_n][max_n];

map<char, int> char_cnt[max_n][max_n];

char sample_map[max_n][max_n];

bool cmp(const cip& a, const cip& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

void input() {
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++) {
        string temp;
        cin >> temp;
        for(int j=0; j<M; j++)
            init_map[i][j+1] = temp[j];
    }
}

void solution() {
    input();

    for(int i=1; i<=N; i+=K) 
        for(int j=1; j<=M; j+=K) {
            for(int k1=0; k1<K; k1++) {
                for(int k2=0; k2<K; k2++) {
                    int x = i+k1;
                    int y = j+k2;
                    char tile = init_map[x][y];
                    char_cnt[k1+1][k2+1][tile] += 1;
                }
            }
        }
    
    for(int k1=1; k1<=K; k1++) 
        for(int k2=1; k2<=K; k2++) {
            map<char, int> &m = char_cnt[k1][k2];
            vector<cip> v(m.begin(), m.end());
            sort(v.begin(), v.end(), cmp);
            sample_map[k1][k2] = v.front().first;
        }
    
    int retile_cnt = 0;
    
    for(int i=1; i<=N; i+=K) 
        for(int j=1; j<=M; j+=K)
            for(int k1=0; k1<K; k1++) 
                for(int k2=0; k2<K; k2++) {
                    int x = i+k1;
                    int y = j+k2;
                    if(sample_map[k1+1][k2+1] != init_map[x][y]) {
                        retile_cnt += 1;
                        init_map[x][y] = sample_map[k1+1][k2+1];
                    }
                }

    cout << retile_cnt << endl;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++)
            cout << init_map[i][j];
        cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
