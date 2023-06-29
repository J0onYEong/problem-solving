#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

vector<int> m;

bool visited[6];
int X;
int result = 1000000;

void recursive(int pos, int cum = 0) {
    if(pos == 0) {
        if(X < cum)
            result = min(result, cum);
    }

    int t = 1;
    for(int i=1; i<pos; i++)
        t *= 10;

    for(int i=0; i<m.size(); i++) {
        if(visited[i])
            continue;

        visited[i] = true;

        recursive(pos-1, cum+m[i]*t);

        visited[i] = false;
    }

}

void solution() {
    cin >> X;

    memset(visited, false, sizeof(bool)*6);

    int t = 1;
    int c = 0;
    while(X / t > 0) {
        m.push_back((X / t) % 10);

        t *= 10;

        c++;
    }

    recursive(c);

    if(result == 1000000) {
        cout << 0 << endl;
        return;
    }
    
    cout << result << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
