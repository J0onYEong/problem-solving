#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int N, K;
    cin >> N >> K;

    queue<int> search;
    set<int> visit;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        search.push(temp);
        visit.insert(temp);
    }

    int horSearch[] = {-1, 1};
    ll result = 0;
    int depth = 1;
    while(!search.empty()) {
        int size = search.size();

        while(size--) {
            int temp = search.front();
            search.pop();

            for(int i=0; i<2; i++) {
                int ins = temp + horSearch[i];
                if(visit.count(ins) < 1) {
                    visit.insert(ins);
                    search.push(ins);
                    result += depth;
                    K--;
                    if(K == 0) {
                        cout << result << endl;
                        return;
                    }
                }
            }
        }
        depth++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
