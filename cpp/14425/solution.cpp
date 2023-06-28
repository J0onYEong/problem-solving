#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;

void solution() {
    cin >> N >> M;

    map<string, int> s;
    int result = 0;

    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        s[temp] = 10001;
    }
    
    for(int i=0; i<M; i++) {
        string temp;

        cin >> temp;

        
        s[temp]++;
    }

    for(auto a : s) {
        int r = a.second - 10001;
        if(r > 0)
            result += r;
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
